#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <AccelStepper.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// Constants and definitions
#define LCD_COLUMNS 20
#define LCD_ROWS 4
#define PULSE_PIN 12
#define DIR_PIN 14
#define EN_PIN 27
#define STEPS_PER_REV 4800
#define RPM 60
#define SPEED (RPM * STEPS_PER_REV / 60.0)
#define TEMP_SENSOR_PIN 13
#define NUM_DEV_SEQUENCES 6

extern const char *version;
extern Keypad keypad;
extern LiquidCrystal_I2C lcd;
extern AccelStepper stepper;
extern OneWire oneWire;
extern DallasTemperature sensors;
extern String devPgm;
extern int run;
extern const int beeperPin;
extern byte thermometer[8];

extern TaskHandle_t motorTaskHandle;
extern TaskHandle_t tempTaskHandle;

extern unsigned long processStartTime;
extern unsigned long processTimeMillis;

#endif
