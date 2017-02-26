#define SWITCH 12

#define RE 6
#define DE 7

uint8_t tracks[16] = {53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38};

void setup() {

  Serial.begin(9600);
  Serial2.begin(4800);

  pinMode(SWITCH, INPUT_PULLUP);
 
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
  digitalWrite(RE, HIGH);
  digitalWrite(DE, HIGH);

}

uint32_t dataOut[5] = {0,0,0,0,0};
long dataIn = 0;

char tag;
bool inv = false;
uint8_t completo = 0;

String inString = "";

void loop() {

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
          completo++;
          break;
        case 'A':
          if (dataIn > 360) { //vel A
            dataOut[0] = dataIn + 1500000;
          }
          else { //abs A
            dataOut[0] = dataIn * (100800 / 360) + 16500000;
          }
          Serial.print(tag);
          completo = 6;
          break;
        case 'b':   //pos B
          dataOut[completo] = dataIn * (100800 / 360) + 2500000;
          Serial.print(tag);
          completo++;
          break;
        case 'B':   //vel B
          if (dataIn > 360) { //vel B
            dataOut[0] = dataIn + 3500000;
          }
          else { //abs B
            dataOut[0] = dataIn * (100800 / 360) + 17500000;
          }
          Serial.print(tag);
          completo = 6;
          break;
        case 'c':   //pos C
          dataOut[completo] = dataIn * (100800 / 360) + 6500000;
          Serial.print(tag);
          completo++;
          break;
        case 'C':
          if (dataIn > 360) { //vel C
            dataOut[0] = dataIn + 7500000;
          }
          else { //abs C
            dataOut[0] = dataIn * (100800 / 360) + 18500000;
          }
          Serial.print(tag);
          completo = 6;
          break;
        case 'd':   //pos D
          dataOut[completo] = dataIn * (100800 / 360) + 8500000;
          Serial.print(tag);
          completo++;
          break;
        case 'D':
          if (dataIn > 360) { //vel D
            dataOut[0] = dataIn + 9500000;
          }
          else { //abs D
            dataOut[0] = dataIn * (100800 / 360) + 19500000;
          }
          Serial.print(tag);
          completo = 6;
          break;
        case 'e':   //pos E
          dataOut[completo] = dataIn * (100800 / 360) + 10500000;
          Serial.print(tag);
          completo++;
          break;
        case 'E':
          if (dataIn[0] > 360) { //vel E
            dataOut = dataIn + 11500000;
          }
          else { //abs E
            dataOut[0] = dataIn * (100800 / 360) + 20500000;
          }
          Serial.print(tag);
          completo++;
          break;
        case 's':
          dataOut[0] = 15500000;
          Serial2.print(dataOut);
          completo = 6;
          break;
        case 'z':
          switch (dataIn) {
            case 1:
              dataOut[0] = 4500000;
              completo = 6;
              break;
            case 2:
              dataOut[0] = 5500000;
              completo = 6;
              break;
            case 3:
              dataOut[0] = 12500000;
              completo = 6;
              break;
            case 4:
              dataOut[0] = 13500000;
              completo = 6;
              break;
            case 5:
              dataOut[0] = 14500000;
              completo = 6;
              break;
            default:
              Serial.println("motore non esistente");
              break;
          }
          break;
        default:
          Serial.println("comando inesistente");
          break;
      }

      Serial.print(dataIn);
      Serial.print(" // ");
      Serial.print(dataOut);
      Serial.print(" // ");
      Serial.println(completo)

      inString = "";

    }
  }

  if (completo == 5) {
    for (int i=0; i<5; i++) {
      Serial2.print(dataOut[i]);
    }
    Serial2.print(666);
    completo = 0;
  }
  if (completo == 6) {
    Serial2.print(dataOut[0]);
    completo = 0;
  }

}
