void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("A0: ")
  Serial.print(analogRead(A0));
  Serial.print(" - A1: ")
  Serial.print(analogRead(A1));
  Serial.print(" - A2: ")
  Serial.print(analogRead(A2));
  Serial.print(" - A3: ")
  Serial.print(analogRead(A3));
}
