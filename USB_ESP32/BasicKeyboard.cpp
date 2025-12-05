#include "USB.h"
#include "USBHIDKeyboard.h"

USBHIDKeyboard Keyboard;  // Create keyboard object

void setup() {
  // Start USB stack
  USB.begin();
  Keyboard.begin();

  // Small delay to give the host time to recognize the device
  delay(3000);

  // Type text once
  Keyboard.print("Hello from ESP32-S3!");
  Keyboard.write(KEY_RETURN);  // press Enter (optional)
}

void loop() {
  // Do nothing
}
