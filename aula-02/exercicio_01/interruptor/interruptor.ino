int botaoOnePort = 9;
int botaoTwoPort = 7;
int ledOnePort = 12;
int ledTwoPort = 6;

void setup() {
  pinMode(botaoOnePort, INPUT);
  pinMode(ledOnePort, OUTPUT);
  pinMode(botaoTwoPort, INPUT);
  pinMode(ledTwoPort, OUTPUT);
}

void loop() {
  if (digitalRead(botaoOnePort) == HIGH) {
    digitalWrite(ledOnePort, HIGH);
  } else {
    digitalWrite(ledOnePort, LOW);
  }
  
  if (digitalRead(botaoTwoPort) == LOW) {
    digitalWrite(ledTwoPort, HIGH);
  } else {
    digitalWrite(ledTwoPort, LOW);
  }
}
