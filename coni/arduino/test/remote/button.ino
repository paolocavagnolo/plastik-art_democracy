#define MAINSW 12 //1 su 0 e 0 su 1
#define SEL_A 28 //0 su 1
#define SEL_B 31 //0 su 2
#define BT_A A14 //0 premuto
#define BT_B A8 //1 premuto

void setup() {
  pinMode(MAINSW, INPUT_PULLUP);
  pinMode(SEL_A, INPUT_PULLUP);
  pinMode(SEL_B, INPUT_PULLUP);
  pinMode(BT_A, INPUT_PULLUP);
  pinMode(BT_B, INPUT_PULLUP);

  Serial.begin(9600);

  Serial2.begin(4800);
}

void loop() {
  while (digitalRead(MAINSW)) //SHOW
  {
    Serial.println("show!");
    delay(500);
  }
  while (!digitalRead(MAINSW)) //TEST
  {
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
