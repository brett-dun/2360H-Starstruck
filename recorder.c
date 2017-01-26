task record() {
	//writeDebugStream("Starting");
	//Loop through this 100 times a second for n number of seconds
	for(int i = 0; i < 100 * 15; i++) {
		writeDebugStream("{%i,%i,%i,%i,%i},\n",vexRT[2],vexRT[3],vexRT[Btn5U],vexRT[Btn6U],vexRT[Btn6D]);
		delay(10);
	}
}
