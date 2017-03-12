//#include <PrimaryData.c> //Primary autonomous -
#include <SecondaryData.c> //Secondary autonomous -

const int LEFT_SIZE = sizeof(leftData)/sizeof(leftData[0]); //length of the left array
const int RIGHT_SIZE = sizeof(rightData)/sizeof(rightData[0]); //length of the right array
const int EITHER_SIZE = sizeof(eitherData)/sizeof(eitherData[0]);

void left() {

	unsigned int enableClaw = 1;
	int leftJoystick = 0;
	byte rightJoystick = 0;
	unsigned int button5U = 0;
	unsigned int button6U = 0;
	unsigned int button6D = 0;

	clearTimer(T1);

	//Loop through this 100 times a second for n number of seconds
	for(int i = 0; i < LEFT_SIZE; i++) {

		//Set the variable to the recorded value
		leftJoystick = leftData[i][0];
		rightJoystick = leftData[i][1];
		//Decode recorded values for the remaining variables
		button5U = ((unsigned int) leftData[i][2]) & 1; //Gives value of the first bit
		button6U = (((unsigned int) leftData[i][2]) >> 1) & 1; //Gives value of the second bit
		button6D = (((unsigned int) leftData[i][2]) >> 2) & 1; //Gives value of the third bit

		motor[frontLeftDrive] = leftJoystick;
		motor[backLeftDrive] = leftJoystick;
		motor[frontRightDrive] = rightJoystick;
		motor[backRightDrive] = rightJoystick;

		if(!button6U && !button6D) {
			//Stop forklift
			motor[forklift1] = 0;
			motor[forklift2] = 0;
			motor[forklift3] = 0;
			motor[forklift4] = 0;
			motor[forklift5] = 0;
		} if(button6U) {
			//Raise forklift
			motor[forklift1] = 128;
			motor[forklift2] = 128;
			motor[forklift3] = 128;
			motor[forklift4] = 128;
			motor[forklift5] = 128;
		} else if(button6D) {
			//Lower forklift
		 	motor[forklift1] = -128;
			motor[forklift2] = -128;
			motor[forklift3] = -128;
			motor[forklift4] = -128;
			motor[forklift5] = -128;
		}

		if(button5U && enableClaw) {
			SensorValue[claw] = !SensorValue[claw];
			enableClaw = 0;
			clearTimer(T1);
		}

		if(time1(T1) > 250) {
			enableClaw = 1; //enable claw
		}

		delay(10);

	}
}


//Same code as above but uses data for the right side
void right() {

	unsigned int enableClaw = 1;
	int leftJoystick = 0;
	int rightJoystick = 0;
	unsigned int button5U = 0;
	unsigned int button6U = 0;
	unsigned int button6D = 0;

	clearTimer(T1);

	//Loop through this 100 times a second for n number of seconds
	for(int i = 0; i < RIGHT_SIZE; i++) {

		//Set the variable to the recorded value
		leftJoystick = rightData[i][0];
		rightJoystick = rightData[i][1];
		//Decode recorded values for the remaining variables
		button5U = ((unsigned int) rightData[i][2]) & 1; //Gives value of the first bit
		button6U = (((unsigned int) rightData[i][2]) >> 1) & 1; //Gives value of the second bit
		button6D = (((unsigned int) rightData[i][2]) >> 2) & 1; //Gives value of the third bit

		motor[frontLeftDrive] = leftJoystick;
		motor[backLeftDrive] = leftJoystick;
		motor[frontRightDrive] = rightJoystick;
		motor[backRightDrive] = rightJoystick;

		if(!button6U && !button6D) {
			motor[forklift1] = 0;
			motor[forklift2] = 0;
			motor[forklift3] = 0;
			motor[forklift4] = 0;
			motor[forklift5] = 0;
		} else if(button6U) {
			motor[forklift1] = 128;
			motor[forklift2] = 128;
			motor[forklift3] = 128;
			motor[forklift4] = 128;
			motor[forklift5] = 128;
		} else if(button6D) {
		 	motor[forklift1] = -128;
			motor[forklift2] = -128;
			motor[forklift3] = -128;
			motor[forklift4] = -128;
			motor[forklift5] = -128;
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

void either() {

	unsigned int enableClaw = 1;
	int leftJoystick = 0;
	byte rightJoystick = 0;
	unsigned int button5U = 0;
	unsigned int button6U = 0;
	unsigned int button6D = 0;

	clearTimer(T1);

	//Loop through this 100 times a second for n number of seconds
	for(int i = 0; i < LEFT_SIZE; i++) {

		//Set the variable to the recorded value
		leftJoystick = eitherData[i][0];
		rightJoystick = eitherData[i][1];
		//Decode recorded values for the remaining variables
		button5U = ((unsigned int) eitherData[i][2]) & 1; //Gives value of the first bit
		button6U = (((unsigned int) eitherData[i][2]) >> 1) & 1; //Gives value of the second bit
		button6D = (((unsigned int) eitherData[i][2]) >> 2) & 1; //Gives value of the third bit

		motor[frontLeftDrive] = leftJoystick;
		motor[backLeftDrive] = leftJoystick;
		motor[frontRightDrive] = rightJoystick;
		motor[backRightDrive] = rightJoystick;

		if(!button6U && !button6D) {
			//Stop forklift
			motor[forklift1] = 0;
			motor[forklift2] = 0;
			motor[forklift3] = 0;
			motor[forklift4] = 0;
			motor[forklift5] = 0;
		} if(button6U) {
			//Raise forklift
			motor[forklift1] = 128;
			motor[forklift2] = 128;
			motor[forklift3] = 128;
			motor[forklift4] = 128;
			motor[forklift5] = 128;
		} else if(button6D) {
			//Lower forklift
		 	motor[forklift1] = -128;
			motor[forklift2] = -128;
			motor[forklift3] = -128;
			motor[forklift4] = -128;
			motor[forklift5] = -128;
		}

		if(button5U && enableClaw) {
			SensorValue[claw] = !SensorValue[claw];
			enableClaw = 0;
			clearTimer(T1);
		}

		if(time1(T1) > 250) {
			enableClaw = 1; //enable claw
		}

		delay(10);

	}
}
