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

  if (Serial.available()) {
    dataIn = Serial.parseInt();
    Serial.println(dataIn)
    
  }

}
