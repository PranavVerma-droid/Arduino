/*
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp8266-client-server-wi-fi/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

#include <ESP8266WiFiMulti.h>
ESP8266WiFiMulti WiFiMulti;

const char* ssid = "Airtel Lockdown";
const char* password = "112345678";

//Your IP address or domain name with URL path
const char* gpio5on = "http://192.168.1.17/5/on";
const char* gpio5off = "http://192.168.1.17/5/off";
//const char* h = "http://192.168.4.1/pressure";


String turnOn;
String turnOff;
const int button1 = 5;
const int button2 = 4; 
unsigned long previousMillis = 0;
const long interval = 5000; 

int test1 = 0;
int test2 = 0;

bool test1high = false;
bool test2high = false;

void setup() {
  Serial.begin(115200);
  Serial.println();
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  
  
  

 
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("Connected to WiFi");
}
void loop() {
  delay(1000);
  unsigned long currentMillis = millis();
  test1 = digitalRead(button1);
  test2 = digitalRead(button2);
  
        if(test1 == HIGH) {
        
        test1high = true;
        }


        if(test1high == true) {
          httpGETRequest(gpio5on); 
          Serial.println("gpio5on");
          } else {
            httpGETRequest(gpio5off);
            Serial.println("gpio5off");
            
            }
  
  
  
  
  //if(currentMillis - previousMillis >= interval) {
     // Check WiFi connection status
    //if ((WiFiMulti.run() == WL_CONNECTED)) {
      

      //Serial.println("Temperature: " + temperature + " *C - Humidity: " + humidity + " % - Pressure: " + pressure + " hPa");

      
      // display temperature
      
      
      // save the last HTTP GET Request
      //previousMillis = currentMillis;
    //}
    //else {
      //Serial.println("WiFi Disconnected");
    //}
  //}
}

String httpGETRequest(const char* serverName) {
  WiFiClient client;
  HTTPClient http;
    

  http.begin(client, serverName);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "--"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
