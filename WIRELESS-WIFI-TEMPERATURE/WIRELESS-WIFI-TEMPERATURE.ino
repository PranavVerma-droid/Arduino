#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "DHT.h"
#define DHTPIN 14    

const char* ssid = "Pranav's Web Project";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();

  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  
  delay(2000);


  float h = dht.readHumidity();

  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }



  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);

  /*Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
  Serial.print(f);
  Serial.print(F("F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("C "));
  Serial.print(hif);
  Serial.println(F("F"));*/

  WiFiClient client = server.available();

  if (client) {                             
    Serial.println("New Client.");         
    String currentLine = "";                
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { 
      currentTime = millis();         
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);                    
        header += c;
        if (c == '\n') {                    
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
           



            
            
            
            client.println("<html>");
            client.println("<head>");
            client.println("<title>Pranav's Web Server</title>");
            client.println("<h1><b><u><center>Pranav's Web Server</center></b></u></h1>");
            client.println("</head><body>");
            client.print("<p><center>The Current Temperature is:");
            client.print(t);
            client.println(" C</p></center>");
            
            
            client.println("</body></html>");
            
            

            break;
          } else { 
            currentLine = "";
          }
        } else if (c != '\r') {  
          currentLine += c;      
        }
      }
    }
    
    header = "";
    
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
