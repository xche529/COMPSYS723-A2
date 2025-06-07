#include<stdio.h>
#include<stdlib.h>
#include "cruiseControl.h"
#include <stdbool.h>
#define PedalsMin 3.0
#define SpeedMax 150.0
#define SpeedMin 30.0
#define SpeedInc 2.5

/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: throttleIn - throttle input
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float saturateThrottle(float throttleIn, int* saturate)
{
	static const float THROTTLESATMAX = 45.0;
	if (throttleIn > THROTTLESATMAX) {
		*saturate = 1;
		return THROTTLESATMAX;
	}
	else if (throttleIn < 0) {
		*saturate = 1;
		return 0;
	}
	else {
		*saturate = 0;
		return throttleIn;
	}
}

/*
DESCRIPTION: Saturate the throttle command to limit the acceleration.
PARAMETERS: isGoingOn - true if the cruise control has just gone into the ON state 
                        from another state; false otherwise
            saturate - true if saturated, false otherwise
RETURNS: throttle output (ThrottleCmd)
*/
float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed)
{
	static const float KP = 8.113;
	static const float KI = 0.5;
	static int saturate = 1;
	static float iterm = 0;
	
	if (isGoingOn==1) {
		iterm = 0;	// reset the integral action
		saturate = 1;	
	}
	float error = cruiseSpeed - vehicleSpeed;
	float proportionalAction = error * KP;
	if (saturate==1)
		error = 0;	// integral action is hold when command is saturated
	iterm = iterm + error;
	float integralAction = KI * iterm;
	return saturateThrottle(proportionalAction + integralAction, &saturate);
}


//  check if the speed is in the speed limit
int check_speed(float data){
	if (data<30 || data>150 ){
		return 0;
	}else{
		return 1;
	}
}

// check if the accel pedal and brake been press
int check(float data){
	if (data < PedalsMin ){
		return 0;
	}else{
		return 1;
	}
}


float updateCruiseSpeed(int data, float speed){
	if(data == 0){
		return 0.0;
	}
    if(data == 1){
        speed += SpeedInc;
    }else if(data == 2){
        speed -= SpeedInc;
    }
    if (speed > SpeedMax){
        speed = SpeedMax;
    }else if (speed < SpeedMin){
        speed = SpeedMin;
    }
    return speed;
}


