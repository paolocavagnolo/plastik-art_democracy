#include <PS2Keyboard.h>

const int DataPin = 9;
const int IRQpin =  3;

#define pot A3

#define zampaAS 8
#define zampaAD 6
#define zampaPS 7
#define zampaPD 5

#define piede A0
#define tamburo 2

PS2Keyboard keyboard;

long t1 = 0;
long t2 = 0;
long t3 = 0;
long t4 = 0;
long t5 = 0;
long t6 = 0;

int tempo = 0;
float w = 0;

void setup() {
  delay(1000);
  keyboard.begin(DataPin, IRQpin);
  Serial.begin(9600);
  Serial.println("Keyboard Test:");

  pinMode(zampaAS,OUTPUT);
  pinMode(zampaAD,OUTPUT);
  pinMode(zampaPS,OUTPUT);
  pinMode(zampaPD,OUTPUT);

  pinMode(piede,OUTPUT);
  pinMode(tamburo,OUTPUT);

  digitalWrite(zampaAS,LOW);
  digitalWrite(zampaAD,LOW);
  digitalWrite(zampaPS,LOW);
  digitalWrite(zampaPD,LOW);

  digitalWrite(piede,LOW);
  digitalWrite(tamburo,LOW);

}

void loop() {
  w = map(analogRead(pot),0,1023,0.25,3);

  Serial.print("weight: ");
  Serial.println(w);

  if (keyboard.available()) {
    
    char c = keyboard.read();

    if (c == '1') {
      galoppo(w);
    } 
    else if (c == 'p') {
      digitalWrite(piede,HIGH);
      t5 = millis();
    } 
    else if (c == 't') {
      digitalWrite(tamburo,HIGH);
      t6 = millis();
    }
       
  }

  else {
    if ((millis() - t5) > tempo) {
      digitalWrite(piede,LOW);
    }
    if ((millis() - t5) > tempo) {
      digitalWrite(piede,LOW);
    }
    if ((millis() - t6) > tempo) {
      digitalWrite(tamburo,LOW);
    }
  }
}

void galoppo(float v) {
  bool fine=false;
  long ii = millis();
  while (!fine) {
    digitalWrite(zampaPS,HIGH);
    if ((millis() - ii) > (300*v) {
      digitalWrite(zampaPS,LOW);
    } 

    if ((millis() - ii) > (75*v)) {
      digitalWrite(zampaPD,HIGH);
    }
    if ((millis() - ii) > (375*v)) {
      digitalWrite(zampaPD,LOW);
    }

    if ((millis() - ii) > (150*v)) {
      digitalWrite(zampaAS,HIGH);
    }
    if ((millis() - ii) > (450*v)) {
      digitalWrite(zampaAS,HIGH);
    }

    if ((millis() - ii) > (225*v)) {
      digitalWrite(zampaAD,HIGH);
    }
    if ((millis() - ii) > (525*v)) {
      digitalWrite(zampaAD,HIGH);
      fine = true;
    }

  }
}
