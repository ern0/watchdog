# ifndef _Jump_hpp
# define _Jump_hpp

class Jump {

	protected:
		void (*loopJump)(void);
		void (*timeoutJump)(void);
		int timeoutValue;

	protected:
		void reset();

	public:
		Jump(); // ctor
		void jump();
		void loop();
		void interrupt();
		void next(void (*lj)(void));
		void timeout(void (*tj)(void),int to);
		
}; // class Jump

# endif
