//Right side autonomous
void rightStart() {
	//Lift Claw Up
	//moveForkliftDegrees(10,128);
	//Open Claw
	SensorValue[claw] = 0;
	//Lift Claw Up
	//moveForkliftDegrees(40+45,128);
	//Forward - push the first star over
	driveInches(48);
	//Backward
	/*driveInches(-24);
	//Angle Right
	turnDegrees(25);
	//Forward - push the second star over
	//driveInches(24/sinDegrees(25));
	//Backward
	driveInches(-24/sinDegrees(25));
	//Angle Right
	turnDegrees(25,64);
	//Forward - push the third star over
	driveInches(24/sinDegrees(50));
	//Backward
	driveInches(-24/sinDegrees(50));
	//Return to Starting Position
	turnDegrees(-50);
	driveInches(-55);
	//Lower Claw
	//moveForkliftDegrees(-50-45);
	//Forward
	driveInches(12);
	//Turn Right
	turnDegrees(90);
	//Forward
	driveInches(6);
	//Close Claw - Pickup star next to the starting position
	SensorValue[claw] = 1;
	//Backward
	driveInches(-6);
	//Turn Left
	turnDegrees(-90);
	//Forward
	driveInches(24);
	//Open Claw
	SensorValue[claw] = 0;
	//Backward
	driveInches(-24);
	//Turn Left
	turnDegrees(-90);
	//Forward
	driveInches(24);
	//Close claw - pickup a few more stars next to the starting position
	SensorValue[claw] = 1;
	//Turn Right
	turnDegrees(90);
	//Forward - push cube into near zone
	driveInches(24);
	//Open Claw - release the stars
	SensorValue[claw] = 0;
	//Back
	driveInches(-36);*/
}
