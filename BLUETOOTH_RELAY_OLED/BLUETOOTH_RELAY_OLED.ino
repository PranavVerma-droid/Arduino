#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//SCK PIN -> D1
//SDA PIN -> D2
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


char inputByte;
int relay = 10;


void setup() {
  pinMode(relay, OUTPUT);
  Serial.begin (9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0,0);

  digitalWrite(relay, LOW);
  delay(1000);


  display.print("Display Initializing");
  delay(700);
  display.display();
  display.print(".");
  delay(400);
    display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);  display.display();
  display.print(".");
  delay(400);

  
 
  
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Display Initialized.");
  display.setCursor(0,10);
  display.println("Waiting for Command");
  display.display();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  while(Serial.available()>0){
  inputByte= Serial.read();

  
  Serial.println(inputByte);
  
  if (inputByte == 'Z'){
  digitalWrite(relay, HIGH);
  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Latest Output:");
  display.setCursor(0,10);
  display.setTextSize(3);
  display.println("Z (ON)");
  }
  else if (inputByte == 'z'){
  digitalWrite(relay, LOW);
  display.setTextSize(1);
  display.clearDisplay();
  display.setCursor(0,0);
  display.println("Latest Output:");
  display.setCursor(0,10);
  display.setTextSize(3);
  display.println("z (OFF)");
  } 
  }
  
  display.display();
  
}
