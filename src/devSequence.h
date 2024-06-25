#ifndef DEVSEQUENCE_H
#define DEVSEQUENCE_H
#define NUM_DEV_SEQUENCES 6
#include <Arduino.h>

struct devSequence
{
  char processName[7];
  int cycles;
  unsigned long int processTime[20];
  char processCycleName[20][10];
  float processCycle[2][20];
  float processTemp[3][20];
};

extern struct devSequence devSequences[NUM_DEV_SEQUENCES];

struct devSequence *findSequenceByName(const char *processName);

#endif
