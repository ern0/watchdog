# include "Blink.hpp"


	static const unsigned char defaultSong[] = { 50,50,0 };
		
		
	Blink::Blink() {
		init();
	} // Blink() ctor	


	void Blink::init() {		
		play(defaultSong);
	} // init()

	
	void Blink::play(const unsigned char* psong) {
		song = psong;
		reset();
	} // play()
	
	
	void Blink::reset() {
		noteIndex = 0;
		noteCounter = 0;
		noteValue = 0;		
	} // reset()
	
	
	void Blink::tick() {

		if (noteCounter > 0) {
			--noteCounter;								
			return;
		}
		
		digitalWrite(LEDPIN,noteValue);
		noteValue = 1 - noteValue;
		
		noteCounter = song[noteIndex] - 1;
		if (noteCounter < 0) {
			reset();
			tick();
		}	else {
			noteIndex++;
		}
		
	} // tick()
	
	
