#include <PS2Keyboard.h>

const int DataPin = 9;
const int IRQpin =  3;

#define pot A3

#define zampaAS 3
#define zampaAD 6
#define zampaPS 7
#define zampaPD 8

#define piede 4
#define tamburo A1

PS2Keyboard keyboard;

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

}

void loop() {
  if (keyboard.available()) {
    
    char c = keyboard.read();

    if (c == PS2_LEFTARROW) {
      digitalWrite
    } else if (c == PS2_RIGHTARROW) {
      Serial.print("[Right]");
    } else if (c == PS2_UPARROW) {
      Serial.print("[Up]");
    } else if (c == PS2_DOWNARROW) {
      Serial.print("[Down]");
    }
    
    
    }

  else {
    if ((millis() - t1) > tempo) {
      digitalWrite(2,LOW);
    }
    if ((millis() - t2) > tempo) {
      digitalWrite(4,LOW);
    }
    if ((millis() - t3) > tempo) {
      digitalWrite(5,LOW);
    }
    if ((millis() - t4) > tempo) {
      digitalWrite(6,LOW);
    }
    if ((millis() - t5) > tempo) {
      digitalWrite(7,LOW);
    }
    if ((millis() - t6) > tempo) {
      digitalWrite(8,LOW);
    }
    if ((millis() - t7) > tempo) {
      digitalWrite(A0,LOW);
    }
    if ((millis() - t8) > tempo) {
      digitalWrite(A1,LOW);
    }
    if ((millis() - t9) > tempo) {
      digitalWrite(A2,LOW);
    }
    if ((millis() - t0) > tempo) {
      digitalWrite(A3,LOW);
    }
  }
}
