#include <Arduino.h>
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

// --- Definição dos Pinos ---
#define ledPino  2
#define botaoPino 4

SoftwareSerial mySoftwareSerial(10,11); //TX RX
DFRobotDFPlayerMini myDFPlayer;

int ultimoEstado = LOW;
int ledLigado = 0;

void setup() {
pinMode(ledPino, OUTPUT);
pinMode(botaoPino,INPUT);

digitalWrite(ledPino, LOW);

mySoftwareSerial.begin(9600);

Serial.begin(9600);

if (!myDFPlayer.begin(mySoftwareSerial)) {

Serial.println(F("Erro: Verifique conexoes e cartao SD"));

while(true);}

Serial.println(F("DFPlayer Online!"));

myDFPlayer.volume(20); // Volume 0-30

}

void loop() {
int leitura = digitalRead(botaoPino);

if(leitura == HIGH && ultimoEstado == 0){
  ledLigado = !ledLigado;

  if(ledLigado){
    digitalWrite(ledPino, HIGH);
    myDFPlayer.play(1);
  }
  else{
    digitalWrite(ledPino, LOW);
    myDFPlayer.play(2);
  }

  delay(50);
}

Serial.println(leitura);

ultimoEstado = leitura;

}