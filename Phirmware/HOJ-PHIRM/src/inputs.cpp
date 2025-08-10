// owe
#include <Arduino.h>
#include "inputs.h"
#include "touch.h"
#include "BleGamepad.h"

#include "gesture.h"


Controller::Controller(BleGamepad* gamepad)
{
    _gamepad = gamepad;
}

void Controller::update()
{
    // Update the touch sensors
    indexFinger.update();
    middleFinger.update();
    ringFinger.update();
    pinkieFinger.update();

    // dUpSensor.update();
    // dDownSensor.update();
    // dLeftSensor.update();
    // dRightSensor.update();

    // _gamepad->press(0x01);

    handleFingerSensor(indexFinger.getSensorState(), BUTTON_1, BUTTON_2, BUTTON_3);
    handleFingerSensor(middleFinger.getSensorState(), BUTTON_4, BUTTON_5, BUTTON_6);
    handleFingerSensor(ringFinger.getSensorState(), BUTTON_7, BUTTON_8, BUTTON_9);
    handleFingerSensor(pinkieFinger.getSensorState(), BUTTON_10, BUTTON_11, BUTTON_12);
}

void Controller::handleFingerSensor(int state, int button1, int button2, int button3)
{
    switch (state)
    {
        case TOUCHTHUMB:
            _gamepad->press(button1);
            Serial.print("Button ");
            Serial.print(button1);
            Serial.println(" pressed.");
            break;
        case TOUCHLOWERPALM:
            _gamepad->press(button2);
            Serial.print("Button ");
            Serial.print(button2);
            Serial.println(" pressed.");
            break;
        case TOUCHUPPERPALM:
            _gamepad->press(button3);
            Serial.print("Button ");
            Serial.print(button3);
            Serial.println(" pressed.");
            break;
        case NONE:
            if (_gamepad->isPressed(button1)) {
                _gamepad->release(button1);
                Serial.print("Button ");
                Serial.print(button1);
                Serial.println(" released.");
            }
            if (_gamepad->isPressed(button2)) {
                _gamepad->release(button2);
                Serial.print("Button ");
                Serial.print(button2);
                Serial.println(" released.");
            }
            if (_gamepad->isPressed(button3)) {
                _gamepad->release(button3);
                Serial.print("Button ");
                Serial.print(button3);
                Serial.println(" released.");
            }
            break;
    }
}