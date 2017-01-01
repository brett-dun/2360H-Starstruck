#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  rightButton,    sensorTouch)
#pragma config(Sensor, dgtl2,  leftButton,     sensorTouch)
#pragma config(Sensor, dgtl3,  limitSwitch,    sensorDigitalIn)
#pragma config(Sensor, dgtl4,  leftSonar,      sensorSONAR_inch)
#pragma config(Sensor, dgtl6,  rightSonar,     sensorSONAR_inch)
#pragma config(Sensor, dgtl10, mechStop,       sensorDigitalOut)
#pragma config(Sensor, dgtl11, claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl12, led,            sensorDigitalOut)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           leftDrive,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port4,           leftForklift,  tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_3)
#pragma config(Motor,  port6,           rightForklift, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           lift,          tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port9,           rightDrive,    tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Supporting Files
#include<BaseFunctions.c>
#include <Autonomous.c>

//Variables
int maxSpeed = 128;



void pre_auton() {
  bStopTasksBetweenModes = true;
}



task autonomous() {
	if(SensorValue[limitSwitch]) {
		SensorValue[led] = 1;
		rightStart();
	} else {
		SensorValue[led] = 0;
		eitherStart();
	}
	//driveInches(40);
	//turnDegrees(90);
	//startTask(forwardBackward); //Either
	//startTask(forwardBackwardCubeLeftStart); //Blue
	//startTask(forwardBackwardCubeRightStart); //Red
}



/*
	Main Controller
	---------------
		Joysticks:
			1	[None]
			2	Right Drive Control
			3	Left Drive Control
			4	[None]
		Buttons:
			5U && 5D	Claw Control
				5U -> Open claw
				5D -> Close Claw
			6U && 6D Forklift Control
				6U -> Raise Forklift
				6D -> Lower Forklift
			7U && 7L && 7R && 7D  [None]
				7U ->
				7L && 7R ->
				7D ->
			8U && 8L && 8R && 8D Variable Drive Speed Control
				8U -> 128 maxSpeed
				8L && 8R -> 64 maxSpeed
				8D -> 32 maxSpeed

		Partner Controller
		------------------
		Joysticks:
			1	[None]
			2	[None]
			3	[None]
			4	[None]
		Buttons:
			5U && 5D	Lift Encoder Reset <<<We either need to remove this or get a partner controller for the claw.>>>
			6U && 6D  Mechanical Stop Control
				6U -> Engage Mechanical Stop
				6D -> Disengage Mechanical Stop
			7U && 7L && 7R && 7D	Lift Control
				7U -> Extend Lift
				7L && 7R -> Stop Lift
				7D -> Retract Lift
			8U && 8L && 8R && 8D	[None]
				8U ->
				8L && 8R ->
				8D ->
*/
task usercontrol() {

	nMotorEncoder[lift] = 0;

	while(true) {

		SensorValue[led] = SensorValue[limitSwitch];

		if(vexRT[Btn8U]) {
			maxSpeed = 128; //Change the maximum speed to 128 (maximum value)
		} else if(vexRT[Btn8L] || vexRT[Btn8R]) {
			maxSpeed = 64;
		} else if(vexRT[Btn8D]) {
			maxSpeed = 32; //Change the maximum speed to 32 (1/4 of the maximum value)
		}

		motor[leftDrive] = vexRT[Ch2] * (maxSpeed / 128.0);
		motor[rightDrive] = vexRT[Ch3] * (maxSpeed / 128.0);
		//motor[leftDrive] = abs(vexRT[Ch3]) >= 4 ? vexRT[Ch3] * (maxSpeed / 128.0) : 0; //left side speed is determined by the left joystick
		//motor[rightDrive] = abs(vexRT[Ch2]) >= 4 ? vexRT[Ch2] * (maxSpeed / 128.0) : 0; //right side speed is determined by the right joystick

		 /*if(vexRT[Btn7L] || vexRT[Btn7R]) { //If buttons 7L or 7R are pressed
			motor[leftForklift] = 0;
			motor[rightForklift] = 0;
		} else if(vexRT[Btn7U]) { //If button 7U is pressed
			motor[leftForklift] = 128;
			motor[rightForklift] = 128;
		} else if(vexRT[Btn7D]) { //If button 7D is pressed
			motor[leftForklift] = -32;
			motor[rightForklift] = -32;
		}*/
		if(!vexRT[Btn6U] && !vexRT[Btn6D]) {
			motor[leftForklift] = 0;
			motor[rightForklift] = 0;
		} if(vexRT[Btn6U]) {
			motor[leftForklift] = 128;
			motor[rightForklift] = 128;
		} else if(vexRT[Btn6D]) {
		 	motor[leftForklift] = -32;
			motor[rightForklift] = -32;
		}


		if(vexRT[Btn5U]) {
			SensorValue[claw] = 1;
		} else if(vexRT[Btn5D]) {
			SensorValue[claw] = 0;
		}



		if(vexRT[Btn5UXmtr2] && vexRT[Btn5DXmtr2]) {
			nMotorEncoder[lift] = 0;
	}

		if(vexRT[Btn7UXmtr2] && !(abs(nMotorEncoder[lift]) >= 17.5 / (0.5 * PI) * 627.2)) {
			motor[lift] = 128;
		} else if(vexRT[Btn7DXmtr2]) {
			motor[lift] = -128;
		}
		if(vexRT[Btn7LXmtr2] || vexRT[Btn7RXmtr2] || abs(nMotorEncoder[lift]) >= 17.5 / (0.5 * PI) * 392) {
			motor[lift] = 0;
		}

		if(vexRT[Btn6UXmtr2]) {
			SensorValue[mechStop] = 1;
		} else if(vexRT[Btn6DXmtr2]) {
			SensorValue[mechStop] = 0;
		}

	}
}
