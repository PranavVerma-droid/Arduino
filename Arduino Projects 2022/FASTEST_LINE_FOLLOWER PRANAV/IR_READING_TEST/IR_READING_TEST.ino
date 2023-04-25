const int s1 = A5;
const int s2 = A4;
const int s3 = A3;
const int s4 = A2;
const int s5 = A1;

int colors1 = 0;
int colors2 = 0;
int colors3 = 0;
int colors4 = 0;
int colors5 = 0;

void setup() {
    pinMode(s1, INPUT);
    pinMode(s2, INPUT);
    pinMode(s3, INPUT);
    pinMode(s4, INPUT);
    pinMode(s5, INPUT);
  
    Serial.begin(9600);
}



void loop() {
    colors1 = analogRead(s1);
    colors2 = analogRead(s2);
    colors3 = analogRead(s3);
    colors4 = analogRead(s4);
    colors5 = analogRead(s5);

    Serial.print("Most Right Sensor: ");
    Serial.println(colors5);

    Serial.print("Right Sensor: ");
    Serial.println(colors4);

    Serial.print("Middle Sensor: ");
    Serial.println(colors3);

    Serial.print("Left Sensor: ");
    Serial.println(colors2);

    Serial.print("Most Left Sensor: ");
    Serial.println(colors1);
    
    Serial.println("");


    delay(1000);
}
