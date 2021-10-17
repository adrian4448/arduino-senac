const int pinoPotenciometro = A0;
const int pinoLED = 11;
int leitura = 0;
int pwm = 0;

void setup() {
  pinMode(pinoPotenciometro, INPUT);
  pinMode(pinoLED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  leitura = analogRead(pinoPotenciometro);

  pwm = map(leitura,0, 1023, 0, 255);

  analogWrite(pinoLED, pwm);

  pwm = map(leitura,0, 1023, 0, 255);

}
