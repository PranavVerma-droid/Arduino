//Code Written by PranavVerma-droid
//Comments Written by ChatGPT.

/* Tips for PID Calibration by ChatGPT:
-   Start with a small Kp value and increase it until the robot starts following the line with some oscillation.
-   Gradually increase the Kd value to reduce the oscillations.
-   Fine-tune both values to achieve smooth line-following behavior. */

#include <QTRSensors.h>

#define Kp 0 // Proportional gain, experiment to find a suitable value
#define Kd 0 // Derivative gain, experiment to find a suitable value (Note: Kp < Kd) 

#define rightMaxSpeed 200 // Max speed for the right motor
#define leftMaxSpeed 200 // Max speed for the left motor
#define rightBaseSpeed 150 // Base speed for the right motor when the robot is on the line
#define leftBaseSpeed 150  // Base speed for the left motor when the robot is on the line

#define NUM_SENSORS  8     // Number of sensors used
#define TIMEOUT      2500  // Timeout for sensors to be considered low
#define EMITTER_PIN  2     // Pin for emitter

#define rightMotor1 3      // Right motor control pin 1
#define rightMotor2 4      // Right motor control pin 2
#define rightMotorPWM 5    // Right motor PWM pin
#define leftMotor1 12      // Left motor control pin 1
#define leftMotor2 13      // Left motor control pin 2
#define leftMotorPWM 11    // Left motor PWM pin
#define motorPower 8       // Motor power control pin

QTRSensors qtrrc;
unsigned int sensorValues[NUM_SENSORS];

void setup() {
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  pinMode(rightMotorPWM, OUTPUT);
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(leftMotorPWM, OUTPUT);
  pinMode(motorPower, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(motorPower, LOW);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(9600);

  qtrrc.setTypeAnalog();
  qtrrc.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, NUM_SENSORS);
  qtrrc.setEmitterPin(EMITTER_PIN); 

  // Calibrate sensors
  for (int i = 0; i < 100; i++) {
    qtrrc.calibrate();
    delay(20);
  }

  digitalWrite(motorPower, LOW);
  delay(2000);

  
  // Debugging
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibrationOn.minimum[i]);
    Serial.print(' '); 
  }
  Serial.println();

  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(qtrrc.calibrationOn.maximum[i]);
    Serial.print(' '); 
  }
  Serial.println();
  Serial.println();
}

int lastError = 0;

void loop() {
  unsigned int sensors[NUM_SENSORS];
  int position = qtrrc.readLineBlack(sensors);
  int error = position - 3500;

  int motorSpeed = Kp * error + Kd * (error - lastError);
  lastError = error;

  int rightMotorSpeed = rightBaseSpeed + motorSpeed;
  int leftMotorSpeed = leftBaseSpeed - motorSpeed;

  // Constrain motor speeds to valid range
  rightMotorSpeed = constrain(rightMotorSpeed, 0, rightMaxSpeed);
  leftMotorSpeed = constrain(leftMotorSpeed, 0, leftMaxSpeed);

  // Motor Speeds
  digitalWrite(motorPower, HIGH);
  
  digitalWrite(rightMotor1, HIGH);
  digitalWrite(rightMotor2, LOW);
  analogWrite(rightMotorPWM, rightMotorSpeed);
  digitalWrite(leftMotor1, HIGH);
  digitalWrite(leftMotor2, LOW);
  analogWrite(leftMotorPWM, leftMotorSpeed);
}

void wait() {
  
}

void autoPID() {
  //WIP
}

void waiting(){
  
}
