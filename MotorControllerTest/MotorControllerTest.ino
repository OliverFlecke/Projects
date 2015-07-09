#include <Servo.h>
#include "MotorController.h"

#define MOTOR_PIN_0 5
#define MOTOR_PIN_1 6

MotorController motors[4];

void setup() 
{
  //motors[0] = MotorController(MOTOR_PIN_0);
  //motors[1] = MotorController(MOTOR_PIN_1);
  
  motors[0].attach(MOTOR_PIN_0);
  //motors[0].calibrate();
  motors[1].attach(MOTOR_PIN_1);
  //motors[1].calibrate();
  
  motors[0].setSpeed(255);
 // motors[1].setSpeed(255);
}

void loop() 
{
  
}
