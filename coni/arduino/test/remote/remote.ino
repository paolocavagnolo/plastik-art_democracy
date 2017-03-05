void setup() {
  // put your setup code here, to run once:
  pinMode(5, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);

  Serial.begin(9600);
  Serial2.begin(4800);

  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);

}

bool oki = false;
uint32_t dataOut = 0;
long dataIn = 0;
char tag;
bool inv = false;

String inString = "";

void loop() {
  
  Serial2.write(Serial.read());

}
