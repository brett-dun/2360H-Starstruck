task record() {
	//writeDebugStream("Starting");
	//Loop through this 100 times a second for n number of seconds
	for(int i = 0; i < 100 * 15; i++) {
		writeDebugStream("{%i,%i,%i},\n",vexRT[Ch3],vexRT[Ch2],(vexRT[Btn5U]+2*vexRT[Btn6U]+4*vexRT[Btn6D]));
		delay(10);
	}
}
