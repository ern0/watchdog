# ifndef _Blink_hpp
# define _Blink_hpp


class Blink {

	private:
		static unsigned char defaultSong[];

	protected:
		unsigned char* song;
		int pin;
		int repeat;
		int index;
		int counter;
		int value;
		
	public:
		void setup(int pin);
		void reset();
		void play(unsigned char* song,int repeat);
		void play(unsigned char* song);
		void wait();
		void stop();
		void tick();
		
}; // class Tick

# endif
