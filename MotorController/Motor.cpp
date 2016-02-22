/*
  Motor.cpp - Library for controlling stepper motor.
  Created by Seyed Ehsan Abrishami, Feb 21, 2016.
  Released into the public domain. 
  An email has to be sent to the owner with feedback on the code. 
  Owner Email : a.ehsan70@gmail.com
*/

#include "Arduino.h"
#include "Motor.h"

Motor::Motor(){
	Serial.print("Hi");
}


Motor::Motor(int enPin, int dirPin, int clkPin, int gndPin){
    _enPin = enPin; 
    _dirPin = dirPin;
    _clkPin = clkPin;
    pinMode(_enPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);
    pinMode(_clkPin, OUTPUT);
}

void Motor::setDir(int dir){
	if (dir == 1){
		digitalWrite(_dirPin, HIGH);  
	}
	else if (dir == 0){
		digitalWrite(_dirPin, LOW); 
	}
	else {
		Serial.print("Wrong Input to setDir().");
	}
}

void Motor::enable(){
	digitalWrite(_enPin, HIGH);
}
/*
speedIn would be half of the period in ms. i.e. the lenght of the signla to be high or low. 
*/
void Motor::setSpeed(int speedIn)
{
	if (speedIn < 1) {
		Serial.print("Wrong Input to setSpeed(): Speed value cannot be negative.");
	}

	digitalWrite(_clkPin, HIGH);
	delay(speedIn);
	digitalWrite(_clkPin, LOW);
	delay(speedIn);  
}

void Motor::disable()
{
	digitalWrite(_enPin, LOW);

}
