const int s1 = A1;
const int s2 = A1;
const int s3 = A1;
const int s4 = A1;
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
  

}



void loop() {
    colors1 = analogRead(s1);
    colors2 = analogRead(s2);
    colors3 = analogRead(s3);
    colors4 = analogRead(s4);
    colors5 = analogRead(s5);


    Serial.print("Right Sensor: ");
    Serial.print(colors4);
    
    Serial.print("Middle Sensor: ");
    Serial.println(colors3);
    
    Serial.print("Left Sensor");
    Serial.print(colors2);
}
