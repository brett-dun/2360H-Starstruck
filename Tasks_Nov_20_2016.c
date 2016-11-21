#include "Tasks_Nov_20_2016.h"

task bringBoomHome() {
	extendBoomInches(14.5,-127);
	wait1Msec(320);
	motor[lift] = 0;
}
task auto1() {
	extendBoomInches(7, 127);
}
task auto2() {
	//driveInches(4*sqrt(24*24*2), 127);
	driveInches(3*24, 127);
	delay(1000);
	driveInches(18, -127);
	startTask(bringBoomHome);
}
task auto3() {
	driveInches(3*24, 127);
	driveInches(2*24, -127);
	turnDegrees(90, 127);
	startTask(bringBoomHome);
	driveInches(2.5*24, 127);
}
task auto4() {
	driveInches(3*24, 127);
	driveInches(2*24, -127);
	turnDegrees(-80, 127);
	startTask(bringBoomHome);
	driveInches(2.5*24, 127);
}
task forwardBackward() {
	extendBoomInches(7, 127);
	startTask(auto1);
	startTask(auto2);
}
task forwardBackwardCubeLeftStart() {
	extendBoomInches(7, 127);
	startTask(auto1);
	startTask(auto3);
}
task forwardBackwardCubeRightStart() {
	extendBoomInches(7, 127);
	startTask(auto1);
	startTask(auto4);
}
