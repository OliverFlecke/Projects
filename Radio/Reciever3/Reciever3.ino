#include <SPI.h>
#include <Mirf.h>
#include <nRF24L01.h>
#include <MirfHardwareSpiDriver.h>

void setup() {
  Serial.begin(115200);
  Mirf.spi = &MirfHardwareSpi;
  Mirf.init();
  Mirf.setRADDR((byte *) "clie1");
  Mirf.payload = sizeof(unsigned long);
  Mirf.config();
 
  Serial.println("Setup done"); 
}

void loop() {
  unsigned long data = 1234;
  unsigned long time = millis();
  
  Mirf.setTADDR((byte *) "serv1");
  Mirf.send((byte *) &time);
  
  while (Mirf.isSending()) { } // Wait while transmitting data
  
 /* delay(10);
  while(!Mirf.dataReady()) {
     if (millis() - time > 1000) {
        Serial.println("No responds");
        return; 
     }
  }*/
  
  Mirf.getData((byte *) &data);
  Serial.print("Ping: ");
  Serial.println(millis() - time);

  delay(1000);
}
