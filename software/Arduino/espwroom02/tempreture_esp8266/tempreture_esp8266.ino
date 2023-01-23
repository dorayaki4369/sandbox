/**************************************************************
 * Blynk is a platform with iOS and Android apps to control
 * Arduino, Raspberry Pi and the likes over the Internet.
 * You can easily build graphic interfaces for all your
 * projects by simply dragging and dropping widgets.
 *
 *   Downloads, docs, tutorials: http://www.blynk.cc
 *   Blynk community:            http://community.blynk.cc
 *   Social networks:            http://www.fb.com/blynkapp
 *                               http://twitter.com/blynk_app
 *
 * Blynk library is licensed under MIT license
 * This example code is in public domain.
 *
 **************************************************************
 * This example runs directly on ESP8266 chip.
 *
 * You need to install this for ESP8266 development:
 *   https://github.com/esp8266/Arduino
 * 
 * Please be sure to select hte right ESP8266 module
 * in the Tools -> Board menu!
 *
 * Change WiFi ssid, pass, and Blynk auth token to run :)
 *
 **************************************************************/
 
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <BME280_MOD-1022.h>
#include <Wire.h>
 
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "Your Aouth Token";
 
unsigned long lastCheck = 0;
double tempMostAccurate, humidityMostAccurate, pressureMostAccurate;
char buff[50];
 
void setup()
{
  Serial.begin(115200);
  Blynk.begin(auth, "ssid", "PassCode");
  Wire.begin(); 
  pinMode(12, OUTPUT);
 
  // need to read the NVM compensation parameters
  BME280.readCompensationParams();
 
  BME280.writeStandbyTime(tsb_0p5ms);         // tsb = 0.5ms
  BME280.writeFilterCoefficient(fc_16);       // IIR Filter coefficient 16
  BME280.writeOversamplingPressure(os16x);    // pressure x16
  BME280.writeOversamplingTemperature(os2x);  // temperature x2
  BME280.writeOversamplingHumidity(os1x);     // humidity x1
 
  BME280.writeMode(smNormal);
}
 
void formattedFloat(float x, uint8_t precision, char *buff) {
  dtostrf(x, 7, precision, buff);
}
 
BLYNK_READ(V0) 
{ 
  tempMostAccurate = BME280.getTemperatureMostAccurate();
  formattedFloat(tempMostAccurate, 2, buff);
  Blynk.virtualWrite(V0, buff);
}
 
BLYNK_READ(V1) 
{ 
  humidityMostAccurate = BME280.getHumidityMostAccurate();
  formattedFloat(humidityMostAccurate, 2, buff);
  Blynk.virtualWrite(V1, buff);
}
 
BLYNK_READ(V2) 
{ 
  pressureMostAccurate = BME280.getPressureMostAccurate();
  formattedFloat(pressureMostAccurate, 0, buff);
  Blynk.virtualWrite(V2, buff);
}
 
void loop()
{
  Blynk.run();
 
  int diff = millis() - lastCheck;
  if (diff > 1000) {
    while (BME280.isMeasuring()) {
 
    }
    // read out the data - must do this before calling the getxxxxx routines
    BME280.readMeasurements();
    lastCheck = millis();
  } else if (diff < 0) {
    lastCheck = 0;
  }
}
