# ifndef _Jump_hpp
# define _Jump_hpp

class Jump {

	protected:
		void (*loopJump)(void);
		int delayValue;
		void (*timeoutJump)(void);
		int timeoutValue;
		bool timedOutFlag;

	protected:
		void reset();

	public:
		Jump(); // ctor
		void jump();
		void loop();
		void interrupt();
		void next(void (*lj)(void),int dy);
		void timeout(void (*tj)(void),int to);
		bool isTimedOut();
		
}; // class Jump

# endif
