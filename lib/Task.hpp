# ifndef _Task_hpp
# define _Task_hpp


class Task {

	private:
		int counter;
		int delay;
	
	protected:
		void setNextDelay(int d);
		
	public:
		virtual void callNextState() = 0;
		void tick();
		
}; // class Task
# endif
