#include "config.h"

// Global variables definition
const char* version = "V0.1.0 20240625";
const byte ROWS = 5;
const byte COLS = 4;
byte rowPins[ROWS] = { 19, 18, 5, 17, 16 };
byte colPins[COLS] = { 15, 2, 0, 4 };

char keys[ROWS][COLS] = {
  { 'F', 'E', '#', '*' },
  { '1', '2', '3', 'U' },
  { '4', '5', '6', 'D' },
  { '7', '8', '9', 'X' },
  { 'L', '0', 'R', 'E' }
};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LiquidCrystal_I2C lcd(0x27, LCD_COLUMNS, LCD_ROWS);
AccelStepper stepper(AccelStepper::DRIVER, PULSE_PIN, DIR_PIN);
OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature sensors(&oneWire);

String devPgm = "";
int run;
const int beeperPin = 25;

TaskHandle_t motorTaskHandle = NULL;
TaskHandle_t tempTaskHandle = NULL;

unsigned long processStartTime;
unsigned long processTimeMillis;

byte thermometer[8] = {
  B00100,
  B01100,
  B00100,
  B01100,
  B00100,
  B01110,
  B01110,
  B01110
};
