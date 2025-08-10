#include "gesture.h"


Gesture::Gesture(IMU* imu)
{
    _imu = imu;
}

void Gesture::absolute_acc()
{
      _abs_acc =  (_imu->getAccelX())*(_imu->getAccelX()) + (_imu->getAccelY())*(_imu->getAccelY()) + (_imu->getAccelZ())*(_imu->getAccelZ());
}

void Gesture::update() // udated IMU so a new gesture can be computed
{
    // int thisCoolGesture = _imu->getAccelX();
    _imu->update();
    absolute_acc();
}


int Gesture::getGesture() // computes if gesture occured
{

    if ( _abs_acc > 10)
    {
        return GESTURE_PUNCH;
    }
    return GESTURE_NONE;
}