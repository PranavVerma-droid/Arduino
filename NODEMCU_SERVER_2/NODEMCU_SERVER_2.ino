#include <ESP8266WiFi.h>


const char* ssid     = "Airtel Lockdown";
const char* password = "112345678";


WiFiServer server(80);


String header;


unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

void setup() {
  Serial.begin(115200);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  WiFiClient client = server.available();   // Listen for incoming clients

  if (client) {                             // If a new client connects,
    Serial.println("New Client.");          // print a message out in the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) { // loop while the client's connected
      currentTime = millis();         
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        header += c;
        if (c == '\n') {                    // if the byte is a newline character
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            //Type your HTML Code HERE:



            
            
            
            client.println("<html>");
            client.println("<head>");
            client.println("<title>Pranav's Web Server</title>");
            client.println("<h1 Align=center><b><u>DOWNLOAD FREE MOVIES AND GAMES VIA Steamunlocked, Utorrent and Hdmovies!</b></u></h1>");
            client.println("</head><body bgcolor="#00FF00">");
            client.println("<p><center>Hey! This is my server! Get out!</center></p>");
            client.println("</body></html>");
            
            

            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
