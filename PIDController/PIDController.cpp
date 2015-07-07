#include "PIDController.h"

/// <summary>
/// Defualt constructor for the PID controller.
/// </summary>
PIDController::PIDController()
{
  this->Kp = 1;
  this->Ki = 0;
  this->Kd = 0;
  std::cout << "New PIDColler Object has been created" << std::endl;
}

/// <summary>
/// Set the P constant of the controller without setting the others.
/// </summary>
PIDController::PIDController(float Kp)
{
  this->Kp = Kp;
  this->Ki = 0;
  this->Kd = 0;
}

/// <summary>
/// Set all three of the constants at once
/// <summary>
PIDController::PIDController(float Kp, float Ki, float Kd)
{
  this->Kp = Kp;
  this->Ki = Ki;
  this->Kd = Kd;
}

/// <summary>
/// Compute the desired output bassed on the setpoint and the actual position
/// of the controlled device
/// </summary>
float PIDController::Compute(float setpoint, float actualPosition)
{
  float derivative;
  float output = 0;
  // Calculate the error based on the given setpint and the messured position
  float error = setpoint - actualPosition;

  // Calcualte the integral and derivative part
  integral += error * dt;
  derivative = (error - error_pre) / dt;

  output = this->Kp*error + this->Ki*integral + this->Kd*derivative;

  // Insure the output is within the possible setpoints
  if (output > max)
    output = max;
  else if (output < min)
    output = min;

  // Update the previues error variable
  error_pre = error;

  // Return the calculated output
  return output;
}

/// <summary>
/// Set the maximum possible setpoint for the output of this PID controller
/// Defaults to 255
/// </summary>
void PIDController::SetMaxOutput(float newMax)
{
  this->max = newMax;
}

/// <summary>
/// Set the minimum possible setpoint for the output of this PID controller
/// Defialts to 0
/// </summary>
void PIDController::SetMinOutput(float newMin)
{
  this->min = newMin;
}

/// <summary>
/// Set the time between each time a computation should be done
/// </summary>
void PIDController::SetLoopTime(float time)
{
  this->dt = time;
}

int main()
{
  PIDController con = PIDController();
  return 0;
}
