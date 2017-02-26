#include <AccelStepper.h>
#include <SoftwareSerial.h>

#define RXpin 11
#define TXpin 12

#define pinStep_A 9
#define pinDirection_A 10

#define pinStep_B 3
#define pinDirection_B 4

#define pinSens_A A0
#define pinSens_B A5

#define RE 6
#define DE 7

SoftwareSerial mySerial(pinRX, pinTX);
AccelStepper stepper_A(1, pinStep_A, pinDirection_A); 
AccelStepper stepper_B(1, pinStep_B, pinDirection_B); 

uint32_t dataIn = 0;

void setup()
{  
  mySerial.begin(4800);

  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  digitalWrite(RE, LOW);
  digitalWrite(DE, LOW);

  //200 step per rivoluzione
  //1600 pulse per rivoluzione

  stepper_A.setMaxSpeed(1000);
  stepper_A.setAcceleration(1000);

  goToZero();

}

void loop()
{
  if (mySerial.available()) {
    dataIn = mySerial.parseInt();
    if (dataIn > 5000) {
    	distance = dataIn *;
    	velocity = dataIn *;
    }
  }
  
  stepper.moveTo(distance);
  stepper.setSpeed(velocity);
  stepper.runSpeedToPosition();

  
}

void goToZero() {
	while (analogRead(pinSens_A) > 0)
}
