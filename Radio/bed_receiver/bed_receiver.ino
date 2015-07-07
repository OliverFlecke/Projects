#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

#define CSN_pin 8
#define CE_pin 7

/*

*/
void setup() 
{
  Serial.begin(115200);
  
  Mirf.csnPin = CSN_pin;
  Mirf.cePin = CE_pin;
  
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  
  Mirf.setRADDR((byte *) "bed");
  Mirf.payload = 1;
  Mirf.channel = 2;
  Mirf.config();
  
  Serial.println("Ready to receive");
}

/*

*/
void loop() 
{
  byte data;
  
  if (Mirf.dataReady()) 
  {
    Mirf.getData((byte *) data); 
    Serial.print("Data received: ");
    
    
    Serial.print(data, DEC);
    Serial.println();
  }
  delay(100);
}
