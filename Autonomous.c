//Right side autonomous
void rightStart() {

	//Open Claw
	openClaw();

	delay(300);

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
	driveInches(-30);
	//Lower Claw
	moveForkliftDegrees(10,-64);
	//Forward
	//driveInches(12);
	//Backward
	//driveInches(-12);
	//Angle Right
	turnDegrees(45);

	//Forward - push the second star over
	driveInches(40);
	//Backward
	driveInches(-24);

	//Return to Starting Position
	turnDegrees(-45);
	squareRobot(64);

	//Lower Claw
	moveForkliftDegrees(-85,64);
	//Forward
	/*driveInches(12);
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
	driveInches(-36);*/
}



//Left Side Autonomous
void leftStart() {
	//Open Claw
	openClaw();

	delay(300);

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
	driveInches(-30);
	//Lower Claw
	moveForkliftDegrees(10,-64);
	//Forward
	//driveInches(12);
	//Backward
	//driveInches(-12);
	//Angle Right
	turnDegrees(-45);

	//Forward - push the second star over
	driveInches(40);
	//Backward
	driveInches(-24);

	//Return to Starting Position
	turnDegrees(-45);
	squareRobot(64);

	//Lower Claw
	moveForkliftDegrees(-85,64);
}

//Autonomous for either side
void eitherStart() {

}

//Programming skills - start on the right
void programmingSkills() {

}
