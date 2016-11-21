/*
	distance > 0 && speed > 0 >>> forward
	distance > 0 && speed < 0 >>> backward
	distance < 0 && speed > 0 >>> backward
	distance < 0 && speed < 0 >>> forward
*/
void extendBoomInches(float distance, int speed);

/*
	angle > 0 && speed > 0 >>> clockwise
	angle > 0 && speed < 0 >>> counterclockwise
	angle < 0 && speed > 0 >>> counterclockwise
	angle < 0 && speed < 0 >>> clockwise
*/
void turnDegrees(float angle , int speed);

/*
	distance > 0 && speed > 0 >>> extend
	distance > 0 && speed < 0 >>> retract
	distance < 0 && speed > 0 >>> retract
	distance < 0 && speed < 0 >>> extend
*/
void driveInches(float distance, int speed);

/*
*/
void moveForkliftDegrees(float angle, int speed);
