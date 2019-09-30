//#include <dht.h>
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

 // Serial.begin(9600);
  //for (int DigitalPin = 7; DigitalPin <= 9; DigitalPin++) 
 //{
 // pinMode(DigitalPin, OUTPUT);
 //}
  //lcd.begin(16,2);  //16 by 2 character display
  
dht.begin();







  
}
void loop() {
   delay(1000);
   float t = dht.readTemperature();
   float h = dht.readHumidity();

  float t1[10] = {t};
  float h1[10] = {h};
  //const char text[] = "Hello World";
  radio.write(&t1, sizeof(t1));
  radio.write(&h1, sizeof(h1));
  delay(1000);



  
}
