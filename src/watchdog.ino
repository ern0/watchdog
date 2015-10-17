# define DEBUG (1)
# define RELAYPIN 9
# define BUZZPIN 8
# define LEDPIN 13

# if ( defined(__unix__) || defined(__APPLE__) )
	# define TIMER2 ( 1000 / 50 )   
	# include "../../posixino/src/posixino.cpp"
# else
	# include <SPI.h>
	# include <Ethernet.h>
# endif

# include "../lib/SerialPrint.cpp"
# include "../lib/TimerInterrupt.cpp"
# include "../lib/Blink.cpp"
# include "songs.inc"

	Blink blink1;
	Blink blink2;


	void setup() {
			
		blink1.init(9);			
		blink1.play(httpSong);
		
		blink2.init(8);
		blink2.play(ethernetRetrySoonSong,20);
		
		setupTimerInterrupt();
	
	} // setup()
	
	
	void tick() { // 50 Hz
	
		blink1.tick();
		blink2.tick();
	
	} // tick()
	
	
	void loop() {
	  
	  
	} // loop()
