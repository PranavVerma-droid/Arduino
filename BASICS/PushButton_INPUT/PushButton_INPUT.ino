const int buttonPin = 4;
int led = 5;
int buttonState = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) { 
   digitalWrite(led, HIGH); 
   Serial.println("LED ON");
   delay(1000); }
  
  if (buttonState == LOW) {
    digitalWrite(led, LOW);
    Serial.println("LED OFF");
    delay(1000); }

}
