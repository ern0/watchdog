# include "Jump.hpp"

	Jump::Jump() {
		reset();
	} // Jump() ctor

	
	void Jump::reset() {
		loopJump = NULL;
		delayValue = 0;
		timeoutJump = NULL;
		timeoutValue = -1;
		timedOutFlag = false;
	} // reset()


	void Jump::loop() {
	
		if (loopJump == NULL) return;		
		if (delayValue > 0) return;
		
		void (*lj)(void) = loopJump;
		reset();		 
		lj();

	} // loop();


	void Jump::interrupt() {

		--delayValue;
		if (delayValue < 0) delayValue = 0;
	
		if (timeoutJump == NULL) return;
		if (timeoutValue < 0) return;
		
		--timeoutValue;
		if (timeoutValue > 0) return; 

		void (*tj)(void) = timeoutJump;
		reset();		 
		timedOutFlag = true;
		tj();
		
	} // interrupt()
                                       

	void Jump::next(void (*lj)(void),int dy) {
		loopJump = lj;
		delayValue = dy;
	} // next()
	

	void Jump::timeout(void (*tj)(void),int to) {
		timeoutJump = tj;
		timeoutValue = to;
		timedOutFlag = false;
	} // timeout()


	bool Jump::isTimedOut() {
		return timedOutFlag;
	} // isTimedOut()
