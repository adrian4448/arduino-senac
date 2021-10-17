//Codigo para conexao wifi e servidor web, by pg132, sergio
//conexao wifi
#include <WiFi.h>
const char* ssid = "Embarcados";
const char* senha = "IoT2021@Senac";

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
}


void loop() {
  // put your main code here, to run repeatedly:

}
