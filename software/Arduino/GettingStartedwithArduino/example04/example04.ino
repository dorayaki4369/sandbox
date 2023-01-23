// Example 04 : LEDのフェードインとフェードアウト
//(スリープ状態のMacのように)

const int LED = 9;  //LEDが接続されたピン
const int LED2 = 10;
const int LED3 = 11;
int i = 0;          //カウントアップとダウンに使用

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  for(i = 0; i < 255; i++){   //0から254までループ(フェードイン)
    analogWrite(LED, i);       //LEDの明るさをセット
    delay(10);                //10ms停止 analogWrite()は一瞬なのでこれがないと変化が目に見えない
  }  for(i = 0; i < 255; i++){   //0から254までループ(フェードイン)
    analogWrite(LED2, i);       //LEDの明るさをセット
    delay(10);                //10ms停止 analogWrite()は一瞬なのでこれがないと変化が目に見えない
  }
    for(i = 0; i < 255; i++){   //0から254までループ(フェードイン)
    analogWrite(LED3, i);       //LEDの明るさをセット
    delay(10);                //10ms停止 analogWrite()は一瞬なのでこれがないと変化が目に見えない
  }
  for(i = 255;i > 0; i--){    //255から1まで(フェードアウト)
    analogWrite(LED, i);
    delay(10);
  }
    for(i = 255;i > 0; i--){    //255から1まで(フェードアウト)
    analogWrite(LED2, i);
    delay(10);
  }
    for(i = 255;i > 0; i--){    //255から1まで(フェードアウト)
    analogWrite(LED3, i);
    delay(10);
  }
}
