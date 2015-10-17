# include "Task.hpp"


	void Task::setNextDelay(int d) {
		counter = d;
	} // setNextDelay()
	

	void Task::tick() {
		
		if (counter < 0) return;
		--counter;
		if (counter < 0) callNextState();
		
		
	} // tick()
	
	
