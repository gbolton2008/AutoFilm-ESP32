#include "display.h"
#include "menu.h"


void startingMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Programme:");
  lcd.setCursor(0, 1);
  lcd.print("1. C41");
  lcd.setCursor(0, 2);
  lcd.print("2. E6");
  lcd.setCursor(0, 3);
  lcd.print("3. B&W");
  lcd.setCursor(10, 1);
  lcd.print("4. ECN-2");
  lcd.setCursor(10, 2);
  lcd.print("5. Custom");
  lcd.setCursor(10, 3);
  lcd.print("6. B&W Rev");

  while (devPgm == "") {
    getMenuInput();
  }
  lcd.print(devPgm);

  if (devPgm == "C41" || devPgm == "E6" || devPgm == "B&W" || devPgm == "ECN-2" || devPgm == "Custom" || devPgm == "B&WREV") {
    startDev();
  }
}

void processHeadings() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Step");
  lcd.setCursor(10, 0);
  lcd.print("Time");
  lcd.setCursor(16, 0);
  lcd.print("Temp");
}



char* secondsToMinutesSeconds(int seconds) {
  char* result = (char*)malloc(6 * sizeof(char));
  if (result == NULL) {
    return NULL;
  }

  int minutes = seconds / 60;
  int secs = seconds % 60;

  snprintf(result, 6, "%02d:%02d", minutes, secs);

  return result;
}
