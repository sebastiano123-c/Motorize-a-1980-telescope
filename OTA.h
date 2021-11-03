/*
 * OTA
 * 
 * Add these two functions in the setup and loop to use the WiFi functionalities, e.g. wifi upload...
 * 
 * @author: Sebastiano Cocchi
*/
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

class OTA{
    public:
        // attributes
        const char* ssid;
        const char* password;
        const char* host;

        // constructor
        OTA(const char* hostName, const char* ssidName, const char* passwordString);

        // functions
        void setupWiFi();
        void handleWiFi();
};

OTA::OTA(const char* hostName, const char* ssidName, const char* passwordString) {
    host = hostName;
    ssid = ssidName;
    password = passwordString;
}

void OTA::setupWiFi(void){
    Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.println("Connection Failed! Rebooting...");
        delay(5000);
        ESP.restart();
    }

    // Port defaults to 3232
    // ArduinoOTA.setPort(3232);

    // Hostname defaults to esp3232-[MAC]
    ArduinoOTA.setHostname(host);

    // No authentication by default
    // ArduinoOTA.setPassword("admin");

    // Password can be set with it's md5 value as well
    // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
    // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

    ArduinoOTA.begin();

    Serial.println("Ready");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void OTA::handleWiFi(){
    ArduinoOTA.handle();
}