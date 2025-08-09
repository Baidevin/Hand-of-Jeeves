#include <Arduino.h>

#include "BleGamepad.h"
#include "inputs.h"

#define LED_BUILTIN 2

BleGamepad gamepad = BleGamepad("Jeeve's Glove", "Ministry of Jeeves", uint8_t(69), false);

Controller inputController = Controller(&gamepad);

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  gamepad.begin();
  gamepad.configuration.setVid(10422);
  gamepad.configuration.setPid(0xbbac);
  Serial.println("Gamepad started");
}

void loop() 
{
  
}