//Right side autonomous
void rightStart() {

	//Open Claw
	openClaw();
	//Move the forklift up to engage the claw
	moveForkliftDegrees(10,128);

	delay(100);

	//Close Claw
	closeClaw();

	delay(100);

	//Raise Forklift
	startTask(raiseForklift);

	//Forward - push the first star over
	driveInches(50);
	//Open Claw
	openClaw();

	//Backward
	driveInches(-12);
	//Lower Claw
	moveForkliftDegrees(5,-16);
	//Forward
	driveInches(12);
	//Backward
	driveInches(-12);
	//Angle Right
	turnDegrees(25);

	//Forward - push the second star over
	driveInches(30);
	//Backward
	driveInches(-30);

	//Return to Starting Position
	turnDegrees(-25);
	squareRobot(64);

	//Lower Claw
	moveForkliftDegrees(-85,32);
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

}

//Autonomous for either side
void eitherStart() {

}

//Programming skills - start on the right
void programmingSkills() {

}
