//Example 08A: Arduinoのネットワークランプ
//一部のコードはTod E. Kurt(todbot.com)のブログを参考にした

import processing.serial.*;
import java.net.*;
import java.io.*;
import java.util.*;

String feed = "http://blog.arduino.cc";

int interval = 10;  //feedを獲得する間隔
int lastTime;       //最後に獲得した時間

int love = 0;
int peace = 0;
int arduino = 0;

int light = 0;      //ランプが測った明るさ

Serial port;
color c;
String cs;

String buffer = ""; //Arduinoから送られた文字を溜めるところ

PFont font;

void setup() {
  size(640, 480);
  frameRate(10);    //速い更新は不要

  font = loadFont("HelveticaNeue-Bold-32.vlw");
  fill(255);
  textFont(font, 32);

  //注意:
  //以下のコードはSerial.list()で得られるポートの一つ目が
  //Arduinoであることを前提にしている。そうでない場合は
  //次の一行(println)をアンコメントし、再度
  //スケッチを実行してシリアル・ポートのリストを表示し、
  //Arduinoのポートを確認して、その番号で[と]の間の0を
  //置き換える。
  //println(Serial.list());
  String arduinoPort = Serial.list()[3];

  port = new Serial(this, arduinoPort, 9600); //Arduinoに接続

  lastTime = 0;
  fetchData();
}

void draw() {
  background( c );
  int n = (interval - ((millis() - lastTime)/1000));

  //3つの値をベースに色を組み立てる
  c = color(peace, love, arduino);
  cs = "#" + hex(c, 6); //Arduinoへ送る文字を準備

  text("Arduino Networked Lamp", 10, 40);
  text("Reading feed:", 10, 100);
  text(feed, 10, 140);

  text("Net update in " + n + " seconds", 10, 450);
  text("peace", 10, 200);
  text(" " + peace, 130, 200);
  rect(200, 172, peace, 28);

  text("love ", 10, 280);
  text(" " + love, 130, 240);
  rect(200, 212, love, 28);

  text("arduino", 10, 280);
  text(" " + arduino, 130, 280);
  rect(200, 252, arduino, 28);

  //画面に色情報を表示
  text("sending", 10, 340);
  text(cs, 200, 340);
  text("light level", 10, 380);
  rect(200, 352, light/10.23, 28);  //最大値1023から最大100に

  if (n <= 0) {
    fetchData();
    lastTime = millis();
  }

  port.write(cs); //Arduinoへデータを送る

  if (port.available() > 0) {   //データが待っているかチェック
    int inByte = port.read(); //1byte読み込む
    if (inByte != 10) {         //それがnewline(LF)でないなら
      buffer = buffer + char(inByte); //bufferに追加
    } else {

      //newlineが届いたので、データを処理しましょう
      if (buffer.length() > 1) { //データがちゃんとあるか確認
        //最後の文字は改行コードなので切り落とす
        buffer = buffer.substring(0, buffer.length() - 1);

        //bufferの文字を数値(整数)に変換
        light = int(buffer);

        //次の読み込みサイクルのためにbufferを掃除
        buffer = "";

        //Arduinoからはどんどんセンサの読みが送られてくるので
        //最新のデータを得るために溜まってしまったものは削除
        port.clear();
      }
    }
  }
}

void fetchData() {
  //フィードのパースにこれらの文字列を使用
  String data;
  String chunk;

  //カウンタをゼロに
  love = 0;
  peace = 0;
  arduino = 0;

  try {
    URL url = new URL(feed);  //URLを表すオブジェクト
    URLConnection conn = url.openConnection();  //接続を準備
    conn.connect(); //Webサイトに接続完了

    //接続先からやってくるデータを１行ずつbufferにするための
    //仮想的なパイプ
    BufferedReader in = new BufferedReader(
      new InputStreamReader(conn.getInputStream()));

    //フィードを1行ずつ読む
    while ((data = in.readLine()) != null) {

      StringTokenizer st = 
        new StringTokenizer(data, "\"<>,.()[] ");  //それを分解
      while (st.hasMoreTokens()) {
        chunk = st.nextToken().toLowerCase();     //小文字に変換

        if (chunk.indexOf("love") >= 0)    //loveを見つけた？
          love++;                         //loveに1を加える

        if (chunk.indexOf("peace") >= 0)    //peaceを見つけた？
          peace++;                         //peaceに1を加える

        if (chunk.indexOf("arduino") >= 0)    //arduinoを見つけた？
          arduino++;                         //arduinoに1を加える
      }
    }

    //各語を参照した回数は64を上限にしておく
    if (peace > 64) peace = 64;
    if (love > 64) love = 64;
    if (arduino > 64) arduino = 64;

    peace = peace * 4;  //4を掛けて最大値を255にしておくと、
    love = love * 4;    //色を4byteで表現するのに便利
    arduino = arduino * 4;
  }
  catch (Exception ex) {  //エラーの場合はスケッチを停止
    ex.printStackTrace();
    System.out.println("ERROR: " +ex.getMessage());
  }
}