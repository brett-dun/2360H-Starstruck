task bringBoomHome() {
	extendBoomInches(-14.5,128);
	wait1Msec(320);
	motor[lift] = 0;
}
task auto1() {
	extendBoomInches(7,128);
}
task auto2() {
	//driveInches(4*sqrt(24*24*2), 127);
	driveInches(3*24);
	delay(1000);
	driveInches(-18);
	startTask(bringBoomHome);
}
task auto3() {
	driveInches(3*24);
	driveInches(-2*24);
	turnDegrees(90);
	startTask(bringBoomHome);
	driveInches(2.5*24);
}
task auto4() {
	driveInches(3*24);
	driveInches(-2*24);
	turnDegrees(-80);
	startTask(bringBoomHome);
	driveInches(2.5*24);
}
task forwardBackward() {
	extendBoomInches(7,128);
	startTask(auto1);
	startTask(auto2);
}
task forwardBackwardCubeLeftStart() {
	extendBoomInches(7,128);
	startTask(auto1);
	startTask(auto3);
}
task forwardBackwardCubeRightStart() {
	extendBoomInches(7,128);
	startTask(auto1);
	startTask(auto4);
}
