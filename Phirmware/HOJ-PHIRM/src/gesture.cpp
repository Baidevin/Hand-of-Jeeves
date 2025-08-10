#include "gesture.h"


Gesture::Gesture(IMU* imu)
{
    _imu = imu;
}

void Gesture::update()
{
    int thisCoolGesture = _imu->getAccelX();
}