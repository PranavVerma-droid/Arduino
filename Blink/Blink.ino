int led = 43;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led, OUTPUT)
}
  

void loop() {
  digitalWrite(led,HIGH);
  digitalWrite(LED_BUILTIN, HIGH);

  delay(1000);

  digitalWrite(led,LOW);
  digitalWrite(LED_BUILTIN,LOW);

  delay(1000);


}