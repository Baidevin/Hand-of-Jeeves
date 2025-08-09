#include <Arduino.h>

class IMU {
public:
    IMU();
    void begin();
    void update();
    float getAccelX();
    float getAccelY();
    float getAccelZ();
    float getGyroX();
    float getGyroY();
    float getGyroZ();

private:
    float accelX, accelY, accelZ;
    float gyroX, gyroY, gyroZ;
};