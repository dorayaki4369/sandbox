//Example 08B: Arduinoネットワークランプ

const int SENSOR = 0;
const int R_LED = 9;
const int G_LED = 10;
const int B_LED = 11;
const int BUTTON = 12;

int val = 0;  //センサから読み取った値を格納する変数

int btn = LOW;
int old_btn = LOW;
int state = 0;
char buffer[7];
int pointer = 0;
byte inByte = 0;

byte r = 0;
byte g = 0;
byte b = 0;

void setup() {
  Serial.begin(9600); //シリアルポートを開く
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = analogRead(SENSOR); //センサから値を読む
  Serial.println(val);

  if(Serial.available() > 0) {
    //受信したデータを読み取る
    inByte = Serial.read();

    //マーカ(#)が見つかったら、続く6文字が色情報
    if(inByte == '#'){
      while(pointer < 6){                  //6文字蓄積
        buffer[pointer] = Serial.read();  //bufferに蓄積
        pointer++;                         //pointerを1進める
      }
      //3つの16進の数字が揃ったので、RGBの3byteにデコード
      r = hex2dec(buffer[1]) + hex2dec(buffer[0]) * 16;
      g = hex2dec(buffer[3]) + hex2dec(buffer[2]) * 16;
      b = hex2dec(buffer[5]) + hex2dec(buffer[4]) * 16;

      pointer = 0;  //次にbufferを使うときのためにクリア
    }
  }

  btn = digitalRead(BUTTON);  //読み取った値を格納

  //変化があるかどうか
  if((btn == HIGH) && (old_btn == LOW)){
    state = 1 - state;
  }

  old_btn = btn;  //古い値を保存しておく

  if(state == 1){ //ランプをオンにする場合
    analogWrite(R_LED, r); //コンピュータから来た
    analogWrite(G_LED, g); //色情報に従って
    analogWrite(B_LED, b); //LEDを点灯する
  }
  else{
    analogWrite(R_LED, 0); //あるいは消す
    analogWrite(G_LED, 0);
    analogWrite(B_LED, 0);
  }
  delay(100); //0.1秒間待つ
}

int hex2dec(byte c){  //16進数を整数に変換
  if(c >= '0' && c <= '9') {
    return c - '0';
  }
  else if(c >= 'A' && c <= 'F'){
    return c - 'A' + 10;
  }
}

