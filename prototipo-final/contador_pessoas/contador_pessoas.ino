//Codigo para conexao wifi e servidor web, by pg132, sergio
//conexao wifi
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "SENAC";
const char* senha = "$enac2021";
#define PinoTrigger 18   //O Trigger emite o pulso
#define PinoEcho 5      //O Echo recebe o pulso

int duracao = 0;
int distancia = 0;
int pessoasDentro = 0;
int distanciaPorta = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  //Iniciando a conexao WiFI
  Serial.print("Conectando para a rede");
  Serial.println(ssid);

  WiFi.begin(ssid,senha);

  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  pinMode(PinoTrigger,OUTPUT);
  pinMode(PinoEcho,INPUT);

}


void loop() {
digitalWrite(PinoTrigger, HIGH);
delayMicroseconds(10);
digitalWrite(PinoTrigger,LOW);
  
duracao = pulseIn(PinoEcho, HIGH); //Armazena o valor lido
distancia = duracao*0.017175;
Serial.print(distancia);
Serial.println("cm");
  if(distanciaPorta == 0) {
    distanciaPorta = distancia - 2;
  }else {
    if(distancia < distanciaPorta) {
    pessoasDentro++;
    if(pessoasDentro % 2 == 0) {

        HTTPClient http;

        Serial.print("[HTTP] begin...\n");
        // configure traged server and url
        //http.begin("https://www.howsmyssl.com/a/check", ca); //HTTPS
        http.begin("http://10.10.30.125:3000/arduino/count"); //HTTP

        Serial.print("[HTTP] GET...\n");
        // start connection and send HTTP header
        int httpCode = http.GET();

        // httpCode will be negative on error
        if(httpCode > 0) {
            // HTTP header has been send and Server response header has been handled
            Serial.printf("[HTTP] GET... code: %d\n", httpCode);

            // file found at server
            if(httpCode == HTTP_CODE_OK) {
                String payload = http.getString();
                Serial.println(payload);
            }
        } else {
            Serial.printf("[HTTP] GET... failed, error: %s\n", httpCode);
        }

        http.end();
    }
  }   
  }
delay(100);
}
