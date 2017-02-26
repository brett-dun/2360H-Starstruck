#include <PrimaryData.c> //Primary autonomous -
//#include <SecondaryData.c> //Secondary autonomous -

void left();
void right();


void playback() {

	if(SensorValue[jumper])
		left();
	else
		right();

	motor[leftDrive] = 0;
	motor[rightDrive] = 0;
	motor[forklift1] = 0;
	motor[forklift2] = 0;
	motor[forklift3] = 0;

}


void left() {

	int enableClaw = 1;
	int leftJoystick = 0;
	int rightJoystick = 0;
	int button5U = 0;
	int button6U = 0;
	int button6D = 0;

	clearTimer(T1);

	//Loop through this 100 times a second for n number of seconds
	for(int i = 0; i < 100 * 15; i++) {

		leftJoystick = leftData[i][0];
		rightJoystick = leftData[i][1];
		button5U = leftData[i][2] / 100;
		button6U = (leftData[i][2] / 10) % 10;
		button6D = leftData[i][2] % 10;

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

		delay(10);

	}
}


void right() {

	int enableClaw = 1;
	int leftJoystick = 0;
	int rightJoystick = 0;
	int button5U = 0;
	int button6U = 0;
	int button6D = 0;

	clearTimer(T1);

	//Loop through this 100 times a second for n number of seconds
	for(int i = 0; i < 100 * 15; i++) {

		leftJoystick = rightData[i][0];
		rightJoystick = rightData[i][1];
		button5U = rightData[i][2] / 100;
		button6U = (rightData[i][2] / 10) % 10;
		button6D = rightData[i][2] % 10;

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

		delay(10);

	}
}
