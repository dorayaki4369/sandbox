//Example 05: ボタンを押すとLEDが点灯し、
//ボタンから指を離した後も点いたままにする
//チャタリングを解消する簡単な方法を取り入れる
//ボタンを押したままにすると、明るさが変化する

const int LED = 9;    //LEDが接続されているピン
const int BUTTON = 7; //プッシュボタンが接続されている入力ピン

int va1 = 0;      //入力ピンの状態がこの変数に記憶される
int old_va1 = 0;  //va1の前の状態を保存しておく変数
int state = 0;    //LEDの状態

int brightness = 128;          //明るさの値を保存する
unsigned long starttime = 0;   //いつ押し始めたのか

void setup() {
  pinMode(LED, OUTPUT);   //ArduinoにLEDが出力であると伝える
  pinMode(BUTTON, INPUT); //BUTTONは入力に設定
}

void loop() {
  va1 = digitalRead(BUTTON);  //入力を読みva1に新鮮な値を保存

  //変化があるかチェック
  if((va1 == HIGH) && (old_va1 == LOW)){
    state = 1 - state;    //オフからオンへ、オンからオフへ
    starttime = millis(); //millis()はArduinoの時計
                          //ボードがリセットされてからの時間を
                          //ミリ秒単位で返す
                          //(最後にボタンが押された時間を記録)
    delay(10);
  }

  //ボタンが押し続けられているかをチェック
  if((va1 == HIGH) && (old_va1 == HIGH)){
    //500ms以上押されているか？
    if(state == 1 && (millis() - starttime) > 500){
      brightness++; //brightnessに1を足す
      delay(10);      //brightnessの速度が速くなりすぎないように
      if(brightness > 255){ //255が最大値
        brightness = 0;     //255を超えたら0に戻す
      }
    }
  }

  old_va1 = va1;  //va1はもう古いので、しまっておく

  if(state == 1){
    analogWrite(LED, brightness);   //現在の明るさでLEDを点灯
  } else {
    analogWrite(LED, 0);            //LEDをオフ
  }
}
