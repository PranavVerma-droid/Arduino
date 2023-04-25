int ir = 10;
int x = 0;

void setup() {
  pinMode(ir,INPUT);
  pinMode(11,OUTPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(11,LOW);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
   x = digitalRead(ir);
   if(x == HIGH) {
      digitalWrite(11,LOW);
      digitalWrite(LED_BUILTIN,LOW);
    }else {
      digitalWrite(11,HIGH);
      digitalWrite(LED_BUILTIN,HIGH);
      }

}
