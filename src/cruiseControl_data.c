#include <stdio.h>
#include <stdbool.h>
#include "cruiseControl.h"

#define SpeedMax 150.0
#define SpeedMin 30.0
#define SpeedInc 2.5


int checkZero(float data){
    if(data > 0){
        return 0;
    }
    else
    return 1;
}

int checkSpeedValid(float data){
	if (data<30 || data>150 ){
		return 0;
	}else{
		return 1;
	}
}

float updateCruiseSpeed(int data, float speed){
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
