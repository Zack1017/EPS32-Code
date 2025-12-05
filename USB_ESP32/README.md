# EPS32-Code

## Ardunio IDE Set UP 

### A. Install/ Update ESP32 core 

Go to File, Preferneces, Additional Boards Manager URLS.  Add if not present: 
``
https://espressif.github.io/arduino-esp32/package_esp32_index.json
``

Next go to Tools, Board, Boards Manager...
Search ESP32 and install or update to the latest

### Select the correct board & USB Mode 

Go to Tools, Board, ESP32, select Adafruit Feather ESP32-S3(Or Similar)

In Tools set: 
* USB Mode: USB-OTG or USB-CDC and HID (wording may change based on version; you want HID enabled)
* If you see "USB CDC On Boot" Enabled is usally fine 

Note: Must use Native USB-C Port and not external UART adapter. 

### Code Example: 
Basic USB Keyboard example (types once on boot)
Type when a button is pressed

### Common Issues 
* Board not recognized as keyboard

    Double-check that:
    * You selected an ESP32-S3 board (not WROOM/WROVER).
    * USB mode / CDC+HID is enabled in Tools.
    * You’re on a recent ESP32 Arduino core.
* Can’t find ``USBHIDKeyboard`` or headers:
    * You may need to enable the new “USB” features in the core (update ESP32 core).
    * Or install Adafruit’s TinyUSB library and use its examples.
* Spamming your PC with keys:
    * Always gate ``Keyboard.print()`` behind some condition (button press, serial command, etc.).