task bringBoomHome() {
	extendBoomInches(14.5,-127);
	wait1Msec(320);
	motor[lift] = 0;
}
task extendBoom() { //All
	extendBoomInches(7, 127);
}
task either() { //ForwardBackward
	//driveInches(4*sqrt(24*24*2), 127);
	driveInches(3*24, -127);
	delay(1000);
	driveInches(18, 127);
	startTask(bringBoomHome);
}
task rightTurn() {
	driveInches(3*24, -127);
	driveInches(2*24, 127);
	turnDegrees(135, 127);
	startTask(bringBoomHome);
	driveInches(2.5*24, 127);
}
task leftTurn() {
	driveInches(3*24, -127);
	driveInches(2*24, 127);
	turnDegrees(-135, 127);
	startTask(bringBoomHome);
	driveInches(2.*24, 127);
}
task forwardBackward() {
	extendBoomInches(7, 127);
	startTask(extendBoom);
	startTask(either);
}
task forwardBackwardCubeLeftStart() {
	extendBoomInches(7, 127);
	startTask(extendBoom);
	startTask(rightTurn);
}
task forwardBackwardCubeRightStart() {
	extendBoomInches(6.5, 127);
	startTask(extendBoom);
	startTask(leftTurn);
}
