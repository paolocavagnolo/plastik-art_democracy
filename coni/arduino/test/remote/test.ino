void setup() {
  // put your setup code here, to run once:
  pinMode(53, OUTPUT);
  pinMode(52, OUTPUT);
  pinMode(51, OUTPUT);
  pinMode(50, OUTPUT);

  Serial.begin(9600);
  Serial2.begin(4800);

  pinMode(12, INPUT_PULLUP);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

}

bool oki = false;
uint32_t dataOut = 0;
uint32_t dataIn = 0;

void loop() {
  /*// put your main code here, to run repeatedly:
    if (digitalRead(12)) {
    digitalWrite(52,HIGH);
    if (oki) {
      Serial2.println("ciao");
      oki = false;
    }
    }
    else {
    digitalWrite(52,LOW);
    oki = true;
    }*/
  if (Serial.available()) {
    Serial2.print(Serial.parseInt());
  }


}