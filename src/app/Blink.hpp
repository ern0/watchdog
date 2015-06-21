# ifndef _Blink_hpp
# define _Blink_hpp


class Blink {

	private:
		unsigned char* defaultSong;

	protected:
		unsigned char* song;
		int index;
		int counter;
		int value;
		
	public:
		Blink(); // ctor
		void init();
		void reset();
		void play(unsigned char* song);
		void tick();
		
}; // class Tick

# endif
