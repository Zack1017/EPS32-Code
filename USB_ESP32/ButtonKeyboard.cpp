#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;

const int BUTTON_PIN = 0;

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  USB.begin();
  Keyboard.begin();
  delay(2000);  // let USB enumerate
}

void loop() {
  // Active LOW button
  if (digitalRead(BUTTON_PIN) == LOW) {
    // Simple debounce
    delay(20);
    if (digitalRead(BUTTON_PIN) == LOW) {
      Keyboard.print("Button pressed on ESP32-S3!");
      Keyboard.write(KEY_RETURN);

      // Wait until button released
      while (digitalRead(BUTTON_PIN) == LOW) {
        delay(10);
      }

      delay(200);  // debounce after release
    }
  }
}
