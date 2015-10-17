# ifndef _Task_hpp
# define _Task_hpp


class Task {

	private:
		int state;
		int counter;
		int delay;
	
	protected:
		void setNextState(int state,int delay);
		
	public:
		virtual void callState(int state) = 0;
		void tick();
		
}; // class Task
# endif
