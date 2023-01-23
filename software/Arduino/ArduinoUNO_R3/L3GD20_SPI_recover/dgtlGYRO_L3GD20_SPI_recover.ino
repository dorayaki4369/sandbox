//L3GD20と通信する簡易プログラム
//
//SPIの3-wire modeで通信(P.28参照)
//DO  bit0    HIGH
//DI  bit1    1でアドレスが増やされる
//DI  bit2-7  レジスタのアドレス
//DO  bit8-15 データ

#include <SPI.h>
short X, Y, Z;  //2byte
float x, y, z;

void L3GD20_write(byte reg, byte val) {
  digitalWrite(10, LOW);
  SPI.transfer(reg);
  SPI.transfer(val);
  digitalWrite(10, HIGH);
}

byte L3GD20_read(byte reg) {
  byte ret = 0;
  digitalWrite(10, LOW);
  SPI.transfer(reg | 0x80); //0bit目は必ず1
  ret = SPI.transfer(0);
  digitalWrite(10, HIGH);
  return ret;
}

void setup () {
  digitalWrite(10, HIGH);
  pinMode(10, OUTPUT);
  SPI.begin();
  SPI.setBitOrder(MSBFIRST);  //アイドル時1
  SPI.setDataMode(SPI_MODE3); //3-wire mode
  SPI.setClockDivider(SPI_CLOCK_DIV2);  //立ち上がりで読む
  Serial .begin(115200);
  while (!Serial ) {}
  Serial .println("ms,x,y,z");
  Serial .println(L3GD20_read(0x0f), HEX); // should show D4 (WHO_AM_I)
  //ノーマルモード ODR=760[Hz] Cut-off=30
  //CTRL_REG1 DR1,DR0,BW1,BW0,PD,Z_en,Y_en,X_en
    //DRはデータレート,BWは帯域幅を選択できる(Table 21参照)
    //PDはパワーダウンモード 通常は0で動かないようになっている
  L3GD20_write(0x20, B11001111);
}

void loop () {
  //Output register mapping参照
  //各軸のデータは2byteの2の補数で表現されている
  //上位byte  下位byte   値
  //00000000  00000000 = 0
  //上位byteにOUT_*_H,下位byteにOUT_*_Lを入れる(シフト演算子を使用)
  
  X = L3GD20_read(0x29);  //OUT_X_H
  x = X = (X << 8) | L3GD20_read(0x28); //OUT_X_L
  Y = L3GD20_read(0x2B);  //OUT_Y_H
  y = Y = (Y << 8) | L3GD20_read(0x2A); //OUT_Y_L
  Z = L3GD20_read(0x2D);  //OUT_Z_H
  z = Z = (Z << 8) | L3GD20_read(0x2C); //OUT_Z_L
  
  //各レンジの分解能をかけてdpsに変換
  x *= 0.00875;
  y *= 0.00875;
  z *= 0.00875;
  Serial .print(millis()); Serial .print(",");
  Serial .print(x); Serial .print(",");
  Serial .print(y); Serial .print(",");
  Serial .println(z);
  delay(5);
}
