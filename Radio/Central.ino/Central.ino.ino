#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define CSN_pin 8
#define CE_pin 7

/*
    Setup the radio to be able to receive.
*/
void setup() 
{
  Serial.begin(115200);

  Mirf.csnPin = CSN_pin;
  Mirf.cePin = CE_pin;
  
  Mirf.spi = &MirfHardwareSpi;            // Set the SPI driver 
  Mirf.init();                            // Setup pins/SPI
  
  Mirf.setRADDR((byte *) "head");         // Configure the reciving address
  Mirf.payload = 1;   // Set the payload of the data to be tranmitted - Must be the same at the reciver
  Mirf.channel = 2;                       // Set channel for transmitting
  Mirf.config();                          // Power up the reciver

  Serial.println("Ready to transmit");
}

/*
    Receive and send data    
*/
void loop() 
{
  // Variable to store the data in
  byte data[Mirf.payload];
  
  data[0] = 73;
  
  Mirf.setTADDR((byte *) "bed");
  Mirf.send(data);
  
  while (Mirf.isSending()) 
  {
    // Wait
  }
  Serial.println("Message send");
  delay(1000);
}
