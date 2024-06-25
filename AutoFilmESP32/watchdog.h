#ifndef WATCHDOG_H
#define WATCHDOG_H

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_task_wdt.h"

// Disable the watchdog timers
void disableWatchdogTimers() {
  esp_task_wdt_deinit();
  TaskHandle_t idle_0 = xTaskGetIdleTaskHandleForCPU(0);
  TaskHandle_t idle_1 = xTaskGetIdleTaskHandleForCPU(1);
  esp_task_wdt_delete(idle_0);
  esp_task_wdt_delete(idle_1);
}

#endif
