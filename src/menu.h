#ifndef MENU_H
#define MENU_H

#include "config.h"
#include "devSequence.h"
#include "motor.h"
#include "display.h"
#include "sound.h"

void getMenuInput();
char getScrollEntEscInput();
char getEntEscInput();
int startProcessing(struct devSequence* sequence, int sequenceStep);
void startDev();

#endif
