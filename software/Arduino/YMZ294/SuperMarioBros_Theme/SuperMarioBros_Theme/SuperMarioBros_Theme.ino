#include <YMZ294.h>

#define ADDR_FREQ_A CH_A
#define ADDR_FREQ_B CH_B
#define ADDR_FREQ_C CH_C

int convertTempoIntoBPM(int tenpo);

// Output Pins
const byte WRCS_PIN = 8;
const byte A0_PIN = 9;
const byte RESET_PIN = 10;
const int DELAY_TIME = convertTempoIntoBPM(100);

YMZ294 ymz(WRCS_PIN, A0_PIN, RESET_PIN);

void set_ch(Channel ch, int note) {

	if (ch == CH_A || ch == CH_B) {
		ymz.SetEnvShape(1, 0, 0, 1);
		ymz.SetEnvFrequency(30);
	}
	ymz.SetFrequency(ch, noteFreq[note]);
}

void user_delay(int time) {
	delay(time / 1.0);
}

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

void loop() {
	set_ch(ADDR_FREQ_A, 76);
	set_ch(ADDR_FREQ_B, 64);
	set_ch(ADDR_FREQ_C, 59);
	user_delay(51);
	set_ch(ADDR_FREQ_A, 0);
	set_ch(ADDR_FREQ_A, 71);
	user_delay(124);
	set_ch(ADDR_FREQ_A, 0);
	set_ch(ADDR_FREQ_A, 76);
	user_delay(124);
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

int convertTempoIntoBPM(int tenpo) {
	return 60000 / tenpo;
}