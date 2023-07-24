void setup() {
  Serial.begin(9600);// setup Serial Monitor to display information
  pinMode(2, INPUT);// Input from sensor
  pinMode(8, OUTPUT);// OUTPUT to alarm or LED
}

void loop() {
  int motion =digitalRead(2);
  if(motion){
    Serial.println("Motion detected");
    digitalWrite(8,HIGH);
  }else{
     Serial.println("nothing moves");
     digitalWrite(8,LOW);
  }
  delay(500);

}
