void skills()
{
	//-Push the first star over

	//Open Claw
	openClaw();
	delay(450);
	//Close Claw
	closeClaw();
	delay(100);
	//Raise Forklift
	startTask(raiseForklift);
	driveInches(52.5);
	//Open Claw
	openClaw();

	//-Get the 4 preload stars

	//Backward
	driveInches(-24);
	//turns 180 degrees
	turnDegrees(180);
	//Lowers forkLift
	startTask(lowerForkLift);
	//forward
	driveInches(19);
	//Close claw
	closeClaw();
	//raises forkLift
	startTask(raiseForkLift);
	//drive backwards
	driveInches(-30);
	//turns 180 degrees
	turnDegrees(180);
	//drives to fence
	driveInches(22.5);
	//Open claw
	openClaw();

	/*
	//-get the cube
	//Backward
	driveInches(-30);
	//turns 180 degrees
	turnDegrees(180);
	//Lowers forkLift
	startTask(lowerForkLift);
	//forward
	driveInches(19);
	//Close claw
	closeClaw();
	//raises forkLift
	startTask(raiseForkLift);
	//drive backwards
	driveInches(-30);
	//turns 180 degrees
	turnDegrees(180);
	//drives to fence
	driveInches(22.5);
	//Open claw
	openClaw();

	//-get the last preload cube

	//Backward
	driveInches(-30);
	//turns 180 degrees
	turnDegrees(180);
	//Lowers forkLift
	startTask(lowerForkLift);
	//forward
	driveInches(19);
	//Close claw
	closeClaw();
	//raises forkLift
	startTask(raiseForkLift);
	//drive backwards
	driveInches(-30);
	//turns 180 degrees
	turnDegrees(180);
	//drives to fence
	driveInches(22.5);
	//Open claw
	openClaw();

	//-get the cube in the middle
	driveInches(-12.125);
	startTask(lowerForklift);
	turnDegrees(90);
	driveInches(27);
	closeClaw();
	startTask(raiseForklift);
	driveInches(48);
	turnDegrees(-90);
	driveInches(24);

	//Go to the other side of the fence and dump it so that the stars on fence fall

	//reverse and get the cube on the loading tile

	//turn to the left and get the starts near the fence in the center

	//and dump them so that the stars in the middle fall*/
}

void skills2() {
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
	driveInches(-30);
	//Lower Claw
	//moveForkliftDegrees(10,-64);
	//Forward
	//driveInches(12);
	//Backward
	//driveInches(-12);
	//Angle Right
	turnDegrees(-35);

	//Forward - push the second star over
	driveInches(35);
	//Backward
	driveInches(-30);

	//Return to Starting Position
	turnDegrees(165);
	driveInches(-12);

	//Lower Claw
	moveForkliftDegrees(-95,64);
	//Forward
	driveInches(30);
	//Close Claw
	closeClaw();
	delay(100);
	moveForkliftDegrees(35,128);
	squareRobot(64);
	startTask(raiseForklift);
	driveInches(24);
	//Turn
	turnDegrees(-150);
	driveInches(30);
	openClaw();
	driveInches(-20);
	turnDegrees(150);
	squareRobot(64);
}

void skills3() {
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
	while(true) {
		//Open Claw
		openClaw();
		delay(1000);

		//Backward
		driveInches(-16);

		//
		turnDegrees(135);
		moveForkliftDegrees(95,-64);
		turnDegrees(135);

		//Forward
		driveInches(8);
		delay(2000);
		//Close Claw
		closeClaw();
		delay(100);

		driveInches(-8);

		//Turn

		turnDegrees(-135);
		moveForkliftDegrees(95,127);
		turnDegrees(-135);


		driveInches(12);

	}
}
