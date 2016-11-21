#include "Functions_Nov_20_2016.h"

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

void extendBoomInches(float distance, int speed) {
	nMotorEncoder[lift] = 0;
	speed = distance < 0 ? -speed :  speed;
	const float ticks = abs(distance / (0.5 * PI) * 627.2);
	do {
		motor[lift] = speed;
	} while(abs(nMotorEncoder[lift]) < ticks);
	motor[lift] = 0;
}

void moveForkliftDegrees(float angle, int speed) {
	nMotorEncoder[forklift] = 0;
	speed = angle < 0 ? -speed :  speed;
	const float ticks = abs((angle/360.0) * 5 * 627.2);
	do {
		motor[forklift] = speed;
	} while(abs(nMotorEncoder[forklift]) < ticks);
	motor[forklift] = 0;
}
