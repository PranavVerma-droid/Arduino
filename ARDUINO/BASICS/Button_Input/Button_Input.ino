// Complete Instructions: https://RandomNerdTutorials.com/esp8266-nodemcu-digital-inputs-outputs-arduino/

// set pin numbers
const int buttonPin = 4;     // the number of the pushbutton pin

// variable for storing the pushbutton status
int buttonState = 0;

void setup() {
  // initialize the pushbutton pin as an input
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    Serial.println("Button Pressed");
    delay(1000);
  } else {
    // turn LED off
    Serial.println("Released");
    delay(1000);
  }
}
