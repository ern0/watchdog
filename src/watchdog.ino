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

# include "../lib/TimerInterrupt.cpp"
# include "../lib/Blink.cpp"
# include "../lib/Task.cpp"
# include "NetCheck.cpp"
# include "songs.inc"


	Blink blink;	
	NetCheck netCheck;
	
	EthernetClient client;		


	void setup() {
			
		blink.init(9);			
		netCheck.setup();		
		
		setupTimerInterrupt();
	
	} // setup()
	
	
	void tick() { // 50 Hz
	
		blink.tick();
		netCheck.tick();
	
	} // tick()
	
	
	void loop() {
	  
	  netCheck.loop();
	  
	} // loop()
