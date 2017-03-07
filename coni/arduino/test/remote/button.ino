#define MAINSW 12 //1 su 0 e 0 su 1
#define SEL_A 28 //0 su 1
#define SEL_B 31 //0 su 2
#define BT_A A14 //0 premuto
#define BT_B A8 //1 premuto
#define SEL_Gp A5 //0 su G e 1 su p

long muovi(char let, int vel, int posA, int posB, int posC = 0);
long t0 = 0;
long dd = 100;
long tdd = 0;

uint8_t channels[16] = {53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38};

void setup() {
  pinMode(MAINSW, INPUT_PULLUP);
  pinMode(SEL_A, INPUT_PULLUP);
  pinMode(SEL_B, INPUT_PULLUP);
  pinMode(BT_A, INPUT_PULLUP);
  pinMode(BT_B, INPUT_PULLUP);
  pinMode(SEL_Gp, INPUT_PULLUP);

  Serial.begin(9600);

  Serial2.begin(4800);
}

int act = 0;
long att1 = 0;
long att2 = 0;
bool inviatoG = false;
bool inviatop = false;

void loop() {
  while (digitalRead(MAINSW)) //SHOW
  {
    if (act == 0) {
      t0= millis();
      Serial.println("ACT 0");
      inviatop = false;
      inviatoG = false;
      act++;
    }
    show_uno();
  }
  while (!digitalRead(MAINSW)) //TEST
  {
    act = 0;

    if (Serial.available() > 0) {
      Serial2.write(Serial.read());
    }

    if ((digitalRead(SEL_A) == 0) && (digitalRead(SEL_B) == 1)) //A
    {
      if (digitalRead(BT_A) == 0)  //premuto
      {
        if (digitalRead(SEL_Gp)) //1 è piccolo
        {
          Serial.println("motore A orario");
          ///////////////////////////
          Serial2.print("P 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("p 10 0");
          Serial2.print('\r');
        }
        else
        {
          Serial.println("motore C orario");
          Serial2.print("G 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("g 10 0 0");
          Serial2.print('\r');
          ////////////////////////////
        }
        delay(1000);
      }
      else if (digitalRead(BT_B) == 1)  //premuto
      {
        if (digitalRead(SEL_Gp)) //1 è piccolo
        {
          Serial.println("motore A antiorario");
          ///////////////////////////
          Serial2.print("P 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("p -10 0");
          Serial2.print('\r');
        }
        else
        {
          Serial.println("motore C antiorario");
          Serial2.print("G 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("g -10 0 0");
          Serial2.print('\r');
          ////////////////////////////
        }
        delay(1000);
      }
    }
    else if ((digitalRead(SEL_A) == 1) && (digitalRead(SEL_B) == 1)) //B
    {
      if (digitalRead(BT_A) == 0)  //premuto
      {
        if (digitalRead(SEL_Gp)) //1 è piccolo
        {
          Serial.println("motore B orario");
          ///////////////////////////
          Serial2.print("P 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("p 0 10");
          Serial2.print('\r');
        }
        else
        {
          Serial.println("motore D orario");
          Serial2.print("G 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("g 0 -10 0");
          Serial2.print('\r');
          ////////////////////////////
        }
        delay(1000);
      }
      else if (digitalRead(BT_B) == 1)  //premuto
      {
        if (digitalRead(SEL_Gp)) //1 è piccolo
        {
          Serial.println("motore B antiorario");
          ///////////////////////////
          Serial2.print("P 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("p 0 -10");
          Serial2.print('\r');
        }
        else
        {
          Serial.println("motore D antiorario");
          Serial2.print("G 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("g 0 10 0");
          Serial2.print('\r');
          ////////////////////////////
        }

        delay(1000);
      }
    }
    else if ((digitalRead(SEL_A) == 1) && (digitalRead(SEL_B) == 0)) //C
    {
      if (digitalRead(BT_A) == 0)  //premuto
      {
        if (digitalRead(SEL_Gp)) //1 è piccolo
        {
          Serial.println("motore inesistente");
        }
        else
        {
          Serial.println("motore E orario");
          Serial2.print("G 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("g 0 0 10");
          Serial2.print('\r');
          ////////////////////////////
        }
        delay(1000);
      }
      else if (digitalRead(BT_B) == 1)  //premuto
      {
        if (digitalRead(SEL_Gp)) //1 è piccolo
        {
          Serial.println("motore inesistente");
        }
        else
        {
          Serial.println("motore E antiorario");

          Serial2.print("G 3000");
          Serial2.print('\r');
          delay(100);
          Serial2.print("g 0 0 -10");
          Serial2.print('\r');
          ////////////////////////////
        }
        delay(1000);
      }
    }
  }
}

void attore(int scena,char let_G, int vel_G, int posG_a, int posG_b, int posG_c, char let_p, int vel_p, int posp_a, int posp_b, int pausa) {

  if (act == scena) {
    if (inviatoG == false) {
      att1 = muovi(let_G,vel_G,posG_a,posG_b,posG_c);
      digitalWrite(channels[act], HIGH);
      inviatoG = true;
      tdd = millis();
    }
    if ((inviatop == false) && ((long)(millis() - tdd) > dd)) {
      att2 = muovi(let_p,vel_p,posp_a,posp_b);
      inviatop = true;
    }
    if ((long)(millis() - t0) > (long)(magg(att1,att2) + pausa)) {
      inviatop = false;
      inviatoG = false;
      digitalWrite(channels[act], LOW);
      t0 = millis();
      Serial.println(act);
      act++;
    }
  }
}

void show_uno() {

  // attore(1,'g',2000, 0,  0,  0, 'p',2000, 0, 0,  8000); //def
  //
  // //intro
  // attore(2,'g',2000, -180,  -180,  180, 'p',2000, -150, 180,  8000); //def
  // attore(3,'g',2000, 0,  -180,  -180, 'p',2500, 150, -180,  8000); //def
  // attore(4,'g',2000, 0,  80,  110, 'p',3400, -130, 180,  8000); //def
  // attore(5,'g',3000, 180,  -250,  -110, 'p',1800, 130, -180,  8000); //def

  //dance
  // attore(6,'g',4000, -640,  300,  -720, 'p',0, 0, 0,  10000); //def
  // attore(1,'g',4000, 110,  -310,  -190, 'p',0, 0, 0,  6000); //def

  //outro
  attore(1,'g',2000, 180,  170,  180, 'p',0, 0, 0,  6000); //def
  //

}

void show_def() {

  //intro
  attore(1,'g',2000, -180,  -180,  180, 'p',3000, -240, 180,  2000); //def
  attore(2,'g',2000, 0,  -180,  -180, 'p',2000, 240, -180,  2000); //def
  attore(3,'g',2000, 0,  80,  110, 'p',3000, -130, 180,  2000); //def
  attore(4,'g',2800, 180,  -80,  -110, 'p',2800, 130, -180,  2000); //def

  //dance
  attore(5,'g',4000, -720,  -90,  -720, 'p',4000, 720, 720,  2000); //def
  attore(6,'g',4000, 720,  90,  720, 'p',4000, -720, -720,  2000); //def

}

long magg(long a, long b) {
  if (a >= b) {
    return a;
  }
  else {
    return b;
  }
}

long muovi(char let, int vel, int posA, int posB, int posC = 0) {
  String payload = "";

  if (let == 'p') {
    char LET = 'P';

    payload = "";

    payload += LET;
    payload += " ";
    payload += String(vel);
    payload += '\r';

    Serial2.print(payload);

    payload = "";

    payload += let;
    payload += " ";
    payload += String(posA);
    payload += " ";
    payload += String(posB);
    payload += '\r';

    Serial2.print(payload);

  }
  else if (let == 'g') {
    char LET = 'G';

    payload = "";

    payload += LET;
    payload += " ";
    payload += String(vel);
    payload += '\r';

    Serial2.print(payload);

    payload = "";

    payload += let;
    payload += " ";
    payload += String(posA);
    payload += " ";
    payload += String(posB);
    payload += " ";
    payload += String(posC);
    payload += '\r';

    Serial2.print(payload);
  }

  int maxx = 0;
  if (abs(posA) >= abs(posB)) {
    if (abs(posA) >= abs(posC)) {
      maxx = abs(posA);
    }
    else {
      maxx = abs(posC);
    }
  }
  else {
    if (abs(posB) >= abs(posC)) {
      maxx = abs(posB);
    }
    else {
      maxx = abs(posC);
    }
  }



  return ((maxx * 100800 / 360) / vel) * 1000;


}
