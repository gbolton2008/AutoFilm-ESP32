#include "config.h"
#include "motor.h"
#include "temperature.h"
#include "display.h"
#include "menu.h"
#include "devSequence.h"
#include "sound.h"
#include "watchdog.h"

// Function declarations
void setup();
void loop();

void setup()
{
  Serial.begin(115200);

  // Disable the watchdog timers
  disableWatchdogTimers();

  // Initialize LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.createChar(0, thermometer);

  // Set pin modes
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, HIGH); // Disable motor initially
  pinMode(beeperPin, OUTPUT);
  // Set stepper motor properties
  stepper.setMaxSpeed(SPEED);
  stepper.setAcceleration(9600); // Set acceleration

  // Display welcome message
  lcd.setCursor(6, 1);
  lcd.print("AUTOFILM");
  lcd.setCursor((20 - strlen(version)) / 2, 3);
  lcd.print(version);
  delay(1000);
  lcd.clear();
}

void loop()
{
  startingMenu();
}
