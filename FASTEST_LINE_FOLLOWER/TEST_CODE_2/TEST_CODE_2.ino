
//Declaration of 5 ir input pins
const int s1 = A3;
const int s2 = A4;
const int s3 = A2;
const int s4 = A5;
const int s5 = A1;
const int s6 = A6;
const int s7 = A7;
const int s8 = A0;





//COlor Definitions
int colors1 = 0;
int colors2 = 0;
int colors3 = 0;
int colors4 = 0;
int colors5 = 0;
int colors6 = 0;
int colors7 = 0;
int colors8 = 0;

//Definitions of motor Pins
const int motor1pin1 = 5;
const int motor1pin2 = 6;
const int motor2pin1 = 9;
const int motor2pin2 = 10;

void setup() {
  //Declaring Input Pins
  pinMode(s1, INPUT);
  pinMode(s2, INPUT);
  pinMode(s3, INPUT);
  pinMode(s4, INPUT);
  pinMode(s5, INPUT);

  
  pinMode(s6, INPUT);
  pinMode(s7, INPUT);
  pinMode(s8, INPUT);
  
  //Beginning Serial
  Serial.begin(9600);
  
  //Declaring Output Pins
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);

  //Putting Motors to sleep
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);

}

void loop() {
  //Reading output and defining to variables
  colors1 = analogRead(s1);
  colors2 = analogRead(s2);
  colors3 = analogRead(s3);
  colors4 = analogRead(s4);
  colors5 = analogRead(s5);
  colors6 = analogRead(s6);
  colors7 = analogRead(s7);
  colors8 = analogRead(s8);

  //Serial.print("RIGHT SENSOR: ");
  //Serial.println(colors5);
  //Serial.print("MIDDLE SENSOR: ");
  //Serial.println(colors3);
  //Serial.print("LEFT SENSOR: ");
  //Serial.println(colors1);

  if(colors3 < 50) {
  //If the front sensor has black in-front of it, then run the motors
  //The IR will return a value of zero because it is not getting any light back (Black tape will absorb all Light)
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
    
    } else if(colors3 > 50){
      //If the front sensor has white.....
      if((colors1 < 50) && (colors2 < 50)) {
          //... and the left sensors have black, move to the left 
          digitalWrite(motor1pin1, LOW);
          digitalWrite(motor1pin2, LOW);
          digitalWrite(motor2pin1, LOW);
          digitalWrite(motor2pin2, HIGH);
        
        
        } else if((colors4 < 50) && (colors5 < 50)) {
            //... and the right sensors have black, move to the right
            digitalWrite(motor1pin1, LOW);
            digitalWrite(motor1pin2, HIGH);
            digitalWrite(motor2pin1, LOW);
            digitalWrite(motor2pin2, LOW);
          
          
          } else {
              //... and none of the sides have black, stop the motors.
              digitalWrite(motor1pin1, LOW);
              digitalWrite(motor1pin2, LOW);
              digitalWrite(motor2pin1, LOW);
              digitalWrite(motor2pin2, LOW);
            
            
            }
      
      
      
      //Finish code here.
      }
  
  
  
  
  
  
  
  
  
  
  
  //Scrap Code:
  
  //if(colors3 < 50) {
      //digitalWrite(motor1pin1, LOW);
      //digitalWrite(motor1pin2, HIGH);
      //digitalWrite(motor2pin1, LOW);
      //digitalWrite(motor2pin2, HIGH);
    
    //} else if (colors3 > 50) {
      //if(colors1 < 50) {
          //digitalWrite(motor1pin1, LOW);
          //digitalWrite(motor1pin2, LOW);
          //digitalWrite(motor2pin1, LOW);
          //digitalWrite(motor2pin2, HIGH);
        
        
        //} else if(colors5 < 50) {
            //digitalWrite(motor1pin1, LOW);
            //digitalWrite(motor1pin2, HIGH);
            //digitalWrite(motor2pin1, LOW);
            //digitalWrite(motor2pin2, LOW);
            //Serial.println("RIGHT BLACK");
          //} else {
            //digitalWrite(motor1pin1, LOW);
            //digitalWrite(motor1pin2, LOW);
            //digitalWrite(motor2pin1, LOW);
            //digitalWrite(motor2pin2, LOW);            
//}
//}
}
