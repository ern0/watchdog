# ifndef _Blink_hpp
# define _Blink_hpp


class Blink {

	private:
		static unsigned char defaultSong[];

	protected:
		unsigned char* song;
		int index;
		int counter;
		int value;
		
	public:
		void init();
		void reset();
		void play(unsigned char* song);
		void tick();
		
}; // class Tick

# endif
