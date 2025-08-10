#include <Arduino.h>

#include "BleGamepad.h"
#include "inputs.h"
#include "IMU.h"
#include "gesture.h"

#define LED_BUILTIN 2

BleGamepad gamepad = BleGamepad("Jeeve's Glove", "Ministry of Jeeves", uint8_t(69), false);

IMU imu = IMU();

Gesture gesture = Gesture(&imu);

Controller inputController = Controller(&gamepad);

void setup()
{
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  gamepad.begin();
  gamepad.configuration.setVid(10422);
  gamepad.configuration.setPid(0xbbac);
  Serial.println("Gamepad started");
  imu.begin();
  Serial.println("IMU started");
}

void loop() 
{
  Serial.println("Looping...");
  // gamepad.press(BUTTON_1);
  // gamepad.release(BUTTON_1);
  imu.update();
  Serial.print("Accel X: ");
  Serial.print(imu.getAccelX());
  Serial.print(" Accel Y: ");
  Serial.print(imu.getAccelY());
  Serial.print(" Accel Z: ");
  Serial.print(imu.getAccelZ());
  // Serial.print(" Gyro X: ");
  // Serial.print(imu.getGyroX());
  // Serial.print(" Gyro Y: ");
  // Serial.print(imu.getGyroY());
  // Serial.print(" Gyro Z: ");
  // Serial.println(imu.getGyroZ());
  delay(500);
  inputController.update();
}