
float sonicSensor = SensorValue[sonarSensor];
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Movement
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void stopMotors()
{
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}
void resetEncoder()
{
	SensorValue[leftEncoder] = 0;SensorValue[rightEncoder] = 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void forward(float rotation)
{
	resetEncoder();
	while(SensorValue[leftEncoder] < rotation*360)
	{
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void backward(float rotation)
{
	SensorValue[leftEncoder] = 0;
	while(SensorValue[leftEncoder] > rotation*-360)
	{
		motor[rightMotor] = -63;
		motor[leftMotor] = -63;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void constantForward()
{
	while(true){
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Line Followers
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void forwardPastLine()
{
	resetEncoder();
	while(SensorValue[centerLineFollower]< 2000)
	{
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void backwardUntilLine()
{
	while(SensorValue[centerLineFollower]< 2000)
	{
		motor[rightMotor] = -63;
		motor[leftMotor] = -63;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	forward(1);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void upToLine()
{
	while(SensorValue[centerLineFollower]< 2000)
	{
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	while(SensorValue[leftEncoder] > 0)
	{
		motor[rightMotor] = -63;
		motor[leftMotor] = -63;
	}
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}
void leftUntilDark()
{
	while(SensorValue[leftLineFollower] > 2000){
		motor(leftMotor) = 0;
		motor(rightMotor) = 60;
}
}
void rightUntilDark()
{
	while(SensorValue[rightLineFollower] > 2000){
		motor(leftMotor) = -60;
		motor(rightMotor) = 0;
}
}
void sidewaysUntilDark()
{
	while(4<5)
	{
		rightUntilDark();
		leftUntilDark();
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Other Sensors
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*void forwardUntilBump()
{
resetEncoder();
while(SensorValue[touchSensor] == 0)
{
constantForward();
}
while(SensorValue[touchSensor] == 1)
{
stopMotors();
}
}*/
/*void spinUntilObject(int speed)
{
while(SensorValue[sonarSensor] < 0.1)
{
		motor[rightMotor] = speed;
		motor[leftMotor] = -speed;
		sonicSensor = SensorValue[sonarSensor];
}
stopMotors();
while(SensorValue[sonarSensor] > 0.2)
{
	constantForward();
	sonicSensor = SensorValue[sonarSensor];
}
stopMotors();
}*/
void forwardWithDistance(){
	while(SensorValue[sonarSensor] > 1){
	motor[rightMotor] = SensorValue[sonarSensor];
	motor[leftMotor] = SensorValue[sonarSensor];
}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void forwardUntilDistance(float distance)
{
	while(SensorValue[sonarSensor] > distance)
	{
		constantForward();
	}
	while(SensorValue[sonarSensor] <= distance)
	{
		stopMotors();
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Turning
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int degree;

void pointTurnRight(int degree)
{
	while(abs(SensorValue[gyro]) > degree*10)
	{
		motor[rightMotor] = -50;
		motor[leftMotor] = 50;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(250);
}

//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void pointTurnLeft(int degree)
{
	resetEncoder();
	while(abs(SensorValue[gyro]) < degree * 10)
	{
		motor[rightMotor] = 50;
		motor[leftMotor] = -50;
	}
	motor[rightMotor] = 0;
	motor[leftMotor] = 0;
	wait1Msec(250);
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void encoderTurnLeft(int degree)
{
	resetEncoder();
	while(SensorValue[leftEncoder] > degree * -360){
		motor[leftMotor] = -63;
		motor[rightMotor] = 63;
	}
	stopAllMotors();}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\
void encoderTurnRight(int degree)
{
	resetEncoder();
	while(SensorValue[leftEncoder] < degree * 360){
		motor[leftMotor] = 63;
		motor[rightMotor] = -63;
	}
	stopAllMotors();}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void resetGyro()
{
	if(SensorValue[gyro] != target){
		target = target + 900;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void turnAngle(float angle, float speed)
{
	resetEncoder();
	while(SensorValue[leftEncoder] < 	angle * 90)
	{
		motor[rightMotor] = speed;
		motor[leftMotor] = speed;
	}
}
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//Arm stuff
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
/*void armUp(int distance)
{
while(SensorValue[armPot] != distance)
{
motor[armMotor] = distance;
}
}*/
void forwardUntilLine()
{
	while(true){
	while(SensorValue[centerLineFollower]< 2000)
	{
		motor[rightMotor] = 63;
		motor[leftMotor] = 63;
	}
	backward(1);
	encoderTurnLeft(1);
}}
