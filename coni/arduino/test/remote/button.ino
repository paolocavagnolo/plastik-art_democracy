#define MAINSW 12 //1 su 0 e 0 su 1
#define SEL_A 28 //0 su 1
#define SEL_B 31 //0 su 2
#define BT_A A14 //0 premuto
#define BT_B A8 //1 premuto

long muovi(char let, int vel, int posA, int posB, int posC = 0);
long t0 = 0;

void setup() {
  pinMode(MAINSW, INPUT_PULLUP);
  pinMode(SEL_A, INPUT_PULLUP);
  pinMode(SEL_B, INPUT_PULLUP);
  pinMode(BT_A, INPUT_PULLUP);
  pinMode(BT_B, INPUT_PULLUP);

  Serial.begin(9600);

  Serial2.begin(4800);
}

int act = 0;
long att1 = 0;
long att2 = 0;
bool inviato = false;

void loop() {
  while (digitalRead(MAINSW)) //SHOW
  {
    if (act == 0) {
      t0 = millis();
      Serial.println("ACT 0");
      inviato = false;
      act++;
    }
    show();
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
        Serial.println("motore A orario");
        ///////////////////////////
        Serial2.print("P 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("p 10 0");
        Serial2.print('\r');
        delay(100);
        Serial2.print("G 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("g 10 0 0");
        Serial2.print('\r');
        ////////////////////////////
        delay(1000);
      }
      else if (digitalRead(BT_B) == 1)  //premuto
      {
        Serial.println("motore A/C antiorario");
        ///////////////////////////
        Serial2.print("P 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("p -10 0");
        Serial2.print('\r');
        delay(100);
        Serial2.print("G 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("g -10 0 0");
        Serial2.print('\r');
        ////////////////////////////
        delay(1000);
      }
    }
    else if ((digitalRead(SEL_A) == 1) && (digitalRead(SEL_B) == 1)) //B
    {
      if (digitalRead(BT_A) == 0)  //premuto
      {
        Serial.println("motore B/D orario");
        ///////////////////////////
        Serial2.print("P 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("p 0 10");
        Serial2.print('\r');
        delay(100);
        Serial2.print("G 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("g 0 -10 0");
        Serial2.print('\r');
        ////////////////////////////
        delay(1000);
      }
      else if (digitalRead(BT_B) == 1)  //premuto
      {
        Serial.println("motore B/D antiorario");
        ///////////////////////////
        Serial2.print("P 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("p 0 -10");
        Serial2.print('\r');
        delay(100);
        Serial2.print("G 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("g 0 10 0");
        Serial2.print('\r');
        ////////////////////////////
        delay(1000);
      }
    }
    else if ((digitalRead(SEL_A) == 1) && (digitalRead(SEL_B) == 0)) //C
    {
      if (digitalRead(BT_A) == 0)  //premuto
      {
        Serial.println("motore C orario");
        ///////////////////////////
        Serial2.print("P 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("p 0 0");
        Serial2.print('\r');
        delay(100);
        Serial2.print("G 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("g 0 0 10");
        Serial2.print('\r');
        ////////////////////////////
        delay(1000);
      }
      else if (digitalRead(BT_B) == 1)  //premuto
      {
        Serial.println("motore C antiorario");
        ///////////////////////////
        Serial2.print("P 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("p 0 0");
        Serial2.print('\r');
        delay(100);
        Serial2.print("G 3000");
        Serial2.print('\r');
        delay(100);
        Serial2.print("g 0 0 -10");
        Serial2.print('\r');
        ////////////////////////////
        delay(1000);
      }
    }
  }
}

void show() {

  //eppur si muove
  if (act == 1) {
    if (inviato == false) {
      Serial.print("ACT ");
      Serial.print(act);
      Serial.print(" tempo: att1: ");

      att1 = muovi('p',3500,-90,360);

      Serial.print(att1);

      att2 = 0;

      Serial.print(" att2: ");
      Serial.println(att2);

      inviato = true;
    }

    if ((millis() - t0) > magg(att1,att2)) {
      act++;
      inviato = false;
      t0 = millis();
    }
  }

  //ti riconosco
  if (act == 2) {
    if (inviato == false) {
      Serial.print("ACT ");
      Serial.print(act);
      Serial.print(" tempo: att1: ");

      att1 = muovi('p',1500,-90,0);

      Serial.print(att1);

      att2 = muovi('g',1800,90,-100,0);

      Serial.print(" att2: ");
      Serial.println(att2);

      inviato = true;
    }

    if ((millis() - t0) > magg(att1,att2)) {
      act++;
      inviato = false;
      t0 = millis() + 3000;
    }
  }

  //il pubblico
  if (act == 3) {
    if (inviato == false) {
      Serial.print("ACT ");
      Serial.print(act);
      Serial.print(" tempo: att1: ");

      att1 = muovi('p',2000,90,0);

      Serial.print(att1);

      att2 = muovi('g',2000,-90,0,110);

      Serial.print(" att2: ");
      Serial.println(att2);

      inviato = true;
    }

    if ((millis() - t0) > magg(att1,att2)) {
      act++;
      inviato = false;
      t0 = millis() + 5000;
    }
  }

  //più pubblico
  if (act == 4) {
    if (inviato == false) {
      Serial.print("ACT ");
      Serial.print(act);
      Serial.print(" tempo: att1: ");

      att1 = muovi('p',3000,0,90);

      Serial.print(att1);

      att2 = muovi('g',3000,-90,100,0);

      Serial.print(" att2: ");
      Serial.println(att2);

      inviato = true;
    }

    if ((millis() - t0) > magg(att1,att2)) {
      act++;
      inviato = false;
      t0 = millis() + 4000;
    }
  }

  //danza #1
  if (act == 5) {
    if (inviato == false) {
      Serial.print("ACT ");
      Serial.print(act);
      Serial.print(" tempo: att1: ");

      att1 = muovi('p',5000,360,720);

      Serial.print(att1);

      att2 = muovi('g',4800,-630,720,-830);

      Serial.print(" att2: ");
      Serial.println(att2);

      inviato = true;
    }

    if ((millis() - t0) > magg(att1,att2)) {
      act++;
      inviato = false;
      t0 = millis();
    }
  }

  //danza #2
  if (act == 6) {
    if (inviato == false) {
      Serial.print("ACT ");
      Serial.print(act);
      Serial.print(" tempo: att1: ");

      att1 = muovi('p',5200,360,720);

      Serial.print(att1);

      att2 = muovi('g',5000,-630,720,-830);

      Serial.print(" att2: ");
      Serial.println(att2);

      inviato = true;
    }

    if ((millis() - t0) > magg(att1,att2)) {
      act++;
      inviato = false;
      t0 = millis();
    }
  }






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

    payload += LET;
    payload += " ";
    payload += String(vel);
    payload += '\r';

    Serial2.print(payload);

    delay(100);

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

    payload += LET;
    payload += " ";
    payload += String(vel);
    payload += '\r';

    Serial2.print(payload);

    delay(100);

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
