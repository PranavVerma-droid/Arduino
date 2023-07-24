#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//SCK PIN -> D1
//SCL PIN -> D2
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define TRIGGER 12 //d6
#define ECHO    14 //d5
#define BULLETIN_LED D7
// NodeMCU Pin D6 > TRIGGER | Pin D5 > ECHO
 
void setup() {
  
  Serial.begin (115200);
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(BUILTIN_LED, OUTPUT);
   if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(200);
  display.clearDisplay();
  display.setTextColor(WHITE);
}
 
void loop() {
  
  long duration, distance;
  digitalWrite(TRIGGER, LOW); 
  digitalWrite(BULLETIN_LED,LOW); 
  delayMicroseconds(2); 
  
  digitalWrite(TRIGGER, HIGH);
  digitalWrite(BULLETIN_LED,HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(TRIGGER, LOW);
  duration = pulseIn(ECHO, HIGH);
  distance= duration*0.034/2;
  
  Serial.print(distance);
  
  Serial.println("Centimeter:");
  delay(100);
  display.clearDisplay();
  
  
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Distance: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(distance);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167);
  display.setTextSize(2);
  
  display.display(); 
}
 
