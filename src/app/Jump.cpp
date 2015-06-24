# include "Jump.hpp"

	Jump::Jump() {
		reset();
	} // Jump() ctor

	
	void Jump::reset() {
		loopJump = NULL;
		timeoutJump = NULL;
		timeoutValue = -1;	
	} // reset()


	void Jump::loop() {
		if (loopJump == NULL) return;
		
		void (*lj)(void) = loopJump;
		reset();		 
		lj();

	} // loop();


	void Jump::interrupt() {
		if (timeoutJump == NULL) return;
		if (timeoutValue < 0) return;
		
		--timeoutValue;
		if (timeoutValue > 0) return; 

		void (*tj)(void) = timeoutJump;
		reset();		 
		tj();
		
	} // interrupt()
                                       

	void Jump::next(void (*lj)(void)) {
		loopJump = lj;
	} // next()
	

	void Jump::timeout(void (*tj)(void),int to) {
		timeoutJump = tj;
		timeoutValue = to;
	} // timeout()
