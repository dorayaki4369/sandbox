#include <Wire.h>
#include <ST7032.h>

ST7032 lcd;

void setup(){
    lcd.begin(8, 2);
    lcd.setContrast(30);
    lcd.print("Hello");
}

void loop(){
    int t = 123;
    lcd.setCursor(0, 1);
    lcd.print("World");
    lcd.setCursor(5, 1);
    lcd.print(t);
}
