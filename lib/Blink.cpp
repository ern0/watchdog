# include "Blink.hpp"


	unsigned char Blink::defaultSong[] = { 50,50,0 };


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
		digitalWrite(LEDPIN,0);
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
	
	
