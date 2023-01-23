#include <YMZ294.h>

#define ADDR_FREQ_A CH_A
#define ADDR_FREQ_B CH_B
#define ADDR_FREQ_C CH_C

// Output Pins
const byte WRCS_PIN = 8;
const byte A0_PIN = 9;
const byte RESET_PIN = 10;

YMZ294 ymz(WRCS_PIN, A0_PIN, RESET_PIN);

void set_ch(Channel ch, int note) {
  ymz.SetFrequency(ch, noteFreq[note]);
}

void user_delay(int time) {
  delay(time / 1.4);
}

/*
void set_ch(Channel ch, int note) {
  int input_delay = map(analogRead(A2),0,1023,0,11);
  ymz.SetFrequency(ch, noteFreq[note-input_delay]);
}

void user_delay(int time) {
  //float input_delay = (float)map(analogRead(A2),0,1023,70,700)/100.0;
    delay(time / 1.2);
  //delay(time / input_delay);
}
*/

void setup() {
  DDRD = 0b11111111;
  pinMode(WRCS_PIN, OUTPUT);
  pinMode(A0_PIN, OUTPUT);
  pinMode(RESET_PIN, OUTPUT);

  ymz.Reset();

  ymz.SetMixer(0b111, 0b000);

  ymz.SetVolume(CH_A, 0b00001110);
  ymz.SetFreqBit(CH_A, 0);
  ymz.SetVolume(CH_B, 0b00001110);
  ymz.SetFreqBit(CH_B, 0);
  ymz.SetVolume(CH_C, 0b00001111);
  ymz.SetFreqBit(CH_C, 0);

  ymz.SetEnvEnable(CH_A, false);
  ymz.SetEnvEnable(CH_B, false);
  ymz.SetEnvEnable(CH_C, false);
}

void loop() {
  playSong();
}

void playStart() {
}

void playSong() {
  
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,45);
  user_delay(223);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,57);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,66);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,59);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  user_delay(13);
  set_ch(ADDR_FREQ_A,67);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  user_delay(13);
  set_ch(ADDR_FREQ_A,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,66);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,62);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,67);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,54);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,66);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,62);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,57);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,66);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,67);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,66);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,62);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(236);
  set_ch(ADDR_FREQ_B,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_B,62);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  user_delay(12);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(249);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,62);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,77);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,60);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,77);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,65);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,60);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(236);
  set_ch(ADDR_FREQ_B,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,65);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,60);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  user_delay(12);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,60);
  user_delay(249);
  set_ch(ADDR_FREQ_A,77);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,76);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,65);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,60);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(248);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,60);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,76);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,79);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,77);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,76);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,59);
  user_delay(236);
  set_ch(ADDR_FREQ_C,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,59);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,59);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,62);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,59);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,68);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,68);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,68);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,75);
  set_ch(ADDR_FREQ_B,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,75);
  set_ch(ADDR_FREQ_B,72);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_B,70);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,60);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,56);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,62);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,58);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,43);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,63);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,44);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,62);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,58);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,43);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,60);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,56);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,44);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,62);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,58);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,44);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,40);
  user_delay(249);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,40);
  user_delay(249);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,40);
  user_delay(249);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,73);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,40);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_B,71);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,40);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,73);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,40);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,66);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,59);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,55);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,40);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,47);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,61);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,57);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,42);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,49);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,62);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,59);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,43);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,61);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,57);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,42);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,49);
  user_delay(248);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,62);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,59);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,43);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,61);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,57);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,42);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,49);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,68);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,68);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(250);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_A,79);
  set_ch(ADDR_FREQ_B,75);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,79);
  set_ch(ADDR_FREQ_B,75);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,79);
  set_ch(ADDR_FREQ_B,75);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(236);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  user_delay(12);
  set_ch(ADDR_FREQ_A,79);
  set_ch(ADDR_FREQ_B,75);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,78);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,74);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,79);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,75);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,60);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,56);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,41);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,62);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,58);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,43);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,63);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,44);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,62);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,58);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,43);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,50);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,63);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,60);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,44);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,65);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,62);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,46);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,53);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,81);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,76);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(250);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,78);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,73);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,42);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,49);
  user_delay(250);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,42);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,42);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,54);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,75);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,70);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,39);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,46);
  user_delay(250);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,39);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,49);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,74);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,69);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,39);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,73);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,68);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,51);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_A,72);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_B,67);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,36);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,43);
  user_delay(249);
  set_ch(ADDR_FREQ_A,71);
  set_ch(ADDR_FREQ_B,66);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,36);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,46);
  user_delay(249);
  set_ch(ADDR_FREQ_A,70);
  set_ch(ADDR_FREQ_B,65);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,36);
  user_delay(249);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,48);
  user_delay(249);
  set_ch(ADDR_FREQ_A,69);
  set_ch(ADDR_FREQ_B,64);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(250);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(250);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,52);
  user_delay(250);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,55);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,45);
  user_delay(249);
  set_ch(ADDR_FREQ_C,0);
  set_ch(ADDR_FREQ_C,57);
  user_delay(250);
  set_ch(ADDR_FREQ_A,0);
  set_ch(ADDR_FREQ_B,0);
  set_ch(ADDR_FREQ_C,0);


}



