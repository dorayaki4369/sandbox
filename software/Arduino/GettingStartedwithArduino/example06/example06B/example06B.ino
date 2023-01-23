//Example 06B: アナログ入力の値に応じてLEDの明るさを変える

const int LED = 13; //LEDがつながっているピン
int val = 0;        //センサからの値を記憶する変数

void setup() {
  pinMode(LED, OUTPUT); //LEDのピンを出力に設定
  //注 : アナログピンは自動的に入力として設定される

}

void loop() {
  val = analogRead(0);      //センサから値を読み込む

  analogWrite(LED, val/4);  //センサの値を明るさとしてLED点灯
  delay(10);                //少しの間、プログラムを停止
}
