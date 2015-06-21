# ifndef _Blink_hpp
# define _Blink_hpp


class Blink {

	private:
		const unsigned char* defaultSong;

	protected:
		const unsigned char* song;
		int noteIndex;
		int noteCounter;
		int noteValue;
		
	public:
		Blink(); // ctor
		void init();
		void reset();
		void play(const unsigned char* song);
		void playNote();
		void tick();
		
}; // class Tick

# endif
