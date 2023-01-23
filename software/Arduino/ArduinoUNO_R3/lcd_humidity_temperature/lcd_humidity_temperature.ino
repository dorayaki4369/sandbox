#include <Wire.h>
#include <ST7032.h>
#include "DHT.h"

#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT11   // DHT 11

ST7032 lcd;
DHT dht(DHTPIN, DHTTYPE);

void setup(){
    dht.begin();
    lcd.begin(8, 2);
    lcd.setContrast(30);
}

void loop(){
    // Wait a few seconds between measurements.
    delay(2000);
  
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    int h = dht.readHumidity();
    // Read temperature as Celsius (the default)
    int t = dht.readTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    int f = dht.readTemperature(true);
   
    lcd.setCursor(0, 0);
    lcd.print("Humi");
    lcd.setCursor(5, 0);
    lcd.print(h);
    lcd.setCursor(7, 0);
    lcd.print("%");
    lcd.setCursor(0, 1);
    lcd.print("Temp");
    lcd.setCursor(5, 1);
    lcd.print(t);
    lcd.setCursor(7, 1);
    lcd.print("C");
}
