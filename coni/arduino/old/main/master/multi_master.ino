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
uint32_t dataOut[5] = {0,0,0,0,0};
long dataIn = 0;
char tag;
bool inv = false;

uint8_t completo = 0;

String inString = "";

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
  if (Serial.available() > 0) {
    int inChar = Serial.read();
    if (isDigit(inChar)) {
      inString += (char)inChar;
    }
    else {
      if ((inChar != '\n') && (inChar != '-')) {
        tag = ((char)inChar);
      }
      else if (inChar == '-') {
        inv = true;
      }
    }

    if (inChar == '\n') {

      dataIn = inString.toInt();
      if (inv) {
        dataIn *= -1;
        inv = false;
      }

      switch (tag) {
        case 'a':   //pos A
          dataOut[completo] = dataIn * (100800 / 360) + 500000;
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'A':
          if (dataIn > 360) { //vel A
            dataOut[completo] = dataIn + 1500000;
          }
          else { //abs A
            dataOut[completo] = dataIn * (100800 / 360) + 16500000;
          }
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'b':   //pos B
          dataOut[completo] = dataIn * (100800 / 360) + 2500000;
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'B':   //vel B
          if (dataIn > 360) { //vel B
            dataOut[completo] = dataIn + 3500000;
          }
          else { //abs B
            dataOut[completo] = dataIn * (100800 / 360) + 17500000;
          }
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'c':   //pos C
          dataOut[completo] = dataIn * (100800 / 360) + 6500000;
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'C':
          if (dataIn > 360) { //vel C
            dataOut[completo] = dataIn + 7500000;
          }
          else { //abs C
            dataOut[completo] = dataIn * (100800 / 360) + 18500000;
          }
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'd':   //pos D
          dataOut[completo] = dataIn * (100800 / 360) + 8500000;
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'D':
          if (dataIn > 360) { //vel D
            dataOut[completo] = dataIn + 9500000;
          }
          else { //abs D
            dataOut[completo] = dataIn * (100800 / 360) + 19500000;
          }
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'e':   //pos E
          dataOut[completo] = dataIn * (100800 / 360) + 10500000;
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 'E':
          if (dataIn > 360) { //vel E
            dataOut[completo] = dataIn + 11500000;
          }
          else { //abs E
            dataOut[completo] = dataIn * (100800 / 360) + 20500000;
          }
          Serial.print(tag);
          Serial.print(dataIn);
          Serial.print(" // ");
          Serial.println(dataOut[completo]);
          completo++;
          break;
        case 's':
          dataOut[completo] = 15500000;
          Serial.print("Stop // ");
          Serial.println(dataOut[completo]);
          Serial2.print(dataOut[completo]);
          completo++;
          break;
        case 'z':
          Serial.println("z");
          Serial.println(dataOut[completo]);
          switch (dataIn) {
            case 1:
              Serial.print("zerosA // ");
              Serial.println(4500000);
              break;
            case 2:
              Serial.print("zerosB // ");
              Serial.println(5500000);
              break;
            case 3:
              Serial.print("zerosC // ");
              Serial.println(12500000);
              break;
            case 4:
              Serial.print("zerosD // ");
              Serial.println(13500000);
              break;
            case 5:
              Serial.print("zerosE // ");
              Serial.println(14500000);
              break;
            default:
              Serial.println("motore non esistente");
              break;
          completo++;
          }
          break;
        case 'g':
          for (uint8_t i = 0; i<completo; i++) {
            Serial.println(dataOut[completo]);
            Serial2.print(dataOut[completo]);
          }
          break;

        default:
          Serial.println("comando inesistente");
          break;
      }

      inString = "";

    } //chiudo if inChar == '\n'

  } // chiudo if serial available
}
