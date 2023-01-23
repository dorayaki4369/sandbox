//***********************************************************
// サーボモーターを動かすプログラム
//***********************************************************
#include <Servo.h>  //サーボモーター用ライブラリを読み込み
Servo myservo; //サーボ用のオブジェクトを作成
int val_m = 0; //サーボの角度を格納するための変数

const int LED = 13; //LEDがつながっているピン

const int BUTTON = 7;

int val_l = 0;        //光センサからの値を記憶する変数

int val_s = 0;
int old_val_s = 0;  //val_sの前の値を保存しておく変数
int state = 0;    //LEDの状態
void setup()
{
myservo.attach(9); //デジタル9番ピンをサーボの角度命令出力ピンとして設定

pinMode(LED, OUTPUT); //LEDのピンを出力に設定
//注 : アナログピンは自動的に入力として設定される
}
void loop()
{
 val_s = digitalRead(BUTTON);  //入力を読み取りval_sに新鮮な値を格納
  
  //変化があるかどうかチェック
  if((val_s == HIGH) && (old_val_s == LOW)){
    state = 1 - state;
    val_m = 30;
    myservo.write(val_m); //サーボを動かす(30度)
    delay(1500);
    val_m = 0;
    myservo.write(val_m); //サーボを動かす(0度)

    delay(100);
  }
  old_val_s = val_s;    //val_sはもう古くなったので、保管しておく
  
  if(state == 1){
    digitalWrite(LED, HIGH);
  }else{
    digitalWrite(LED, LOW);
  }
}
