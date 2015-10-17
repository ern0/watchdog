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


	int x;


	void setup() {
	
		setupTimerInterrupt();
		pinMode(LEDPIN,OUTPUT);
		
		
		volatile int x = 0;
		
	} // setup()
	
	
	void tick() { // 50 Hz
	
		x++;
	
	} // tick()
	
	
	void loop() {
	  
		if (x % 10 == 0) {
			digitalWrite(13,0);
		} else if (x % 5 == 0) {
			digitalWrite(13,1);
		}
		
	  
	} // loop()
