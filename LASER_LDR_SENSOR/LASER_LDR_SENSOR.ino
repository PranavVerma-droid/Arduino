int laserinput = A0;
int x = 0;
int buzzerpin = 3;

int relaypin = 12;

bool buzzer = false;

void setup() {
  pinMode(laserinput, INPUT);
  pinMode(buzzerpin, OUTPUT);
  pinMode(buzzerpin, OUTPUT);
  Serial.begin(9600);
  buzzer = false;
  digitalWrite(buzzerpin, LOW);
}

void loop() {
  x = analogRead(laserinput);
  Serial.println(x);
  //delay(1000);

  if(x <= 200) {
    buzzer = true;
    }
  
  if(buzzer == true) {
    digitalWrite(buzzerpin, HIGH);
    delay(1000);
    digitalWrite(buzzerpin, LOW);
    delay(500);
    }
}