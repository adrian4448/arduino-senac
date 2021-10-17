const int pinoLEDR = 11;
const int pinoLEDG = 10;
const int pinoLEDB = 9;
const int pinoBotaoR = 7;
const int pinoBotaoG = 6;
const int pinoBotaoB = 5;

// Variáveis para armazenar o estado de cada botão
int leituraBotaoR;
int leituraBotaoG;
int leituraBotaoB;

void setup() {
 pinMode(pinoLEDR,OUTPUT);
 pinMode(pinoLEDG,OUTPUT);
 pinMode(pinoLEDB,OUTPUT);
 pinMode(pinoBotaoR,INPUT_PULLUP);
 pinMode(pinoBotaoG,INPUT_PULLUP);
 pinMode(pinoBotaoB,INPUT_PULLUP);
}

void loop() {
  // le estado dos botões
  leituraBotaoR=digitalRead(pinoBotaoR);
  leituraBotaoG=digitalRead(pinoBotaoG);
  leituraBotaoB=digitalRead(pinoBotaoB);

  if(leituraBotaoR == LOW) {
    analogWrite(pinoLEDR, 255);  
    } else {
      analogWrite(pinoLEDR, 0);  
    }

  if(leituraBotaoG == LOW) {
    analogWrite(pinoLEDG, 255);  
    } else {
      analogWrite(pinoLEDG, 0); // apaga o LED  
    }

    if(leituraBotaoB == LOW) {
      analogWrite(pinoLEDB, 255); 
    } else {
      analogWrite(pinoLEDB, 0); 
    }

    delay(100); 
}
