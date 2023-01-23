// "A very easy and simple inverted pendulum balancing robot"
// You need only half a day to make it, if you have some Materials.
// (This sketch is ver.2.0)
// No timer library is used in this version.
// But stability of robot is more improved than earlier version.
// Copyright (C) 2014 ArduinoDeXXX All Rights Reserved.
//#include <MsTimer2.h> //01 (This line is omitted in this version.)
int i = 0; //02
byte countS = 0; //03
long zeroOmegaI = 0; //04
int recOmegaI[10]; //05
int omegaI = 0; //06
long thetaI = 0; //07
long sumPower = 0; //08
long sumSumP = 0; //09
const int kAngle = 54; //10
const int kOmega = 170; //11
const long kSpeed = 60; //12
const long kDistance = 60; //13
long powerScale; //14
int power; //15
long vE5 = 0; //16
long xE5 = 0; //17
void setup () { //18
  Serial .begin(115200); //19
  pinMode(4, OUTPUT); //20
  pinMode(5, OUTPUT); //20-a
  pinMode(6, OUTPUT); //21
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  for ( i = 0 ; i < 10 ; i++ ) {
    recOmegaI[i] = 0;  //25
  }
  delay(300);
  training();
  // MsTimer2::set(5, chkAndCtl); // (This line is omitted in this version.)
  // MsTimer2::start(); // (This line is omitted in this version.)
} //30
void loop () { //31
  chkAndCtl();// NL1 (This is a new line in this version.)
  if ( power > 0 ) {
    analogWrite( 6, power );
    digitalWrite( 4, HIGH );
    digitalWrite( 5, LOW ); //35
    analogWrite( 9, power );
    digitalWrite( 7, HIGH );
    digitalWrite( 8, LOW );
  } else {
    analogWrite( 6, - power ); //40
    digitalWrite( 4, LOW );
    digitalWrite( 5, HIGH );
    analogWrite( 9, - power );
    digitalWrite( 7, LOW );
    digitalWrite( 8, HIGH ); //45
  }
  delayMicroseconds(3600); // NL2 (This is a new line in this version.)
} //47
void training() {
  // 48
  delay (1000);
  for ( i = 0 ; i < 500 ; i++ ) { //50
    zeroOmegaI = zeroOmegaI + analogRead(A5);
  }
  zeroOmegaI = zeroOmegaI / i;
} //54
void chkAndCtl() { //55
  omegaI = 0; // NL3 (These 6 lines, NL3-NL8, are added in this version.)
  for ( i = 0 ; i < 10 ; i++ ) { //NL4
    omegaI = omegaI + analogRead(A5) - zeroOmegaI; //NL5
    delayMicroseconds(10); //NL6
  }// NL7
  omegaI = omegaI / 10;// NL8
  // omegaI = analogRead(A5) - zeroOmegaI; // (This line is omitted in this
  if ( abs( omegaI ) < 3 ) {
    omegaI = 0;  // (The lower bound is less than
  }
  recOmegaI[0] = omegaI;
  thetaI = thetaI + omegaI;
  countS = 0; //60
  for ( i = 0 ; i < 10 ; i++ ) {
    if ( abs( recOmegaI[i] ) < 8 ) {
      countS++;
    }
  }
  if ( countS > 9 ) {
    thetaI = 0;// 65
    vE5 = 0;
    xE5 = 0;
    sumPower = 0;
    sumSumP = 0;
  } //70
  for ( i = 9 ; i > 0 ; i-- ) {
    recOmegaI[ i ] = recOmegaI[ i - 1 ];
  }
  powerScale = ( kAngle * thetaI / 100 ) + ( kOmega * omegaI / 100 ) + ( kSpeed * vE5 / 1000 ) + ( kDistance * xE5 / 1000 ); //72
  power = max ( min ( 95 * powerScale / 100 , 255 ) , -255 );
  sumPower = sumPower + power;
  sumSumP = sumSumP + sumPower;// 75
  // vE5 = ??? //76
  // xE5 = ??? //77
} //78
// Copyright (C) 2014 ArduinoDeXXX All Rights Reserved. //79
