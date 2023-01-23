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
int delayTime = 500;
int i = 3;
void loop() {
	doremi(i);
	i = i >= 10 ? 3 : i + 1;
}

void doremi(int octave) {
	ymz.SetFrequency(CH_A, CalcFreqByMML(octave, 'C'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(octave, 'C') - 1);
	delay(delayTime);
	ymz.SetFrequency(CH_A, CalcFreqByMML(octave, 'D'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(octave, 'D') - 1);
	delay(delayTime);
	ymz.SetFrequency(CH_A, CalcFreqByMML(octave, 'E'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(octave, 'E') - 1);
	delay(delayTime);
	ymz.SetFrequency(CH_A, CalcFreqByMML(octave, 'F'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(octave, 'F') - 1);
	delay(delayTime);
	ymz.SetFrequency(CH_A, CalcFreqByMML(octave, 'G'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(octave, 'G') - 1);
	delay(delayTime);
	ymz.SetFrequency(CH_A, CalcFreqByMML(octave, 'A'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(octave, 'A') - 1);
	delay(delayTime);
	ymz.SetFrequency(CH_A, CalcFreqByMML(octave, 'B'));
	ymz.SetFrequency(CH_B, CalcFreqByMML(octave, 'B') - 1);
	delay(delayTime);
	//ymz.SetFrequency(CH_A, CalcFreqByMML(octave + 1, 'C'));
	//ymz.SetFrequency(CH_B, CalcFreqByMML(octave + 1, 'C') - 1);
	//delay(delayTime);
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

