#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

// Define pins
#define CE_PIN   9
#define CSN_PIN 10

// NOTE: the "LL" at the end of the constant is "LongLong" type
const uint64_t pipe = 0xE8E8F0F0E1LL; // Define the transmit pipe


/*-----( Declare objects )-----*/
RF24 radio(CE_PIN, CSN_PIN); // Create a Radio

// Values to store the received data in
int values[2];  

/*
  Setup radio for receiving data
*/
void setup() {
  Serial.begin(115200);
  delay(1000);
  Serial.println("Nrf24L01 Receiver Starting");
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}

/*

*/
void loop() {
  if (radio.available()) 
  {
    bool done = false; 
    
    while (!done) 
    {
     done = radio.read(values, sizeof(values));
     Serial.print("X : ");
     Serial.print(values[0]);
     Serial.print(" Y : ");
     Serial.println(values[1]); 
    }
  }
  else 
  {
    radio.printDetails();
   //Serial.println("No Radio availabe");    
   delay(100);
  }
}
