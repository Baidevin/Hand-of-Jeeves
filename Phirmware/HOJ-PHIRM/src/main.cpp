#include <Arduino.h>

#include "BleGamepad.h"
#include "packet.h"

#define LED_BUILTIN 2

BleGamepad gamepad = BleGamepad("Jeeve's Glove", "Jeeve's Chosen", uint8_t(69), false);


void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  gamepad.begin();
  gamepad.configuration.setVid(10422);
  gamepad.configuration.setPid(0xbbac);
  // gamepad.configuration.setHidReportId(100);

  gamepad.press();

  Serial.println("Gamepad started");
  Serial.println(gamepad.configuration.getFirmwareRevision());
  Serial.println(gamepad.configuration.getHardwareRevision());
  Serial.println(gamepad.configuration.getModelNumber());
  Serial.println(gamepad.configuration.getPid());
  Serial.println(gamepad.configuration.getVid());
}

void loop() 
{
  if(gamepad.isConnected()) {
    // Serial.println("Gamepad is connected"); 
    gamepad.press(BUTTON_1);
    // Serial.println("Button 1 pressed");
    gamepad.release(BUTTON_1);
  } else {
    Serial.println("Gamepad is not connected");
  }
}