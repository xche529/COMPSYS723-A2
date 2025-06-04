//The type 'string' is defined as 'char*' in Esterel, hence passing a string by referenc  is 'char**'
//Aviod naming a function 'recv'
int check_speed(float data);
int check(float data);
float saturateThrottle(float throttleIn, int* saturate);
float regulateThrottle(int isGoingOn, float cruiseSpeed, float vehicleSpeed);
float updateCruiseSpeed(int data, float speed);
