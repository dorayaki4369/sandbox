// Example 03A : ボタンを押すとLEDが点灯し、
//ボタンから指を話した後も点いたままにする

const int LED = 13;
const int BUTTON = 7;

int val = 0;
int state = 0;    //LEDの状態

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);  //入力を読み取りvalに格納

  //入力がHIGH(ボタンが押されている)なら状態(state)を変更
  if(val == HIGH){
    state = 1 - state;
  }

  if(state == 1){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}

