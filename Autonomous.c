//Define functions and tasks
void rightStart();
void leftStart();
void eitherStart();
task bringBoomHome();
task auto1();
task auto2();
task auto3();
task auto4();
void highHangAlign();
task extendBoomFull();


//Right side autonomous
void rightStart() {

	//Move the forklift up to engage the claw
	moveForkliftDegrees(10,128);

	//Open Claw
	openClaw();
	//Lift Claw Up
	moveForkliftDegrees(40+45,128);

	//Forward - push the first star over
	driveInches(48);

	//Backward
	driveInches(-24);
	//Angle Right
	turnDegrees(25);

	//Forward - push the second star over
	driveInches(24/sinDegrees(25));

	//Backward
	driveInches(-24/sinDegrees(25));
	//Angle Right
	turnDegrees(25);

	//Forward - push the third star over
	driveInches(24/sinDegrees(50));
	//Backward
	driveInches(-24/sinDegrees(50));

	//Return to Starting Position
	turnDegrees(-50);
	squareRobot(64);

	//Lower Claw
	moveForkliftDegrees(-50-45,32);
	//Forward
	driveInches(12);
	//Turn Right
	turnDegrees(90);
	//Forward
	driveInches(6);

	//Close Claw - Pickup star next to the starting position
	closeClaw();
	//Backward
	driveInches(-6);
	//Turn Left
	turnDegrees(-90);
	//Forward
	driveInches(24);
	//Open Claw
	openClaw();
	//Backward
	driveInches(-24);
	//Turn Left
	turnDegrees(-90);
	//Forward
	driveInches(24);
	//Close claw - pickup a few more stars next to the starting position
	closeClaw();
	//Turn Right
	turnDegrees(90);
	//Forward - push cube into near zone
	driveInches(24);
	//Open Claw - release the stars
	openClaw();
	//Back
	driveInches(-36);
}

//Left Side Autonomous
void leftStart() {
	extendBoomInches(7,128);
	startTask(auto1);
	startTask(auto3);
}

//Autonomous for either side
void eitherStart() {
	extendBoomInches(7,128);
	startTask(auto1);
	startTask(auto2);
}

task bringBoomHome() {
	extendBoomInches(-14.5,128);
	wait1Msec(320);
	motor[lift] = 0;
}
task auto1() {
	extendBoomInches(7,128);
}
task auto2() {
	//driveInches(4*sqrt(24*24*2), 127);
	driveInches(3*24);
	delay(1000);
	driveInches(-18);
	startTask(bringBoomHome);
}
task auto3() {
	driveInches(3*24);
	driveInches(-2*24);
	turnDegrees(90);
	startTask(bringBoomHome);
	driveInches(2.5*24);
}
task auto4() {
	driveInches(3*24);
	driveInches(-2*24);
	turnDegrees(-80);
	startTask(bringBoomHome);
	driveInches(2.5*24);
}
/*
task forwardBackwardCubeRightStart() {
	extendBoomInches(7,128);
	startTask(auto1);
	startTask(auto4);
}
*/


//Highly Experimental
void highHangAlign() {

	const float target = 6.5
	const float max = 64;

	float average = 0;
	float speed = 0;

	startTask(extendBoomFull);

	do {

		average = (SensorValue[leftSonar] + SensorValue[rightSonar]) / 2;
		speed = atan(0.5*(target-average)) / (PI/2) * max;

		motor[leftDrive] = atan(0.5*(average-SensorValue[leftSonar])) / (PI/2) * max + speed;
		motor[rightDrive] = atan(0.5*(average-SensorValue[rightButton])) / (PI/2) * max + speed;

	} while(SensorValue[leftSonar] > target || SensorValue[rightSonar] > target);

}
task extendBoomFull() {
	extendBoomInches(17.5,128);
}
