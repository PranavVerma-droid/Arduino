
int x = 0;

#include <ESP8266WiFi.h>
#include "ESPAsyncWebServer.h"

#include <Wire.h>
#include <Adafruit_Sensor.h>

// Set your access point network credentials
const char* ssid = "Airtel Lockdown";
const char* password = "112345678";

//Adafruit_BME280 bme(BME_CS); // hardware SPI
//Adafruit_BME280 bme(BME_CS, BME_MOSI, BME_MISO, BME_SCK); // software SPI

// Create AsyncWebServer object on port 80
AsyncWebServer server(80);




void loop(){
  x = digitalRead(5);
  Serial.println(x);


}

String readTemp() {
  return String(x);
}




void setup(){
  // Serial port for debugging purposes
  Serial.begin(115200);
  pinMode(5, INPUT);
  Serial.println("");
  
  // Setting the ESP as an access point
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

      server.on("/irstatus", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", readTemp().c_str());
  });

  server.begin();

  



  // Start server
  
}
 
