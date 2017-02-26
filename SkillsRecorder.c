task record() {
	//Loop through this 50 times a second for n number of seconds
	for(int i = 0; i < 50 * 60; i++) {
		writeDebugStream("{%i,%i,%i},\n",vexRT[Ch2],vexRT[Ch3],(100*vexRT[Btn5U]+10*vexRT[Btn6U]+vexRT[Btn6D]));
		delay(20);
	}
}
