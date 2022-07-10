#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
//SCK PIN -> D1
//SDA PIN -> D2
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#include "DHT.h"
#define DHTPIN 14     // Digital pin connected to the DHT sensor (D5)
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)
DHT dht(DHTPIN, DHTTYPE);

int led = 12;



void setup() {

  Serial.begin (115200);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(200);
  display.clearDisplay();
  display.setTextColor(WHITE);

  pinMode(led, OUTPUT);

  Serial.println(F("DHTxx test!"));
  dht.begin();

}

void loop() {
float  h = dht.readHumidity();
float  t = dht.readTemperature();

digitalWrite(led, HIGH);
    
  display.clearDisplay();
  
  
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Current Temperature: ");
  display.setTextSize(3);
  display.setCursor(0,10);
  display.print(t);
  display.setTextSize(1);


  
  
  display.setCursor(0,33);
  display.print("Made by Pranav Verma!");
  display.setCursor(0,43);
  display.print("Username on Github: ");
  display.setCursor(0,53);
  display.print("PranavVerma-droid");
  display.display();
  delay(1000);


}
