int frequencia = 2000;
int botaoUp = 11;
int botaoDown = 9;
int somOut = 10;

void setup() {
  pinMode(botaoUp, INPUT_PULLUP);
  pinMode(botaoDown, INPUT_PULLUP);
  pinMode(somOut, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  if(digitalRead(botaoUp) == LOW) {
    frequencia = frequencia + 100;
  }
  if(digitalRead(botaoDown) == LOW) {
    frequencia = frequencia - 100;
  }
  Serial.write(frequencia);
  tone(somOut, frequencia);
  delay(1000);
  noTone(somOut);
  delay(1000);
}
