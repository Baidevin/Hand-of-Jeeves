#pragma once
#include <Arduino.h>
#include "IMU.h"

enum gestures {
    GESTURE_PUNCH,
    GESTURE_SWING,
    GESTURE_ROTATE
};

class Gesture
{
    private:
    IMU* _imu;
    float _abs_acc;

    public:
    Gesture(IMU* imu);
    void update();
    int getGesture();
    void absolute_acc();
};