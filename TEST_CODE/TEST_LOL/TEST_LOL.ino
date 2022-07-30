#include <ArduinoOTA.h>

int cv1 = 3;
int cv2 = 4;
int cv3 = 5;
int cv4 = 6;
int cv5 = 8;
int cv6 = 9;

int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(cv1, INPUT);
  pinMode(cv2, INPUT);
  pinMode(cv3, INPUT);
  pinMode(cv4, INPUT);
  pinMode(cv5, INPUT);
  pinMode(cv6, INPUT);
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {
  a = digitalRead(cv1);
  b = digitalRead(cv1);
  c = digitalRead(cv1);
  d = digitalRead(cv1);
  e = digitalRead(cv1);
  f = digitalRead(cv1);
  
  //IR SENSORS DETECT LOW AS INPUT = TRUE
  //IR SENSORS DETECT HIGH AS INPUT = FALSE
  
  //a - sensor in the front
  //f - sensor in the back
  if(a == LOW) {
    //MOTOR RUN CODE GOES HERE
    }
  if(a == HIGH) {
    if(f == LOW) {
      //DETECT SENSORS FROM RIGHT & LEFT SENSORS
      //IN THIS CASE, RIGHT = b, LEFT = c

      if(b == LOW) {
        //MOVE TO LEFT
        } else if(c == LOW){
          //MOVE TO RIGHT
          } else {
            //ERROR.STOPCODE goes here
            }
      }
    }

}
