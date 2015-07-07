#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define pins 
#define CE_PIN 9
#define CSN_PIN 53
// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe

RF24 radio(CE_PIN, CSN_PIN); // Create a Radio
int values[2];
/* 
  Setup serial and radio transmittation 
*/
void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  values[0] = 0;
  values[1] = 0;
}

/*
  Transmit numbers
*/
void loop() {
  values[0]++;
  values[1]++;
  
  radio.write(values, sizeof(values));
  
  delay(1000);
}
