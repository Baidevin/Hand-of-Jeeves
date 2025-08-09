
#include <stdio.h>
//#include <ADCTouch.h>


// T0 -> I2C INT -> GPIO4
// T1 -> BOOT -> GPIO0
// T7 -> D1 -> GPIO27
// T6 -> D0 -> MTMS -> GPIO14
// T5 -> PWM1 -> MTDI -> GPIO12
// T4 -> PWM0 -> GPIO13
// T3 -> G0 -> GPIO15
// T2 -> stat_led -> GPIO2

int Button_0 = 4;
int Button_1 = 0;
int Button_2 = 2;

enum touchSensors {
  TOUCH0 = 4,
  TOUCH1 = 0,
  TOUCH2 = 2,
  TOUCH3 = 15,
  TOUCH4 = 13,
  TOUCH5 = 12,
  TOUCH6 = 14,
  TOUCH7 = 27,
};

void setup() {
  Serial.begin(115200); // Initialize serial communication at 115200 baud
  delay(1000);          // Short delay to allow serial monitor to open
  Serial.println("ESP32 Touch Test");
}

void loop() {
  // Read the value from touch pin 0 (T0), which corresponds to GPIO 4.
  // You can use either the touch sensor number (T0) or the GPIO number (4).

  // int movingAverage = 0;

  // for (int i=0; i<5; i++){
  //   movingAverage += touchRead(TOUCH0);
  // };

  Serial.println("Button 0 I2C Int:"); 
  Serial.println(touchRead(TOUCH0)); 
  // Serial.println("\n");
  Serial.println("Button 1 D1:"); 
  Serial.println(touchRead(TOUCH7));
  // Serial.println("\n");
    Serial.println("Button 2 G0:"); 
  Serial.println(touchRead(TOUCH3));

  Serial.println("Button 3 PWM1:"); 
  Serial.println(touchRead(TOUCH5));
  delay(10); // Wait for 10 milliseconds before the next reading
}
