#include <PS2Keyboard.h>

const int DataPin = 9;
const int IRQpin =  3;

#define pot A3

PS2Keyboard keyboard;

long t1 = 0;
long t2 = 0;
long t3 = 0;
long t4 = 0;
long t5 = 0;
long t6 = 0;
long t7 = 0;
long t8 = 0;
long t9 = 0;
long t0 = 0;

int tempo = 0;

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");

  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(A0,OUTPUT);
  pinMode(A1,OUTPUT);

  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(A0,LOW);
  digitalWrite(A1,LOW);

}

void loop() {
  tempo = map(analogRead(pot),0,1023,50,200);

  if (keyboard.available()) {

    char c = keyboard.read();
    
    Serial.println(c);


}
