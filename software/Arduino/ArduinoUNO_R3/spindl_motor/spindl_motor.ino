// arduino でHDDスピンドルモータ制御
// 単純な矩形波制御
// DC三相モータになら大抵応用できると思います。


// クラス定義
// UVW各端子をコントロール
class TriCont {
  public:
    void PinDefine(int Hside, int Lside);   //使用ピンの定義
    void PinGive(int mode);                  //High側TrをONにするか。Low側TrをONにするか。
    int HpinNo;                             //割り当てられたピンの番号
    int LpinNo;
  private:
};

//使用ピンの定義
void TriCont::PinDefine(int Hside, int Lside)
{
  HpinNo = Hside;
  LpinNo = Lside;
  pinMode(HpinNo, OUTPUT);
  pinMode(LpinNo, OUTPUT);
  digitalWrite(HpinNo, LOW);        //貫通電流防止のためH/L両方LOWにしておく
  digitalWrite(LpinNo, LOW);
}

//High側をONにするか。Low側をONにするか。
void TriCont::PinGive(int mode)      //mode : 1=High  -1=Low 0=none(どこにも通電しない)
{
  digitalWrite(HpinNo, LOW);
  digitalWrite(LpinNo, LOW);
  delay(1);                         //貫通電流防止のためにデッドタイム作る。ここでは1msec

  switch (mode)
  {
    case 0:
      digitalWrite(HpinNo, LOW);         // 0 の時は通電無し
      digitalWrite(LpinNo, LOW);
      break;
    case 1:
      digitalWrite(HpinNo, HIGH);        // 1 の時はHigh側Trを通電。端子に5Vを押し出す
      digitalWrite(LpinNo, LOW);
      break;
    case -1:
      digitalWrite(HpinNo, LOW);         // -1 の時はLow側Trを通電。端子から電流を引き込む
      digitalWrite(LpinNo, HIGH);
      break;
    default:
      break;
  }
}



// =======クラス関連終了。以下メイン============================


TriCont Ucont;                  //各端子ごとにクラスから生成
TriCont Vcont;
TriCont Wcont;

void setup()
{
  Ucont.PinDefine(8, 9);        //使用するピンを作る
  Vcont.PinDefine(10, 11);
  Wcont.PinDefine(12, 13);
}

void loop()
{
  /*
  stage| 1| 2| 3| 4| 5| 6|
  ------------------------
      U| 1| 1| 0|-1|-1| 0|
      V|-1| 0| 1| 1| 0|-1|
      W| 0|-1|-1| 0| 1| 1|
  ------------------------
   1:Voltage push
  -1:Voltage pull
   0:none
  stage1～6を繰り返す事で回転していく
  */

  Ucont.PinGive(1);      //stage1
  Vcont.PinGive(-1);
  Wcont.PinGive(0);
  delay(20);             //delayを少なくすれば高速回転。脱調に注意

  Ucont.PinGive(1);      //stage2
  Vcont.PinGive(0);
  Wcont.PinGive(-1);
  delay(20);


  Ucont.PinGive(0);      //stage3
  Vcont.PinGive(1);
  Wcont.PinGive(-1);
  delay(20);

  Ucont.PinGive(-1);    //stage4
  Vcont.PinGive(1);
  Wcont.PinGive(0);
  delay(20);

  Ucont.PinGive(-1);    //stage5
  Vcont.PinGive(0);
  Wcont.PinGive(1);
  delay(20);

  Ucont.PinGive(0);      //stage6
  Vcont.PinGive(-1);
  Wcont.PinGive(1);
  delay(20);
}
