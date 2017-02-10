#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  rightButton,    sensorTouch)
#pragma config(Sensor, dgtl2,  leftButton,     sensorTouch)
#pragma config(Sensor, dgtl3,  jumper,         sensorDigitalIn)
#pragma config(Sensor, dgtl11, claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl12, led,            sensorDigitalOut)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign )
#pragma config(Motor,  port2,           forklift1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           leftDrive,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_1)
#pragma config(Motor,  port4,           forklift2,     tmotorVex393_MC29, openLoop, reversed, encoderPort, I2C_2)
#pragma config(Motor,  port5,           forklift5,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           forklift3,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           forklift4,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           rightDrive,    tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//Competition Control and Duration Settings
#pragma DebuggerWindows("debugStream")
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

//Supporting Files
#include <BaseFunctions.c>
#include <AdvancedFunctions.c>
#include <Autonomous.c>
#include <ProgrammingSkills.c>
#include <recorder.c>
#include <data.c>
#include <playback.c>

//Variables
int maxSpeed = 128;
int enableClaw = 1;


void pre_auton() { bStopTasksBetweenModes = true; }



task autonomous() {
	if(SensorValue[jumper]) { //no jumper == 1
		SensorValue[led] = 1;
		playback();
		//rightStart();
		//mAuto();
	} else { //yes jumper == 0
		SensorValue[led] = 0;
		leftStart();
	}
	//skills3();
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
*/
task usercontrol() {

	//startTask(record);

	clearTimer(T1);

	//nMotorEncoder[leftForklift] = 0;
	///const float ticks = abs((100/360.0) * 5 * 627.2);

	while(true) {

	/*if(abs(nMotorEncoder[leftForklift]) > ticks){
		motor[leftForklift] = 0;
		motor[rightForklift] = 0;
	}*/

		SensorValue[led] = SensorValue[jumper];

		if(vexRT[Btn8U]) {
			maxSpeed = 128; //Change the maximum speed to 128 (maximum value)
		} else if(vexRT[Btn8L] || vexRT[Btn8R]) {
			maxSpeed = 64;
		} else if(vexRT[Btn8D]) {
			maxSpeed = 32; //Change the maximum speed to 32 (1/4 of the maximum value)
		}

		motor[leftDrive] = vexRT[Ch2] * (maxSpeed / 128.0);
		motor[rightDrive] = vexRT[Ch3] * (maxSpeed / 128.0);

		if(!vexRT[Btn6U] && !vexRT[Btn6D]) {
			motor[forklift1] = 0;
			motor[forklift2] = 0;
			motor[forklift3] = 0;
			motor[forklift4] = 0;
			motor[forklift5] = 0;
		} if(vexRT[Btn6U]) {
			motor[forklift1] = 128;
			motor[forklift2] = 128;
			motor[forklift3] = 128;
			motor[forklift4] = 128;
			motor[forklift5] = 128;
		} else if(vexRT[Btn6D]) {
		 	motor[forklift1] = -128;
			motor[forklift2] = -128;
			motor[forklift3] = -128;
			motor[forklift4] = -128;
			motor[forklift5] = -128;
		}


		if(vexRT[Btn5U] && enableClaw) {
			SensorValue[claw] = !SensorValue[claw];
			enableClaw = 0;
			clearTimer(T1);
		}

		if(time1(T1) > 250) {
			enableClaw = 1;
		}

	}
}
