int x = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  x = digitalRead(5);
     if(x == HIGH) {
      Serial.println("HIGH");
    
    }else {
      Serial.println("LOW");
      }
}
