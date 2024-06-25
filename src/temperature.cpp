#include "temperature.h"

void readTemperature() {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  lcd.setCursor(13, 3);
  lcd.write(byte(0));
  if (temperatureC == DEVICE_DISCONNECTED_C) {
    lcd.print("--");
  } else {
    lcd.print(temperatureC, 1);
    lcd.print("C");
  }
}

void updateTempDisplay(void* parameter) {
  sensors.requestTemperatures();
  float temperatureC = sensors.getTempCByIndex(0);
  lcd.setCursor(13, 3);
  lcd.write(byte(0));
  if (temperatureC == DEVICE_DISCONNECTED_C) {
    lcd.print("--");
  } else {
    lcd.print(temperatureC, 1);
    lcd.print("C");
  }

  vTaskDelete(NULL);  // Delete the task when done
}
