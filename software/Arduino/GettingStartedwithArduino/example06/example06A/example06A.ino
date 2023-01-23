//Example 06A: アナログ入力の値に応じてLEDの点滅レートが変化

const int LED = 13; //LEDがつながっているピン
int val = 0;        //センサからの値を記憶する変数

void setup() {
  pinMode(LED, OUTPUT); //LEDのピンを出力に設定
  //注 : アナログピンは自動的に入力として設定される

}

void loop() {
  val = analogRead(0);    //センサから値を読み込む

  digitalWrite(13, HIGH); //LEDをオン
  delay(val);             //少しの間、プログラムを停止

  digitalWrite(13, LOW);  //LEDをオフ
  delay(val);             //少しの間、プログラムを停止
}
