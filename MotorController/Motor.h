/*
  Motor.h - Library for controlling stepper motor.
  Created by Seyed Ehsan Abrishami, Feb 21, 2016.
  Released into the public domain. 
  An email has to be sent to the owner with feedback on the code. 
  Owner Email : a.ehsan70@gmail.com
*/
#ifndef Motor_h
#define Motor_h

#include "Arduino.h"

class Motor
{
  public:
  	Motor();
  	Motor(int enPin, int dirPin, int clkPin, int gndPin);
    void enable();
    void setDir(int dir);
    void setSpeed(int speedIn);
    void disable();
  private:
    int _enPin, _dirPin, _clkPin, _gndPin;
};

#endif