#include "Motor.h"

Motor motorObj(9,10,11,1);

void setup() {
  Serial.begin(9600);      // open the serial port at 9600 bps:
  motorObj.enable();
  motorObj.setDir(1);  
}

void loop() {
 motorObj.setSpeed(100);
}
