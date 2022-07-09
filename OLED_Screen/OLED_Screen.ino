#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

int led = 2;
int ledState = 0;

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//SCK PIN -> D1
//SDA PIN -> D2
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


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

}

void loop() {
  display.clearDisplay();
  
  
  digitalWrite(led, HIGH);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LED_STATUS: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print("OFF");
  display.setTextSize(1);
  delay(1000);
  
  

  
  digitalWrite(led, LOW);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LED_STATUS: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print("ON");
  display.setTextSize(1);
  delay(1000);

}
