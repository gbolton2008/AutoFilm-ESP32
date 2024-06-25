#ifndef DISPLAY_H
#define DISPLAY_H

#include <LiquidCrystal_I2C.h>
#include "config.h"

void updateTempDisplay(void* parameter);
void startingMenu();
void processHeadings();
void readTemperature();
char* secondsToMinutesSeconds(int seconds);

#endif
