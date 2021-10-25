int ky032 = 6;

int sinalKy032;

void setup() {
  pinMode(ky032, INPUT);
  Serial.begin(9600);
  Serial.println("Inicio da leitura");
}

void loop() {
  sinalKy032 = digitalRead(ky032);
  Serial.println(sinalKy032);
}
