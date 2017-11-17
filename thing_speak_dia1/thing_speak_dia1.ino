#include "ThingSpeak.h"
#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>

int potenciometro = A0;
int valorPotenciometro = 0;

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xEE, 0xFF};
EthernetClient client;

unsigned long myChannelNumber = 366125;
const char * myWriteAPIKey = "Y1Q5K43SS25R0SH1";  //chave de escrita

void setup() {
  Serial.begin(9600); //
  Ethernet.begin(mac);
  ThingSpeak.begin(client);
}

void loop() {
  valorPotenciometro = analogRead (potenciometro);
  if(Serial.available ()>0){  //
    int valor = Serial.parseInt(); // 
    ThingSpeak.writeField(myChannelNumber, 1, valor, myWriteAPIKey); //
    }
   delay(10000);
}
