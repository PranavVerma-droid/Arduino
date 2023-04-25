int motor1pin1 = 3;
int motor1pin2 = 5;
int motor2pin1 = 6;
int motor2pin2 = 9;

int s1 = A5;
int s2 = A4;
int s3 = A3;
int s4 = A2;
int s5 = A1;

int colors1 = 0;
int colors2 = 0;
int colors3 = 0;
int colors4 = 0;
int colors5 = 0;

int counter = 0;

void setup() {
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT); 
  pinMode(motor2pin1, OUTPUT); 
  pinMode(motor2pin2, OUTPUT);

  pinMode(s1, INPUT);
  pinMode(s2, INPUT); 
  pinMode(s3, INPUT); 
  pinMode(s4, INPUT);
  pinMode(s5, INPUT); 

  Serial.begin(9600);
  
}

void forward() {
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 120);
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 120);
  //Serial.println("FORWARD");
  }

void backward() {

  analogWrite(motor1pin1, 120);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin1, 120);
  analogWrite(motor2pin2, 0);

  }

void left() { 
  analogWrite(motor1pin1, 120);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 120);
 
  }

void right() {
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 120);
  analogWrite(motor2pin1, 120);
  analogWrite(motor2pin2, 0);

  }

void stop() {
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 0);

}

void mediumLeft(){
  analogWrite(motor1pin1, 100);
  analogWrite(motor1pin2, 0);
  analogWrite(motor2pin1, 0);
  analogWrite(motor2pin2, 100);
}

void mediumRight(){
  analogWrite(motor1pin1, 0);
  analogWrite(motor1pin2, 100);
  analogWrite(motor2pin1, 100);
  analogWrite(motor2pin2, 0);
}

void loop() {
    colors1 = analogRead(s1);
    colors2 = analogRead(s2);
    colors3 = analogRead(s3);
    colors4 = analogRead(s4);
    colors5 = analogRead(s5);

    Serial.println(counter);

    if(colors3<100){
      forward();
    }
    
    
   if( colors4<100 ){
      delay(10);
      right();
    }
  if(colors2<100){
      delay(10);
      left();
  }

  if(colors3>100 && colors4>100 && colors5>100){
    stop();
  }
  
}