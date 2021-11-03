#include "OTAWebServer.h"
#include <WiFiCredentials.h>

OTAWebServer otaWebServer("Kepler1-esp32-03", WIFI_SSID, WIFI_PASSWORD);

#define LED_BUILTIN 2

void setup(){
  otaWebServer.setupWebServer();
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  otaWebServer.handleWebServer();
  delay(1);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}