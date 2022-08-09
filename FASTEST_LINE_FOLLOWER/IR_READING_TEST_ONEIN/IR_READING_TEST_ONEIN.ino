
const int s3 = A3;



int colors3 = 0;


void setup() {
   
    pinMode(s3, INPUT);

  
    Serial.begin(9600);
}



void loop() {

    colors3 = analogRead(s3);



    Serial.print("Middle Sensor: ");
    Serial.println(colors3);


    Serial.println("");


    delay(1000);
}
