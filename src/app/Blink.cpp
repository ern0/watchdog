# include "Blink.hpp"


	static unsigned char defaultSong[] = { 50,50,0 };
		
		
	Blink::Blink() {
		init();
	} // Blink() ctor	


	void Blink::init() {		
		play(defaultSong);
	} // init()

	
	void Blink::play(unsigned char* psong) {
		song = psong;
		reset();
	} // play()
	
	
	void Blink::reset() {
		index = 0;
		counter = song[index] - 1;
		value = 0;		
	} // reset()
	
	
	void Blink::tick() {
	
		if (counter > 0) {
			--counter;								
			return;
		}

		counter = song[index] - 1;
		if (counter < 0) reset();
		index++;

		digitalWrite(LEDPIN,value);
		value = 1 - value;	
		
	} // tick()
	
	
