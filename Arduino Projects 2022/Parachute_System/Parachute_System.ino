 
#include <Servo.h> // servo library  
Servo s1;  
const int buttonPin1 = 4;
const int buttonPin2 = 5;
int buttonState1 = 0;
int buttonState2 = 0;
bool deploy = false;


void setup()  
 {   
  Serial.begin(9600);
  s1.attach(0);  //D3 pin of arduino  
  pinMode(buttonPin1, INPUT); 
  pinMode(buttonPin2, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
 }  
void loop()   
 {  
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState1 == HIGH) {
      deploy = true;
      
       }
  if (buttonState2 == HIGH){
    deploy = false;
    Serial.println("2nd Button Pressed");
    
    
  }
  
if (deploy == true){
    delay(0);
    s1.write(180);  
    digitalWrite(LED_BUILTIN, HIGH);  
    Serial.println("Deploy = True");
  } else {
    s1.write(0);
    Serial.println("Deploy = False");
    digitalWrite(LED_BUILTIN, LOW);
    }  
 }


 
