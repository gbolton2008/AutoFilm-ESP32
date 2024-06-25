#include "sound.h"


int melody[] = {
  262, 294, 330, 349, 392, 440, 494, 523, 587, 659, 698, 784, 880, 988, 1047
};
int noteDurations[] = {
  250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250, 250
};

void playTune() {
  for (int thisNote = 0; thisNote < 15; thisNote++) {
    int noteDuration = noteDurations[thisNote];
    tone(beeperPin, melody[thisNote], noteDuration);

    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    noTone(beeperPin);
  }
}

void playAlarmTone() {
  for (int i = 1; i <= 10; i++) {
    tone(beeperPin, 2000);
    delay(500);
    noTone(beeperPin);
    delay(250);
  }
}
