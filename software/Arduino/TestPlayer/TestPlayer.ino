#include <SD.h>
#include <SPI.h>
#include <Audio.h>
#include <string>

int numList = 0;

void setup() {
	Serial.begin(9600);

	//SD�J�[�h������
	Serial.print("Initializing SD card...");
	if (!SD.begin(4)) {
		Serial.println(" failed!");
		while (true);
	}
	Serial.println(" done.");
}

void loop() {
	initPlayer();
	int count = 0;

START:
	//�I��
	Serial.println(F("Please input a music name : "));
	while (Serial.available() == 0);
	String musicName = Serial.readString();
	Serial.println(musicName);
	File myFile = SD.open(musicName);
	if (!myFile) {
		Serial.println(F("error opening"));
		goto START;
	}

	const int S = 1024; // Number of samples to read in block
	short buffer[S];

	Serial.print(F("Playing"));
	// until the file is not finished
	while (myFile.available()) {
		// read from the file into buffer
		myFile.read(buffer, sizeof(buffer));

		// Prepare samples
		int volume = 1024;
		Audio.prepare(buffer, S, volume);
		// Feed samples to audio
		Audio.write(buffer, S);

		// Every 100 block print a '.'
		count++;
		if (count == 100) {
			Serial.print(F("."));
			count = 0;
		}

		//�ȍĐ����̃R�}���h
		if (Serial.available() != 0)
		{
			if (Serial.read() == 's')
			{
				Serial.println(F("Stop playing"));
				break;
			}
			else if (Serial.read() == ' ')
			{
				Serial.println(F("Pause"));
				while (Serial.read() != ' ');
				Serial.println(F("Playing"));
			}
		}
	}
	myFile.close();
	Audio.end();
	Serial.println(F("End of file. Thank you for listening!"));
	delay(500);
}

void initPlayer() {
	//�I�[�f�B�I������
	//�T���v�����[�g88200bps, �o�b�t�@100ms
	Audio.begin(88200, 100);

	//�~���[�W�b�N���X�g�\��
	File root = SD.open("/");
	printDirectory(root);
	Serial.print(F("Number of the music : "));
	Serial.println(numList);
	root.close();
}

//�t�@�C�����ꗗ�\��
void printDirectory(File dir) {
	numList = 0;
	while (true) {
		File entry = dir.openNextFile();
		if (!entry) {
			// no more files
			break;
		}
		numList++;
		Serial.println(entry.name());
		entry.close();
	}
}