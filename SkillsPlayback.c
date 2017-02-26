#include <SkillsData.c>

void playback() {

	int enableClaw = 1; //Set the value of enable claw to one
	//Set the remaining variables to a default value of zero
	int leftJoystick = 0;
	int rightJoystick = 0;
	int button5U = 0;
	int button6U = 0;
	int button6D = 0;

	clearTimer(T1);

	//Loop through this 50 times a second for n number of seconds
	for(int i = 0; i < 50 * 60; i++) {

		//Set the variable to the recorded value
		leftJoystick = leftData[i][0];
		rightJoystick = leftData[i][1];
		//Decode recorded values for the remaining variables
		button5U = leftData[i][2] / 100; //Gives value of the 100s place
		button6U = (leftData[i][2] / 10) % 10; //Gives value of the 10s place
		button6D = leftData[i][2] % 10; //Gives value of the 1s place

		motor[leftDrive] = leftJoystick;
		motor[rightDrive] = rightJoystick;

		if(!button6U && !button6D) {
			motor[forklift1] = 0;
			motor[forklift2] = 0;
			motor[forklift3] = 0;
		} if(button6U) {
			motor[forklift1] = 128;
			motor[forklift2] = 128;
			motor[forklift3] = 128;
		} else if(button6D) {
		 	motor[forklift1] = -128;
			motor[forklift2] = -128;
			motor[forklift3] = -128;
		}

		if(button5U && enableClaw) {
			SensorValue[claw] = !SensorValue[claw];
			enableClaw = 0;
			clearTimer(T1);
		}

		if(time1(T1) > 250) {
			enableClaw = 1;
		}

		delay(20);

	}

	motor[leftDrive] = 0;
	motor[rightDrive] = 0;
	motor[forklift1] = 0;
	motor[forklift2] = 0;
	motor[forklift3] = 0;

}
