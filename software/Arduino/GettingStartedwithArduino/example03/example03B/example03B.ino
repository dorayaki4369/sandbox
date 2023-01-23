// Example 03B : ボタンを押すとLEDが点灯し、
//ボタンから指を話した後も点いたままにする(改良版)

const int LED = 13;
const int BUTTON = 7;

int val = 0;
int old_val = 0;  //valの前の値を保存しておく変数
int state = 0;    //LEDの状態

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);  //入力を読み取りvalに新鮮な値を格納
  //変化があるかどうかチェック
  if((val == HIGH) && (old_val == LOW)){
    state = 1 - state;
  }
  old_val = val;    //valはもう古くなったので、保管しておく
  if(state == 1){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}

