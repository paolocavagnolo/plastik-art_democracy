void setup() {
  // put your setup code here, to run once:
  pinMode(53,OUTPUT);
  pinMode(52,OUTPUT);
  pinMode(51,OUTPUT);
  pinMode(50,OUTPUT);

  Serial.begin(9600);
  Serial2.begin(4800);

  pinMode(12,INPUT_PULLUP);
  
}

bool oki = false;

void loop() {
  // put your main code here, to run repeatedly:
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
  }
}
