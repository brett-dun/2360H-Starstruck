
void cube(bool leftStart) {

	openClaw(); //Deploy Claw
	delay(250);
	startTask(maintainForkliftDown);
	closeClaw();
	driveInches(10);

	/*if(leftStart) //Turn to move star out of the way
		targetAngle(340,true);
	else
		targetAngle(20,false);

	if(leftStart) //Turn back to original position
		targetAngle(0,false);
	else
		targetAngle(0,true);*/

	openClaw();
	driveInches(23);
	closeClaw(); //Grab Cube
	startTask(raiseForklift);
	driveInches(14);

	if(leftStart) //Turn towards fence
		targetAngle(45,false);
	else
		targetAngle(315,true);

	startTask(maintainForkliftUp);
	driveInches(40);
	openClaw(); //Drop cube
	delay(200);
	driveInches(-24);

	if(leftStart)
		targetAngle(0,true);
	else
		targetAngle(0,false);

	startTask(lowerForklift);
	driveInches(-64);

	if(leftStart) //Turn towards stars
		targetAngle(310,true);
	else
		targetAngle(50,false);

	startTask(maintainForkliftDown);
	driveInches(25);
	startTask(maintainForkliftDown);
	driveInches(25);
	closeClaw(); //Grab stars

	if(leftStart) //Turn towards fence
		targetAngle(50,false);
	else
		targetAngle(310,true);

	startTask(raiseForklift);
	driveInches(55);
	motor[backLeft] = 128;
	motor[frontLeft] = 128;
	motor[backRight] = 128;
	motor[frontRight] = 128;

	delay(500);

	motor[backLeft] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[frontRight] = 0;
	openClaw(); //Drop stars
}



void backStars(bool leftStart) {
	openClaw();
	delay(500);
	startTask(maintainForkliftDown);
	driveInches(22.5);
	startTask(maintainForkliftDown);
	driveInches(22.5);
	closeClaw();
	delay(100);
	driveInches(-45);
	startTask(raiseForklift);

	if(leftStart)
		targetAngle(90,false);
	else
		targetAngle(270,true);

	driveInches(37);
	startTask(maintainForkliftUp);
	driveInches(30);

	openClaw();
	delay(200);
	squareRobot();
	driveInches(12);

	if(leftStart)
		targetAngle(185,false);
	else
		targetAngle(175,true);

	startTask(lowerForklift);
	driveInches(6);
	startTask(maintainForkliftDown);
	delay(1200);
	closeClaw();
	delay(200);
	driveInches(-6);

	if(leftStart)
		targetAngle(110,true);
	else
		targetAngle(250,false);

	startTask(raiseForklift);
	driveInches(50);
	startTask(maintainForkliftUp);
	driveInches(10);
	openClaw();
}



void frontStars(bool leftStart) {
	openClaw();
	delay(500);
	closeClaw();
	startTask(raiseForklift);
	driveInches(65);
	openClaw(); //Drop stars
	delay(200);
	squareRobot();
	driveInches(12);

	if(leftStart)
		targetAngle(80,false);
	else
		targetAngle(280,true);

	startTask(lowerForklift);
	driveInches(6);
	delay(1200);
	closeClaw();
	delay(200);
	driveInches(-6);

	if(leftStart)
		targetAngle(20,true);
	else
		targetAngle(340,false);

	startTask(raiseForklift);
	driveInches(63);
	openClaw();

}



void skills() {
	cube(true);
	delay(100);
	driveInches(-21);
	targetAngle(325,true);
	squareRobot();
	startTask(lowerForklift);
	driveInches(36);

	for(int i = 0; i < 4; i++) {
		targetAngle(240,true);
		startTask(maintainForkliftDown);
		delay(2000);
		closeClaw();
		delay(100);
		startTask(raiseForklift);
		targetAngle(50,false);
		startTask(maintainForkliftUp);
		driveInches(31);
		startTask(maintainForkliftUp);
		driveInches(15);
		openClaw();
		delay(100);
		driveInches(-20);
		startTask(lowerForklift);
	}
}
