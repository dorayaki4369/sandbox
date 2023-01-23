#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <SPI.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

/****************************************
   RemoteTank

   ANTARES-PC_Network is my house's wifi
 ****************************************/

//blynk setting
//const char ssid[] = "ANTARES-PC_Network";
//const char password[] = "mowb-5fpt-k4hq";
const char ssid[] = "Hipon";
const char pass[] = "1234567890d";
const char auth[] = "004484fec6764e2fb0b832ce4f764ea3";

//machine setting
//IOPin
int BUTTON = 12;

//virtualPin
WidgetLED led1(V0);
int label = V6;
int slider = V2;

//variable

BLYNK_WRITE(V1)
{
  int pinValue = param.asInt(); // assigning incoming value from pin V1 to a variable
  // You can also use:
  // String i = param.asStr();
  // double d = param.asDouble();
  Serial.print("V1 Slider value is: ");
  Serial.println(pinValue);
}


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  Blynk.virtualWrite(label, 3.14);
}
