#include <QTRSensors.h>

#define NUM_SENSORS  8     // number of sensors used
#define TIMEOUT       2500  // 2500 sec sensors low
#define EMITTER_PIN   2 // D2 

QTRSensors qtrrc;
unsigned int sensorValues[NUM_SENSORS];

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  qtrrc.setTypeAnalog();
  qtrrc.setSensorPins((const uint8_t[]){A0, A1, A2, A3, A4, A5, A6, A7}, NUM_SENSORS);
  qtrrc.setEmitterPin(EMITTER_PIN);

  Serial.begin(9600);
}

void loop()
{
  qtrrc.read(sensorValues, QTR_EMITTERS_ON); // get the sensor readings
  
  for (int i = 0; i < NUM_SENSORS; i++) {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  Serial.println();
  
  delay(250); // delay for a short while to make the output readable
}
