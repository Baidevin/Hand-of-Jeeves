#include "gesture.h"


Gesture::Gesture(IMU* imu)
{
    _imu = imu;
}

void Gesture::update()
{
    int thisCoolGesture = _imu->getAccelX();
}

int Gesture::getGesture()
{
    if (_imu->getAccelX() > 100)
    {
        return GESTURE_PUNCH;
    }
}