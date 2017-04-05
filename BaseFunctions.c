/*	Status of Each Function
- driveInches:
- turnDegrees:
- turnDegreesGyro:
- moveForkliftDegrees:
- openClaw:
- closeClaw:
*/

const float WHEEL_DIAMETER = 4;
float sixBarTarget = -40; //starting position
float gyroValue, angleDiff;

/*
	distance > 0 >>> forward
	distance < 0 >>> backward
*/
void driveInches(float distance) {

	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[frontLeft] = 0;
	nMotorEncoder[backRight] = 0;
	nMotorEncoder[frontRight] = 0;

	const float max = distance < 0 ? -128 : 128;
	const float ticks = abs(distance / (WHEEL_DIAMETER * PI) * 392); //will always be positive

	float leftAverage = 0;
	float rightAverage = 0;
	float average = 0;
	float speed = 0;
	float leftSpeed = 0;
	float rightSpeed = 0;

	do {

		leftAverage = ( abs(nMotorEncoder[backLeft]) + abs(nMotorEncoder[frontLeft]) ) / 2.0;
		rightAverage = ( abs(nMotorEncoder[backRight]) + abs(nMotorEncoder[frontRight]) ) / 2.0;
		average = ( leftAverage + rightAverage ) / 2.0;

		speed = atan(0.00125*3*(ticks - average)) / (PI/2) * max;

		if(leftAverage < rightAverage) {
			leftSpeed = speed;
			rightSpeed = speed - atan(0.5 *(average-leftAverage)) / (PI/2) * speed;
		} else {
			leftSpeed = speed - atan(0.5 *(average-rightAverage)) / (PI/2) * speed;
			rightSpeed = speed;
		}

		motor[backLeft] = leftSpeed;
		motor[frontLeft] = leftSpeed;
		motor[backRight] = rightSpeed;
		motor[frontRight] = rightSpeed;

	} while(leftAverage < ticks || rightAverage < ticks);

  motor[backLeft] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[frontRight] = 0;

}

/*
	angle > 0 >>> clockwise
	angle < 0 >>> counterclockwise
*/
void turnDegrees(float angle){
 // 14.5, 15, diameter = 20.86, 1 tick = 0.1431 degrees
	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[frontLeft] = 0;
	nMotorEncoder[backRight] = 0;
	nMotorEncoder[frontRight] = 0;

	float desiredTicks = angle/0.14308;

	while(abs(nMotorEncoder[backLeft]) < desiredTicks) {
		motor[backLeft] = 5 + 64 * atan(0.00125 * (desiredTicks-abs(nMotorEncoder[backLeft])));
		motor[frontLeft] = 5 + 64 * atan(0.00125 * (desiredTicks-abs(nMotorEncoder[frontLeft])));
		motor[backRight] = -5 -64 * atan(0.00125 * (desiredTicks-abs(nMotorEncoder[backRight])));
		motor[frontRight] = -5 -64 * atan(0.00125 * (desiredTicks-abs(nMotorEncoder[frontRight])));
	}
	motor[backLeft] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[frontRight] = 0;


/*	nMotorEncoder[backLeft] = 0;
	nMotorEncoder[frontLeft] = 0;
	nMotorEncoder[backRight] = 0;
	nMotorEncoder[frontRight] = 0;

	const float max = angle < 0 ? -64 : 64;
	const float ticks = abs(angle / 360.0) * (sqrt(pow(15.125,2) + pow(14,2))) / WHEEL_DIAMETER *  392;
																						// 11.5^2 + 14.75^2 = c^2

	float leftAverage = 0;
	float rightAverage = 0;
	float total = 0;
	float speed = 0;
	float leftSpeed = 0;
	float rightSpeed = 0;

	motor[backLeft] = max;
	motor[frontLeft] = max;
	motor[backRight] = -max;
	motor[frontRight] = -max;

	do {

		leftAverage = ( abs(nMotorEncoder[backLeft]) + abs(nMotorEncoder[frontLeft]) ) / 2.0;
		rightAverage = ( abs(nMotorEncoder[backRight]) + abs(nMotorEncoder[frontRight]) ) / 2.0;

		leftSpeed = -atan( abs(ticks - leftAverage) / 64.0 ) / (PI/2) * max;//-(atan(0.5 *(ticks - leftAverage)) / (PI/2) * max + speed);
		rightSpeed = atan( abs(ticks - leftAverage) / 64.0 ) / (PI/2) * max;//atan(0.5 *(ticks - rightAverage)) / (PI/2) * max + speed;

		motor[backLeft] = leftSpeed;
		motor[frontLeft] = leftSpeed;
		motor[backRight] = rightSpeed;
		motor[frontRight] = rightSpeed;

	}	while(leftAverage < ticks || rightAverage < ticks);

	motor[backLeft] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[frontRight] = 0; */
}

/*
	angle > 0 >>> clockwise
	angle < 0 >>> counterclockwise
*/
void turnDegreesGyro(float angle){

	const float max = angle < 0 ? -32 : 32;

	float initial = SensorValue[gyro] / 10.0;
	initial = initial > 0 ? initial : 360-initial;
	//float angleDiff = 0;
	float speed = 0;
	float leftSpeed = 0;
	float rightSpeed = 0;

	motor[backLeft] = max;
	motor[frontLeft] = max;
	motor[backRight] = -max;
	motor[frontRight] = -max;

	do {

		gyroValue = SensorValue[gyro];

		float temp = (360 - SensorValue[gyro] / 10.0) + initial;
		angleDiff = angleDiff < 360 - angleDiff ? temp : 360 - temp;

		speed = max; //atan(angle - angleDiff) / (PI/2) * max;

		leftSpeed = -speed;
		rightSpeed = speed;

		motor[backLeft] = leftSpeed;
		motor[frontLeft] = leftSpeed;
		motor[backRight] = rightSpeed;
		motor[frontRight] = rightSpeed;

	}	while(angleDiff < angle);

	motor[backLeft] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[frontRight] = 0;
}


/*
	angle > 0 >>> raise
	angle < 0 >>> lower
*/
void moveForkliftDegrees(float angle) {

	float initial = SensorValue[sixBar];
	float speed = angle < 0 ? -128 : 128;

	const float ticks = abs((angle/360.0) * 360);

	do {

		motor[forklift1] = speed;
		motor[forklift2] = speed;
		motor[forklift3] = speed;
		motor[forklift4] = speed;
		motor[forklift5] = speed;

	} while(abs(SensorValue[sixBar]-initial) < ticks);

	motor[forklift1] = 0;
	motor[forklift2] = 0;
	motor[forklift3] = 0;
	motor[forklift4] = 0;
	motor[forklift5] = 0;

}

task maintainForklift() {

	while(true) {

		float speed = atan(sixBarTarget-SensorValue[sixBar]) * 128;

		motor[forklift1] = speed;
		motor[forklift2] = speed;
		motor[forklift3] = speed;
		motor[forklift4] = speed;
		motor[forklift5] = speed;

	}

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
