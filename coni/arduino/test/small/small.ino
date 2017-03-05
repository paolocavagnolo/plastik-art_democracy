#include <SoftwareSerial.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#include <SerialCommand.h>


SerialCommand SCmd;


#define pinRX 11
#define pinTX 12

//MOTORE STRETTO
#define pinStep_A 4        //bianco
#define pinDirection_A 5   //giallo
#define pinSens_A A2

//MOTORE LARGO
#define pinStep_B 9         //bianco
#define pinDirection_B 10   //giallop
#define pinSens_B A0

#define RE 6
#define DE 7

#define MAXSPEED 5000
#define MAXACC 800

AccelStepper stepper_A(1, pinStep_A, pinDirection_A);
AccelStepper stepper_B(1, pinStep_B, pinDirection_B);

MultiStepper steppers;

long posA = 0;
long posB = 0;

long positions[2] = {0,0};

uint32_t velA = 1000;
uint32_t velB = 1000;

uint32_t dataIn = 0;

void setup() {

  SCmd.addCommand("p",process_command);
  SCmd.addCommand("P",Process_command);

  stepper_A.setMaxSpeed(MAXSPEED);
  stepper_B.setMaxSpeed(MAXSPEED);
  stepper_A.setAcceleration(MAXACC);
  stepper_B.setAcceleration(MAXACC);

  steppers.addStepper(stepper_A);
  steppers.addStepper(stepper_B);

  //200 step per rev  (motor)
  //1600 pulse per rev (driver)
  pinMode(pinSens_A, INPUT_PULLUP);
  pinMode(pinSens_B, INPUT_PULLUP);

  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  digitalWrite(RE, LOW);
  digitalWrite(DE, LOW);

  Serial.begin(9600);

}


void loop() {
  SCmd.readSerial();
  steppers.moveTo(positions);
  steppers.runSpeedToPosition();

}

void process_command()
{
  int aNumber;
  char *arg;

  Serial.println("We're in process_command");
  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    positions[0] += (long)(aNumber * 100800 / 360);
    Serial.print("First argument was: ");
    Serial.println(positions[0]);

  }
  else {
    Serial.println("No arguments");
  }

  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);
    positions[1] += (long)(aNumber * 100800 / 360);
    Serial.print("Second argument was: ");
    Serial.println(positions[1]);


  }
  else {
    Serial.println("No second argument");
  }

}

void Process_command()
{
  int aNumber;
  char *arg;

  Serial.println("We're in process_command");
  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);    // Converts a char string to an integer
    stepper_A.setMaxSpeed(aNumber);
    Serial.print("Second argument was: ");
    Serial.println(aNumber);

  }
  else {
    Serial.println("No arguments");
  }

  arg = SCmd.next();
  if (arg != NULL)
  {
    aNumber=atoi(arg);
    stepper_B.setMaxSpeed(aNumber);
    Serial.print("Second argument was: ");
    Serial.println(aNumber);


  }
  else {
    Serial.println("No second argument");
  }

}
