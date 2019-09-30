#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}
void loop() {
  if (radio.available()) {
    float text;
    float text1;
    radio.read(&text, sizeof(text));
    radio.read(&text1, sizeof(text1));
  
    Serial.print(text);
    Serial.print("-------");
    Serial.println(text1);
  }
}
