#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "004484fec6764e2fb0b832ce4f764ea3";

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, "Hipon", "1234567890d");
  //Blynk.begin(auth, "ANTARES-PC_Network", "mowb-5fpt-k4hq");
}

void loop()
{
  Blynk.run();
}
