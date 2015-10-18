# include "Task.hpp"

	// counter:
	//  x >  0: active - counting down
	//  x =  0: fire
	//  x = -1: passive - performing


	Task::Task() {
	
		state = -1;
		counter = -1;
		timeoutCounter = -1;
		
	} // Task() ctor
	

	void Task::setNextState(int s,int d) {
	
		state = s;
		counter = d;
		timeoutCounter = -1;
		
		//prii("set next state",s);
		
	} // setNextState()
	
	
	void Task::setNextState(int s) {
		setNextState(s,0);
	} // setNextState()
	
	
	void Task::setTimeout(int t) {
		timeoutCounter = t;
	} // setTimeout()
	

	void Task::tick() {
		
		if (counter > 0) --counter;
		
		if (timeoutCounter > 0) {
			--timeoutCounter;		
			return;
		}
		if (timeoutCounter == 0) {
			--timeoutCounter;
			callTimeout(state);
		}
				
	} // tick()
	
	
	void Task::loop() {

		if (counter > 0) return;
		
		if (counter == 0) {
			--counter;
			//prii("call state",state);
			callState(state);
		}

	} // loop()
