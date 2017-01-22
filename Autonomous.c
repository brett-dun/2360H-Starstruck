//Right side autonomous
void rightStart() {

	//Open Claw
	openClaw();

	delay(450);

	//Close Claw
	closeClaw();

	delay(100);

	//Raise Forklift
	startTask(raiseForklift);

	//Forward - push the first star over
	driveInches(52.5);
	//Open Claw

	//Backward
	/*driveInches(-30);
	//Lower Claw
	//moveForkliftDegrees(10,-64);
	//Forward
	//driveInches(12);
	//Backward
	//driveInches(-12);
	//Angle Right
	turnDegrees(35);

	//Forward - push the second star over
	driveInches(35);
	//Backward
	/*driveInches(-35);

	turnDegrees(-35);
	squareRobot(64);*/

	//Return to Starting Position
	/*turnDegrees(-140);
	driveInches(-12);

	//Lower Claw
	moveForkliftDegrees(-85,64);
	//Forward
	driveInches(18);
	//Close Claw
	closeClaw();
	//Turn
	turnDegrees(65);
	openClaw();
	driveInches(-12);

	//Turn Right
	/*turnDegrees(90);
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
	driveInches(-36);*/
}



//Left Side Autonomous
void leftStart() {
	//Open Claw
	openClaw();

	delay(450);

	//Close Claw
	closeClaw();

	delay(100);

	//Raise Forklift
	startTask(raiseForklift);

	//Forward - push the first star over
	driveInches(52.5);
	//Open Claw
	openClaw();

	//Backward
	driveInches(-25);
	//Lower Claw
	//moveForkliftDegrees(10,-64);
	//Forward
	//driveInches(12);
	//Backward
	//driveInches(-12);
	//Angle Right
	/*turnDegrees(-35);

	//Forward - push the second star over
	driveInches(35);
	//Backward
	driveInches(-35);

	//Return to Starting Position
	turnDegrees(140);*/
	//driveInches(-12);
	turnDegrees(125);
	driveInches(-5)
	//Lower Claw
	moveForkliftDegrees(-105,64);
	//Forward
	driveInches(28);
	//Close Claw
	closeClaw();
	delay(100);
	startTask(raiseForklift);
	//Turn
	turnDegrees(-90);
	moveForkliftDegrees(20,128);
	driveInches(24.5);
	openClaw();
	//driveInches(-12);
}

//Autonomous for either side
void eitherStart() {

}

void mAuto() {
	//Open Claw
	openClaw();

	delay(1000);

	driveInches(72);

	closeClaw();
	delay(450);

	turnDegrees(135);

	startTask(raiseForklift);
	driveInches(43.5);

	openClaw();

}
