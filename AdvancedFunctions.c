void highHangAlign();
task extendBoomFull();

//Highly Experimental
void highHangAlign() {

	const float target = 6.5;
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

	extendBoomInches(-1);

}

task extendBoomFull() {
	extendBoomInches(17.5);
}

task raiseForklift() {
	moveForkliftDegrees(90,128);
}
task lowerForklift() {
	moveForkliftDegrees(85,-64);
}
