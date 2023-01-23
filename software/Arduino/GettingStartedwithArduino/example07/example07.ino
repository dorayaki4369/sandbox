//Example 07: アナログ入力ピン0の値をコンピュータへ送る
//アップロードの後に、[Serial Moniter]ボタンを押すこと

const int SENSOR = 0; //抵抗型のセンサーがつながっているピン
int val = 0;          //センサからの値を記憶する変数

void setup() {
  Serial.begin(9600); //シリアルポートを開きます
                       //毎秒9600bitでコンピュータにデータを送信
}

void loop() {
  val = analogRead(SENSOR); //  センサからの値を記憶する

  Serial.println(val);     //シリアルポートにデータを出力
  delay(100);               //送信したら0.1秒待つ
}
