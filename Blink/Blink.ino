const int led = 43;

void setup() {
 
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(led, HIGH);
  Serial.println("LED TURNED ON");
  Serial.println("");
  delay(1000);                       // wait for a second
  
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(led, LOW);
  Serial.println("LED TURNED OFF");
  Serial.println("");
  delay(1000);  
}
