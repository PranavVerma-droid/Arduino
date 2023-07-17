int led = 43;
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(led,OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN,HIGH);
  
  digitalWrite(led,HIGH);

  delay(1000);

  digitalWrite(LED_BUILTIN,LOW);
  
  digitalWrite(led,LOW);
  //delay adding fo

  delay(1000);
  //helpful for many reasons ofc llol
}