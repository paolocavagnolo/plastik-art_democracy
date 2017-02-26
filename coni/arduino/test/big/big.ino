#include <AccelStepper.h>

AccelStepper stepper; 

#define ANALOG_IN A0

void setup()
{  
  stepper.setMaxSpeed(1000);
}
void loop()
{
  // Read new position
  int analog_in = analogRead(ANALOG_IN);
  stepper.moveTo(analog_in);
  stepper.setSpeed(100);
  stepper.runSpeedToPosition();
}

#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 12); // RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySerial.begin(4800);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}

