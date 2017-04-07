
void cube(bool leftStart) {

	openClaw();
	delay(250);
	startTask(maintainForkliftDown);
	closeClaw();
	driveInches(10);

	if(leftStart)
		targetAngle(340,true);
	else
		targetAngle(20,false);

	if(leftStart)
		targetAngle(0,false);
	else
		targetAngle(0,true);

	openClaw();
	driveInches(23);
	closeClaw();
	startTask(raiseForklift);
	driveInches(14);

	if(leftStart)
		targetAngle(45,false);
	else
		targetAngle(315,true);

	startTask(maintainForkliftUp);
	driveInches(40);
	openClaw();
	delay(200);
	driveInches(-24);

	if(leftStart)
		targetAngle(0,true);
	else
		targetAngle(0,false);

	startTask(lowerForklift);
	driveInches(-64);

	if(leftStart)
		targetAngle(310,true);
	else
		targetAngle(50,false);

	startTask(maintainForkliftDown);
	driveInches(50);
	closeClaw();

	if(leftStart)
		targetAngle(50,false);
	else
		targetAngle(310,true);

	startTask(raiseForklift);
	driveInches(55);
	openClaw();
}



void backStars(bool leftStart) {
	openClaw();
	delay(500);
	startTask(maintainForkliftDown);
	driveInches(45);
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
}



void frontStars(bool leftStart) {
	openClaw();
	delay(250);
	moveForkliftDegrees(95);
	driveInches(54);
	openClaw();
	driveInches(-24);

	if(leftStart)
		targetAngle(30,false);
	else
		targetAngle(330,true);

	driveInches(30);
	driveInches(-30);

	if(leftStart)
		targetAngle(170,false);
	else
		targetAngle(190,true);
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
