#include "ThingSpeak.h"
#include <SPI.h>
#include <UIPEthernet.h>
#include <utility/logging.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xE1, 0x64};
EthernetClient client;

int potenciometro = A0; //Porta analógica utilizada pelo LDR

unsigned long myChannelNumber = 366125;
const char * myWriteAPIKey = "Y1Q5K43SS25R0SH1";
int fieldNumber = 1;

void setup() {
  Ethernet.begin(mac);
  ThingSpeak.begin(client);
}

void loop() {
  int estado = analogRead(potenciometro);  //Lê o valor fornecido pelo potenciometro
  ThingSpeak.writeField(myChannelNumber, fieldNumber, estado, myWriteAPIKey);
  delay(10000);
}
