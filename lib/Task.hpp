# ifndef _Task_hpp
# define _Task_hpp

# include "Tick.hpp"

class Task {
	
	protected:
		Tick* tick;
		bool first;
		tick_t last;
		int miss;
	
	protected:
		bool check(tick_t t,bool delayMode);
		
	public:
		Task(); // ctor		
		void setTick(Tick* t);
		void reset();
		int collectMiss();
		bool every(tick_t t);
		bool delay(tick_t t);
		
}; // class Task

# endif
