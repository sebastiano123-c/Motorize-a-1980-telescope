
#include <Arduino.h>
#include <WiFiCredentials.h>
#include "OTA.h"

OTA myWiFi("Kepler1-esp32-03", WIFI_SSID, WIFI_PASSWORD);

#define LED_BUILTIN 2

void setup() {
  Serial.begin(115200);
  myWiFi.setupWiFi();
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  myWiFi.handleWiFi();
  delay(1);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}