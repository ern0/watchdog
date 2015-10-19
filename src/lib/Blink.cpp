# include "Blink.hpp"


	unsigned char Blink::defaultSong[] = { 0 };


	void Blink::setup(int p) {		
	
		pin = p;
		pinMode(pin,OUTPUT);			
		play(defaultSong,-1);
		
	} // setup()

	
	void Blink::play(unsigned char* psong,int prepeat) {
		song = psong;
		repeat = prepeat;
		reset();
	} // play()


	void Blink::play(unsigned char* psong) {
		play(psong,-1);
	} // play()
	
	
	void Blink::wait() {
		while (repeat != 0);
	} // wait()
	
	
	void Blink::stop() {
		reset();
		repeat = 0;
	} // stop()
	
	
	void Blink::reset() {
		index = 0;
		counter = song[index] - 1;
		value = 0;		
		digitalWrite(pin,0);
	} // reset()
	
	
	void Blink::tick() {
	
		if (repeat == 0) return;
		
		if (counter > 0) {
			--counter;								
			return;
		}

		counter = song[index] - 1;
		if (counter < 0) {
			if (repeat > 0) repeat--;
			reset();
		}
		index++;

		digitalWrite(pin,value);
		value = 1 - value;	
		
	} // tick()
	
	
