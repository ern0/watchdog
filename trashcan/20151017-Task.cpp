# include <stdlib.h>
# include <stdio.h>
# include "Task.hpp"

		
	Task::Task() {
		tick = NULL;
		first = true;
		last = 0;
		miss = 0;
	} // Task() ctor	


	void Task::setTick(Tick* t) {
		tick = t;
		reset();
	} // setTick()


	void Task::reset() {
		if (tick != NULL) first = true;
	} // reset()
	
	
	int Task::collectMiss() {
	
		int result = miss;
		miss = 0;
		
		return result;
	} // collectMiss()	


	bool Task::every(tick_t interval) {
		return check(interval,false);
	} // every()
	
	
	bool Task::delay(tick_t interval) {
		return check(interval,true);
	} // delay()
	
	
	bool Task::check(tick_t interval,bool delayMode) {

		if (tick == NULL) return false;
		
		if (first) {
			first = false;
			last = tick->getValue();
			return ( delayMode ? false : true );  
		} // if first
		
		int elapsed = tick->elapsed(last);
		if (elapsed < interval) return false;
		
		--miss;
		while (interval <= elapsed) {
			elapsed -= interval;
			last += interval;
			miss++;
		} // while
		
		return true;
	} // check()
