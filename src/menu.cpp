#include "menu.h"

void getMenuInput()
{
  char key = keypad.getKey();
  if (key != NO_KEY)
  {
    switch (key)
    {
    case '1':
      devPgm = "C41";
      break;
    case '2':
      devPgm = "E6";
      break;
    case '3':
      devPgm = "B&W";
      break;
    case '4':
      devPgm = "ECN-2";
      break;
    case '5':
      devPgm = "Custom";
      break;
    case '6':
      devPgm = "B&WREV";
      break;
    }
  }
}

char getScrollEntEscInput()
{
  while (true)
  {
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
      if (key == 'U' || key == 'D' || key == 'X' || key == 'E' || key == 'L' || key == 'R')
      {
        return key;
      }
    }
    if (millis() % 1000 == 0)
    {
      readTemperature();
    }
  }
}

char getEntEscInput()
{
  while (true)
  {
    char key = keypad.getKey();
    if (key != NO_KEY)
    {
      if (key == 'X' || key == 'E')
      {
        return key;
      }
    }
    if (millis() % 1000 == 0)
    {
      readTemperature();
    }
  }
}

int startProcessing(struct devSequence *sequence, int sequenceStep)
{
  run = 1;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(sequence->processCycleName[sequenceStep]);
  for (int x = strlen(sequence->processCycleName[sequenceStep]); x < 10; x++)
  {
    lcd.print(" ");
  }

  lcd.setCursor(10, 0);
  lcd.print(secondsToMinutesSeconds(sequence->processTime[sequenceStep]));
  lcd.setCursor(16, 0);
  lcd.print(" " + (String)(int)sequence->processTemp[1][sequenceStep] + "C");

  lcd.setCursor(0, 1);
  lcd.print("Ent:start Esc:quit");

  char key = getEntEscInput();
  if (key == 'X')
  {
    devPgm = "";
    run = 0;
    return 0;
  }
  processTimeMillis = (unsigned long)sequence->processTime[sequenceStep] * 1000;
  processStartTime = millis();

  MotorTaskParams *params = new MotorTaskParams();
  params->cwRotations = sequence->processCycle[0][sequenceStep];
  params->ccwRotations = sequence->processCycle[1][sequenceStep];
  params->processEndTime = processStartTime + processTimeMillis;

  Serial.print("Starting Motor Task with CW Rotations: ");
  Serial.print(params->cwRotations);
  Serial.print(", CCW Rotations: ");
  Serial.print(params->ccwRotations);
  Serial.print(", Process End Time: ");
  Serial.println(params->processEndTime);

  xTaskCreatePinnedToCore(
      runMotorTask,
      "MotorTask",
      8192,
      (void *)params,
      1,
      &motorTaskHandle,
      0);

  while (millis() < processStartTime + processTimeMillis)
  {
    lcd.setCursor(0, 1);
    lcd.print("Remaining: " + (String)secondsToMinutesSeconds((processStartTime + processTimeMillis - millis()) / 1000) + "      ");
    delay(410);
    Serial.println("before temp read" + (String)millis() + "\n");
    readTemperature();
    Serial.println("after temp read" + (String)millis() + "\n");
  }

  if (motorTaskHandle != NULL)
  {
    vTaskDelete(motorTaskHandle);
    motorTaskHandle = NULL;
  }
  playAlarmTone();

  delete params;
  return 1;
}

void startDev()
{
  const char *searchName = devPgm.c_str();
  struct devSequence *currentSequence = findSequenceByName(searchName);

  for (int i = 0; i < currentSequence->cycles; i++)
  {
    if (run == 1)
    {
      run = startProcessing(currentSequence, i);
      continue;
    }

    processHeadings();
    lcd.setCursor(0, 1);
    lcd.print(currentSequence->processCycleName[i]);
    for (int x = strlen(currentSequence->processCycleName[i]); x < 10; x++)
    {
      lcd.print(" ");
    }

    lcd.setCursor(10, 1);
    lcd.print(secondsToMinutesSeconds(currentSequence->processTime[i]));
    lcd.setCursor(16, 1);
    lcd.print(" " + (String)(int)currentSequence->processTemp[1][i] + "C");

    lcd.setCursor(0, 2);
    lcd.print("Scroll / Esc / Ent");

    char key = getScrollEntEscInput();
    if (key == 'U')
    {
      if (i > 0)
      {
        i--;
      }
      i--;
    }
    else if (key == 'D' && i < currentSequence->cycles - 1)
    {
      continue;
    }
    else if (key == 'D' && i == currentSequence->cycles - 1)
    {
      i--;
      continue;
    }
    else if (key == 'X')
    {
      devPgm = "";
      run = 0;
      return;
    }
    else if (key == 'E')
    {
      int run = 1;
      startProcessing(currentSequence, i);
    }
    else if (key == 'L')
    {
      currentSequence->processTime[i] -= 5;
      lcd.setCursor(10, 1);
      lcd.print(secondsToMinutesSeconds(currentSequence->processTime[i]));
      i--;
    }
    else if (key == 'R')
    {
      currentSequence->processTime[i] += 5;
      lcd.setCursor(10, 1);
      lcd.print(secondsToMinutesSeconds(currentSequence->processTime[i]));
      i--;
    }
  }
  devPgm = "";
  run = 0;
}
