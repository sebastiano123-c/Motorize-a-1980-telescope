
#include <Arduino.h>
#include <WiFi.h>

#define WIFI_NTWRK "SCAP4G"
#define WIFI_PSW   "casadolcecasamia"
#define WIFI_TIMEOUT_MS 20000

#define LED_BUILTIN 2

void connectToWiFi(){
  Serial.println("Connecting to WiFi...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NTWRK, WIFI_PSW);

  unsigned long startAttemptTime = millis();

  while(WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < WIFI_TIMEOUT_MS){
    Serial.print("-");
    delay(100);
  }

  if(WiFi.status() != WL_CONNECTED){
    Serial.println("FAILED!");
  }else{
    Serial.print("Connected");
    Serial.println(WiFi.localIP());
  }
}

void setup() {
  Serial.begin(115200);
  connectToWiFi();
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}