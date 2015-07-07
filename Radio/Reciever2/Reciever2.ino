#include "Nrf2401.h"
 
Nrf2401 Radio;
 
void setup(void)
{
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  Radio.localAddress = 1;
  Radio.rxMode(3);
  Serial.println("Start recieving");
}
 
void loop(void)
{
  while(!Radio.available());
  Radio.read();
  if(Radio.data[0] == 22 && Radio.data[1] == 33 && Radio.data[2] == 44)
  {
    Serial.println("Data recieved");
    digitalWrite(13, HIGH);
    delay(500);
    digitalWrite(13, LOW);
  }
}
