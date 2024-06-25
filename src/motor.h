#ifndef MOTOR_H
#define MOTOR_H

#include <AccelStepper.h>
#include "config.h"

struct MotorTaskParams
{
  float cwRotations;
  float ccwRotations;
  unsigned long int processEndTime;
};

void runMotorTask(void *parameter);

#endif
