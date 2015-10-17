# include "Task.hpp"


	void Task::setNextState(int s,int d) {
		state = s;
		counter = d;
	} // setNextState()
	

	void Task::tick() {
		
		if (counter < 0) return;
		--counter;
		if (counter < 0) callState(state);
				
	} // tick()
	
	
