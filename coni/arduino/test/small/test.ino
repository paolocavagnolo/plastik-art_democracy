#include <SoftwareSerial.h>
#include <AccelStepper.h>

#define pinRX 11
#define pinTX 12

//MOTORE STRETTO - A
#define pinStep_A 4 		//bianco
#define pinDirection_A 5 	//giallo
#define pinSens_A A2

//MOTORE LARGO
#define pinStep_B 9 		//bianco
#define pinDirection_B 10 	//giallop
#define pinSens_B A0

#define RE 6
#define DE 7

#define MAXSPEED 6000
#define MAXACC 1500

SoftwareSerial mySerial(pinRX, pinTX);
AccelStepper stepper_A(1, pinStep_A, pinDirection_A); 
AccelStepper stepper_B(1, pinStep_B, pinDirection_B); 

uint32_t velA = 1000;
uint32_t velB = 1000;
long posA = 0;
long posB = 0;
uint32_t dataIn = 0;

void setup() {
  mySerial.begin(4800);

  stepper_A.setMaxSpeed(MAXSPEED);
  stepper_B.setMaxSpeed(MAXSPEED);
  stepper_A.setAcceleration(MAXACC);
  stepper_B.setAcceleration(MAXACC);

  //200 step per rev
  //
  pinMode(pinSens_A, INPUT_PULLUP);
  pinMode(pinSens_B, INPUT_PULLUP);

  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  digitalWrite(RE, LOW);
  digitalWrite(DE, LOW);

  //Serial.begin(9600);
  //zeros_A();
  //zeros_B();
}

/*
399200  500000  600800    posA
		1000000   		  velA
2399200 2500000 2600800   posB
		3000000   		  velB
*/

void loop() {
  if (mySerial.available()) {
    dataIn = mySerial.parseInt();
    if (dataIn < 1000000) {
      posA = dataIn - 500000;
      stepper_A.moveTo(posA);
      //Serial.print("posA");
      //Serial.println(posA);
    }
    else if ((dataIn >= 1000000) && (dataIn < 2000000)) {
      velA = dataIn - 1000000;
      //Serial.print("velA");
      //Serial.println(velA);
    }
    else if ((dataIn >= 2000000) && (dataIn < 3000000)) {
      posB = dataIn - 2500000;

      //Serial.print("posB");
      //Serial.println(posB);
    }
    else if ((dataIn >= 3000000) && (dataIn < 4000000)) {
      velB = dataIn - 3500000;
      //Serial.print("velB");
      //Serial.println(velB);
    }

    else if ((dataIn >= 4000000) && (dataIn < 5000000)) {
      stepper_A.setMaxSpeed(dataIn - 4000000);
      stepper_A.setAcceleration(dataIn - 4000000);
    }

    else if ((dataIn >= 5000000) && (dataIn < 6000000)) {
      stepper_B.setMaxSpeed(dataIn - 5000000);
      stepper_B.setAcceleration(dataIn - 5000000);
    }
    else if ((dataIn >= 6000000) && (dataIn < 7000000)) {
      zeros_A();
    }
    else if ((dataIn >= 7000000) && (dataIn < 8000000)) {
      zeros_B();
    }

    stepper_B.moveTo(posB);
    stepper_A.moveTo(posA);
  }
  stepper_A.run();
  stepper_B.run();
}

zeros_A() {
  
}

zeros_B() {

}

