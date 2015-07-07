#include "Nrf2401.h"
 
Nrf2401 Radio;
 
void setup(void)
{
  Radio.remoteAddress = 1;
  Radio.txMode(3);
  Radio.data[0] = 22;
  Radio.data[1] = 33;
  Radio.data[2] = 44;
}
 
void loop(void)
{
  Radio.write();
  delay(2000);
}
