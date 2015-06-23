
	Jump() {
		reset();
	} // Jump() ctor

	
	void reset() {
		loopJump = NULL;
		timeoutJump = NULL;
		timeout = -1;	
	} // reset()


	void loop() {
		if (loopJump == NULL) return;
		
		void (*lj)(void) = loopJump;
		reset();		 
		lj();

	} // loop();


	void timeout() {
		if (timeoutJump == NULL) return;
		if (timeout < 0) return;
		
		--timeout;
		if (timeout > 0) return; 

		void (*tj)(void) = timeoutJump;
		reset();		 
		tj();
		
	} // timeout()
                                       

	void next(void (*lj)(void)) {
		loopJump = lj;
	} // next()
	

	void onTimeout(void (*tj)(void),int to) {
		timeoutJump = tj;
		timeout = to;
	} // onTimeout()
