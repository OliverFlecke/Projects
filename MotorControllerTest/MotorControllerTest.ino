#include "MotorController.h"

MotorController motors[4];

void setup() 
{
  motors[0] = MotorController(6);
  motors[1] = MotorController(7);

}

void loop() {
  // put your main code here, to run repeatedly:

}
