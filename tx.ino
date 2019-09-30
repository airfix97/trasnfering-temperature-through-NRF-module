
#include <DHT.h>

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN
const byte address[6] = "00001";

#define DHTPIN 5                // Connect the signal pin of DHT11 sensor to digital pin 5
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);


void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  dht.begin();
}
void loop() {
   delay(1000);
   float t = dht.readTemperature();    // reads the temperature 
   float h = dht.readHumidity();       // reads the humidity

  float t1[10] = {t};
  float h1[10] = {h};
  //const char text[] = "Hello World";
  radio.write(&t1, sizeof(t1));        // sends temperature data to nrf module to transmit
  radio.write(&h1, sizeof(h1));         // send humidity data to nrf module to trasnmit
  delay(1000);                          // send data after every second 
}
