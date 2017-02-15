#include <PS2Keyboard.h>

#define DATAPIN 9
#define IRQPIN  3
#define tambPin 2
#define piedePin 4
#define suPin 5
#define sxPin 6
#define dxPin 7
#define giuPin 8


uint16_t c;

PS2KeyAdvanced keyboard;


void setup()
{
  // Configure the keyboard library
  keyboard.begin( DATAPIN, IRQPIN );
  Serial.begin( 115200 );
  pinMode(tambPin, OUTPUT);
  pinMode(piedePin, OUTPUT);
  pinMode(suPin, OUTPUT);
  pinMode(sxPin, OUTPUT);
  pinMode(dxPin, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
}



void loop()
{
  if ( keyboard.available() )
  {
    // read the next key
    c = keyboard.read();
    if (c == 84) {
      digitalWrite(tambPin, HIGH);
    }
    else if (c == 32852) {
      digitalWrite(tambPin, LOW);
    }
    else if (c == 80) {
      digitalWrite(piedePin, HIGH);
    }
    else if (c == 32848) {
      digitalWrite(piedePin, LOW);
    }
    else if (c == 279) {
      digitalWrite(suPin, HIGH);
    }
    else if (c == 33047) {
      digitalWrite(suPin, LOW);
    }
    else if (c == 278) {
      digitalWrite(dxPin, HIGH);
    }
    else if (c == 33046) {
      digitalWrite(dxPin, LOW);
    }
    else if (c == 280) {
      digitalWrite(giuPin, HIGH);
    }
    else if (c == 33048) {
      digitalWrite(giuPin, LOW);
    }
    else if (c == 277) {
      digitalWrite(sxPin, HIGH);
    }
    else if (c == 33045) {
      digitalWrite(sxPin, LOW);
    }
  }
}
