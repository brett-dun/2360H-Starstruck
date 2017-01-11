/*	Status of Each Function
- turnDegrees: working (minor adjustments may be needed to account for friction)
- driveInches: working (minor adjustments may be needed to account for friction)
- extendBoomInches: working
- moveForkliftDegrees: working
- squareRobot: working
- openClaw: working
- closeClaw: working
- engageMechStop: working
- disengageMechStop: working
*/


/*
	angle > 0 >>> clockwise
	angle < 0 >>> counterclockwise
*/
void turnDegrees(float angle){

	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;

	const float max = angle < 0 ? -128 : 128;
	const float ticks = abs((angle / 360) * (sqrt(pow(11.5,2) + pow(14.75,2)) / 4) * 627.2) / 2;
																						// 11.5^2 + 14.75^2 = c^2

	float average = 0;
	float speed = 0;

	motor[leftDrive] = -max;
	motor[rightDrive] = max;

	do {

		average = ( abs(nMotorEncoder[leftDrive]) + abs(nMotorEncoder[rightDrive]) ) / 2;
		speed = atan(0.5 * (ticks - average)) / (PI/2) * max;

		motor[leftDrive] = -(atan(0.5 *(ticks - abs(nMotorEncoder[leftDrive]))) / (PI/2) * max);
		motor[rightDrive] = atan(0.5 *(ticks - abs(nMotorEncoder[rightDrive]))) / (PI/2) * max;

	}	while(abs(nMotorEncoder[leftDrive]) < ticks || abs(nMotorEncoder[rightDrive]) < ticks);

	motor[leftDrive] = 0;
	motor[rightDrive] = 0;
}


/*
	distance > 0 >>> forward
	distance < 0 >>> backward - needs to be fixed
*/
void driveInches(float distance) {

	nMotorEncoder[leftDrive] = 0;
	nMotorEncoder[rightDrive] = 0;

	const float max = distance < 0 ? -64 : 64;
	const float ticks = abs(distance / (4 * PI) * 627.2); //will always be positive

	float speed = 0;
	float average = 0;

	do {

		average = (abs(nMotorEncoder[leftDrive]) + abs(nMotorEncoder[rightDrive])) / 2; //will always be positive
		speed = atan(0.00125*4*(ticks - average)) / (PI/2) * max;

		motor[leftDrive] = atan(0.5 *(average-abs(nMotorEncoder[leftDrive]))) / (PI/2) * speed + speed;
		motor[rightDrive] = atan(0.5 *(average-abs(nMotorEncoder[rightDrive]))) / (PI/2) * speed + speed;

	} while(abs(nMotorEncoder[leftDrive]) < ticks || abs(nMotorEncoder[rightDrive]) < ticks);

  motor[leftDrive] = 0;
  motor[rightDrive] = 0;
}


/*
	distance > 0 >>> extend
	distance < 0 >>> retract
*/
void extendBoomInches(float distance) {

	nMotorEncoder[lift] = 0;
	int speed = distance < 0 ? -128 : 128;
	const float ticks = abs(distance / (0.5 * PI) * 392);

	do {

		motor[lift] = speed;

	} while(abs(nMotorEncoder[lift]) < ticks);

	motor[lift] = 0;

}


/*
	angle > 0 && speed > 0 >>> raise
	angle > 0 && speed < 0 >>> lower
	angle < 0 && speed > 0 >>> lower
	angle < 0 && speed < 0 >>> raise
*/
void moveForkliftDegrees(float angle, int speed) {

	nMotorEncoder[leftForklift] = 0;
	speed = angle < 0 ? -speed : speed;

	const float ticks = abs((angle/360.0) * 5 * 627.2);

	do {

		motor[leftForklift] = speed;
		motor[rightForklift] = speed;

	} while(abs(nMotorEncoder[leftForklift]) < ticks);

	motor[leftForklift] = 0;
	motor[rightForklift] = 0;

}


/*
*/
void squareRobot(int speed) {

	speed = abs(speed);

	motor[leftDrive] = -speed;
	motor[rightDrive] = -speed;

	do {

		if(SensorValue[leftButton]) {
			motor[rightDrive] = 0;
		}

		if(SensorValue[rightButton]) {
			motor[leftDrive] = 0;
		}

	} while(!SensorValue[leftButton] || !SensorValue[rightButton]);

}


/*
Use these methods to avoid having to change the sensor value if the physical setup of the pneumatics changes
*/
void openClaw() {
	SensorValue[claw] = 1;
}
void closeClaw() {
	SensorValue[claw] = 0;
}
void engageMechStop() {
	SensorValue[mechStop] = 1;
}
void disengageMechStop() {
	SensorValue[mechStop] = 0;
}
