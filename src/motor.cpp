#include "motor.h"

void runMotorTask(void *parameter)
{
  MotorTaskParams *params = (MotorTaskParams *)parameter;

  // Enable the motor
  digitalWrite(EN_PIN, LOW);
  while (true)
  {
    // Rotate clockwise
    Serial.println("Rotating CW" + (String)params->cwRotations);
    stepper.setCurrentPosition(0);
    stepper.moveTo(STEPS_PER_REV * params->cwRotations);
    while (stepper.distanceToGo() != 0)
    {
      stepper.run();
    }

    // Rotate counter-clockwise
    Serial.println("Rotating CCW" + (String)params->ccwRotations);
    stepper.setCurrentPosition(0);
    stepper.moveTo(-STEPS_PER_REV * params->ccwRotations);
    while (stepper.distanceToGo() != 0)
    {
      stepper.run();
    }
  }
  // Disable the motor
  digitalWrite(EN_PIN, HIGH);

  vTaskDelete(NULL); // Delete the task when done
}
