#include <Servo.h>

#define PinoTrigger 4   //O Trigger emite o pulso
#define PinoEcho 5      //O Echo recebe o pulso
#define pinServo 9

int duracao = 0;
int distancia = 0;
int pessoasDentro = 0;
int distanciaPorta = 0;

Servo servo1;
int grau = 0;

void setup ()
{
servo1.write(0);
servo1.attach(pinServo);
pinMode(PinoTrigger,OUTPUT);
pinMode(PinoEcho,INPUT);
Serial.begin(9600);
}

void loop()
{
digitalWrite(PinoTrigger, HIGH);
delayMicroseconds(10);
digitalWrite(PinoTrigger,LOW);
  
duracao = pulseIn(PinoEcho, HIGH); //Armazena o valor lido
distancia = duracao*0.017175;
Serial.print(distancia);
Serial.println("cm");  

if(distancia < 5) {
  servo1.write(5000);
  delay(500);
  servo1.write(0);
  delay(500);
}

delay(100);

}
