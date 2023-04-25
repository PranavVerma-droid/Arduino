//Code by Pranav Verma
//https://github.com/PranavVerma-droid

//Pin Definitions:

  //HC - SR04:
  
  //GND -> GND
  //ECHO -> D3
  //Trig -> D2
  //VCC -> 5V

  //OLED SCREEN:

  //GND -> GND
  //VDD/VCC -> 3.3V
  //SCL/SCK -> A5
  //SDA -> A4

  //BLUETOOTH:

  //GND -> GND
  //VCC -> 5V
  //TxD -> Rx
  //RxD -> TxD


//Through Bluetooth, if you send a command of z, the relay will go into "LOW"
//Through Bluetooth, if you send a command of Z, the relay will go into "HIGH"

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

// defines variables
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement
char inputByte;
const int relay = 11;
const int ir = 4;

int x = 0;
int y = 0;
// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
//SCK PIN -> D1
//SDA PIN -> D2
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// 'index(2)', 10x10px
const unsigned char myBitmap [] PROGMEM = {
  0xfb, 0xc0, 0xc0, 0xc0, 0x92, 0x40, 0x9e, 0x40, 0x9e, 0x00, 0x8e, 0x00, 0x9c, 0x40, 0x8c, 0x40, 
  0xc0, 0xc0, 0xfb, 0xc0
};

void setup() {

  Serial.begin (9600);
     if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(200);
  display.clearDisplay();
  display.setTextColor(WHITE);

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  Serial.begin(9600); // // Serial Communication is starting with 9600 of baudrate speed
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // print some text in Serial Monitor
  Serial.println("with Arduino UNO R3");
  pinMode(relay,OUTPUT);

}

void loop() {
  while(Serial.available()>0){
  
  inputByte= Serial.read();
  Serial.println(inputByte);
  
  if (inputByte=='Z'){
    digitalWrite(relay,HIGH); }
  
  else if (inputByte=='z'){
    digitalWrite(relay,LOW); } 
  }
  
  
  x = digitalRead(relay);
  y = digitalRead(ir);
  
  display.clearDisplay();
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  
  digitalWrite(LED_BUILTIN, HIGH);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LED_STATUS: ");
  display.setTextSize(1);
  display.println("ON");
  display.setTextSize(1);
  display.setCursor(0,10);
  display.print("Distance: ");
  display.println(distance);
  display.setCursor(0,20);
  display.print("Relay Output: ");
  if(x == HIGH) {
    display.print("HIGH");
    } else {
      display.print("LOW");
      }

  display.setCursor(0,30);
  display.print("IR INPUT: ");
  if(y == HIGH) {
    display.println("HIGH");
    } else {
      display.println("LOW"); }
  display.setCursor(0,43);
  display.print("Made by Pranav Verma!");

  display.setCursor(0,53);
  display.print("PranavVerma-droid");
  display.drawBitmap(105, 53, myBitmap, 10, 10, WHITE);
  display.setTextColor(WHITE);

  display.display();
  delay(690);
  
  

  display.clearDisplay();
  digitalWrite(LED_BUILTIN, LOW);
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("LED_STATUS: ");
  display.setTextSize(1);
  display.println("OFF");
  display.setTextSize(1);
    display.setCursor(0,10);
  display.print("Distance: ");
  display.println(distance);
    display.setCursor(0,20);
  display.print("Relay Output: ");
    if(x == HIGH) {
    display.print("HIGH");
    } else {
      display.print("LOW");
      }
    display.setCursor(0,30);
  display.print("IR INPUT: ");
  if(y == HIGH) {
    display.println("HIGH");
    } else {
      display.println("LOW"); }
  display.setCursor(0,43);
  display.print("Made by Pranav Verma!");

  display.setCursor(0,53);
  display.print("PranavVerma-droid");
  display.drawBitmap(105, 53, myBitmap, 10, 10, WHITE);
  display.setTextColor(WHITE);

  

  
  
  
  
  display.display();
  delay(690);
  

}
