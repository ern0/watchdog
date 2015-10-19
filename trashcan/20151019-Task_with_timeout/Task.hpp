# ifndef _Task_hpp
# define _Task_hpp


class Task {

	private:
		volatile int state;
		volatile int counter;
		volatile int timeoutCounter;
	
	protected:
		void setNextState(int state,int delay);
		void setNextState(int state);
		void setTimeout(int timeout);
		
	public:
		Task();
		void tick();
		void loop();
		virtual void callState(int state) = 0;
		virtual void callTimeout(int state) = 0;
		
}; // class Task
# endif
