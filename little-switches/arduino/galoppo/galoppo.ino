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

#define pausaAppoggio 75
#define pausaAllungo 150
#define volo 400

PS2Keyboard keyboard;

long t1 = 0;
long t2 = 0;
long t3 = 0;
long t4 = 0;
long t5 = 0;
long t6 = 0;

int tempo = 78;
float w = 0;

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

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
  w = mapfloat(analogRead(pot)/1.0,0,1023,0.25,3);

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
  int aa = 0;
  long ps,pd,as,ad;
  bool bps = true;
  bool bpd = true;
  bool bas = true;
  bool bad = true;


  bool fine=false;
  long ii = millis();
  while (!fine) {
    if (bps) {
      digitalWrite(zampaPS,HIGH);
      ps = millis();
      bps = false;
    }  
    if (((millis() - ii) > (pausaAppoggio*v)) && bpd)  {
      digitalWrite(zampaPD,HIGH);
      pd = millis();
      bpd = false;
    }
    if (((millis() - ii) > (pausaAppoggio+pausaAllungo*v)) && bas) {
      digitalWrite(zampaAS,HIGH);
      as = millis();
      bas = false;
    }
    if ((millis() - ii) > (pausaAppoggio+pausaAllungo+pausaAppoggio*v)) && bad) {
      digitalWrite(zampaAD,HIGH);
      ad = millis();
      bad = false;
    }

    if ((millis() - ii) > ((ps+volo)*v)) {
      digitalWrite(zampaPS,LOW);
    } 
    if ((millis() - ii) > ((pd+volo)*v)) {
      digitalWrite(zampaPD,LOW);
    }
    if ((millis() - ii) > ((as+volo)*v)) {
      digitalWrite(zampaAS,LOW);
    }
    if ((millis() - ii) > ((ad+volo)*v)) {
      digitalWrite(zampaAD,LOW);
      ii = millis();
      bps = true;
      bpd = true;
      bas = true;
      bad = true;  
      aa++;
    }

    if (aa > 10) {
      fine = true;
    }

  }
}
