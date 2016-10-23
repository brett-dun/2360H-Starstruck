#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           leftDrive,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port3,           rightDrive,    tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port4,           catapult1,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           catapult2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           lift,          tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!


//Functions
void extendBoomInches(float inches, int speed);
//void extendBoom(bool direction, int liftTime);
void turnDegrees(float angle , int speed);
void driveInches(float distance, int speed);

//Variables
bool extended = false;
int maxSpeed = 128;


void pre_auton() {
  bStopTasksBetweenModes = true;
}


task autonomous() {
	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}


task usercontrol() {

	while (true) {

		motor[leftDrive] = vexRT[Ch3] * (maxSpeed / 128.0);
		motor[rightDrive] = vexRT[Ch2] * (maxSpeed / 128.0);

		if(vexRT[Btn5U] && !extended) {
			nMotorEncoder[lift] = 0;
			motor[lift] = 128;
			extended = !extended;
		} else if(vexRT[Btn5D] && extended) {
			nMotorEncoder[lift] = 0;
			motor[lift] = -128;
			extended = !extended;
		}

		if(vexRT[Btn7U]) {
			maxSpeed = 128;
		} else if(vexRT[Btn7L] || vexRT[Btn7R]) {
			maxSpeed = 64;
		} else if(vexRT[Btn7D]) {
			maxSpeed = 32;
		}

		//Diameter of Gear * PI * Length of Extension Thing * Ticks Per Rotation
		const float distance = 17 / (0.5 * PI) * 627.2;
		if(nMotorEncoder[lift] >= distance || nMotorEncoder[lift] <= -distance) {
			motor[lift] = 0;
		}

	}

}

/*
	angle > 0 && speed > 0 >>> clockwise
	angle > 0 && speed < 0 >>> counterclockwise
	angle < 0 && speed > 0 >>> counterclockwise
	angle < 0 && speed < 0 >>> clockwise
*/
void turnDegrees(float angle , int speed){ // 11.5^2 + 14.75^2 = c^2
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	speed = angle < 0 ? -speed : speed;
	const float ticks = abs((angle / 360) * (sqrt(pow(11.5,2) + pow(14.75,2)) / 4) * 392);
	motor[leftDrive] = speed;
	motor[rightDrive] = -speed;
	do{
		if(abs(nMotorEncoder[leftDrive]) >= ticks) {
			motor[leftDrive] = 0;
		}
		if(abs(nMotorEncoder[rightDrive]) >= ticks) {
			motor[rightDrive] = 0;
		}
	}	while(abs(nMotorEncoder[leftDrive]) < ticks || abs(nMotorEncoder[rightDrive]) < ticks);
	motor[leftDrive] = 0;
	motor[rightDrive] = 0;
}

/*
	distance > 0 && speed > 0 >>> forward
	distance > 0 && speed < 0 >>> backward
	distance < 0 && speed > 0 >>> backward
	distance < 0 && speed < 0 >>> forward
*/
void driveInches(float distance, int speed) {
	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;
	speed = distance < 0 ? -speed :  speed;
	const float rotations = abs(distance / (4 * PI) * 392);//627.2;
	do {
		motor[leftDrive] = abs(nMotorEncoder[leftDrive]) >= abs(nMotorEncoder[rightDrive]+50) ? speed * 0.95 : speed;
		motor[rightDrive] = abs(nMotorEncoder[rightDrive]) >= abs(nMotorEncoder[leftDrive]+50) ? speed * 0.95 : speed;
		if(abs(nMotorEncoder[leftDrive]) >= rotations) {
			motor[leftDrive] = 0;
		}
		if(abs(nMotorEncoder[rightDrive]) >= rotations) {
			motor[rightDrive] = 0;
		}
	} while(abs(nMotorEncoder[leftDrive]) < rotations || abs(nMotorEncoder[rightDrive]) < rotations);
  motor[leftDrive] = 0;
  motor[rightDrive] = 0;
}

void extendBoomInches(float inches, int speed) {
	nMotorEncoder[lift] = 0;
	const float ticks = abs(inches / (0.5 * PI) * 627.2);
	do {
		motor[lift] = speed;
	} while(abs(nMotorEncoder[lift]) < ticks);
	motor[lift] = 0;
}
