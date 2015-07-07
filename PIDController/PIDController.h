#ifndef PID_CONTROLLER
#define PID_CONTROLLER

// Libraries
// #include "Arduino.h"
#include <iostream>

/// <summary>
/// Class to reprecent and compute a PID controller
/// </summary>
class PIDController
{
  public:
    // Constructors
    PIDController::PIDController();
    PIDController::PIDController(float);
    PIDController::PIDController(float, float, float);

    // PID algoritme
    float Compute(float, float);

    // Set max and min of the controller
    void SetMaxOutput(float);
    void SetMinOutput(float);

    // Set time between each computation
    void SetLoopTime(float);

  private:
    // Constants for the PID controller
    float Kp;
    float Ki;
    float Kd;

    // The time between each calculation
    float dt = 0.01;

    // Minimum and maximum setpoints for the output
    // This is default values, which should be able to be changed
    float max = 255;
    float min = 0;

    // Variables for the PID computation
    float error_pre = 0;
    float integral = 0;
};

#endif // End PID_CONTROLLER
