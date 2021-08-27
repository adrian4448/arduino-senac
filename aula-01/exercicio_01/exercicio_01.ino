int vermelho = 13;
int amarelo = 12;
int verde = 11;
int pare = 10;
int prossiga = 9;

void setup() {
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(pare, OUTPUT);
  pinMode(prossiga, OUTPUT);
}

void loop() {
  digitalWrite(prossiga, HIGH);
  digitalWrite(vermelho, HIGH);
  delay(3000);
  digitalWrite(vermelho, LOW);
  digitalWrite(prossiga, LOW);
  digitalWrite(pare, HIGH);
  digitalWrite(amarelo, HIGH);
  delay(3000);
  digitalWrite(amarelo, LOW);
  digitalWrite(verde, HIGH);
  delay(3000);
  digitalWrite(verde, LOW);
  digitalWrite(pare, LOW);
}
