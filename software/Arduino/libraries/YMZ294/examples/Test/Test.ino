#include <YMZ294.h>

// Output Pins
const byte WRCS_PIN = 8;
const byte A0_PIN = 9;
const byte RESET_PIN = 10;

YMZ294 ymz(WRCS_PIN, A0_PIN, RESET_PIN);

void setup() {
	DDRD = 0b11111111;
	pinMode(WRCS_PIN, OUTPUT);
	pinMode(A0_PIN, OUTPUT);
	pinMode(RESET_PIN, OUTPUT);

	ymz.Reset();
	ymz.SetMixer(0b111, 0b100);
	ymz.SetVolume(CH_A, 0b00001111);
	ymz.SetFreqBit(CH_A, 0);
	ymz.SetVolume(CH_B, 0b00001111);
	ymz.SetFreqBit(CH_B, 0);

	pipo();

	delay(300);
}

word Duration = 2;
void loop() {
	Duration = (analogRead(0) >> 6);

	static word state = 0b000000000001;
	static bool lr = true;

	state += (lr ? 1 : -1);
	if (state == 0x03ff || state == 1)
		lr = !lr;
	ymz.SetFreqBit(CH_A, state);
	ymz.SetFreqBit(CH_B, state);

	delay(Duration);
}

void pipo() {
	ymz.SetFrequency(CH_A, CalcFreqByMML(8, 'C'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(8, 'C') - 1);
	delay(100);
	ymz.SetFrequency(CH_A, CalcFreqByMML(7, 'C'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(7, 'C') - 1);
	delay(100);
	ymz.SetFreqBit(CH_A, 0);
	ymz.SetFreqBit(CH_B, 0);
}
