# define LEDPIN 7
# define BUZZPIN 8
# define RELAYPIN 9

# if ( defined(__unix__) || defined(__APPLE__) )
	# define TIMER2 ( 1000 / 50 )   
	# include "../../posixino/src/posixino.cpp"
	# define DEBUG (1)
# else
	# include <SPI.h>
	# include <Ethernet.h>
	# define DEBUG (0)
# endif


# include "songs.inc"

# include "lib/TimerInterrupt.cpp"
# include "lib/Task.cpp"
# include "lib/Blink.cpp"
Blink blink;	
Blink buzz;

# include "app/NetCheck.cpp"
NetCheck netCheck;	


	void setup() {
	
		blink.setup(LEDPIN);			
		buzz.setup(BUZZPIN);
		
		Serial.begin(9600);
		
		netCheck.setup();		
		netCheck.setPin(RELAYPIN);
		netCheck.setHost("google.com");
		netCheck.setPort(80);
		
		setupTimerInterrupt();
		
		# if DEBUG
			Serial.println("setup done");
		# endif
	
	} // setup()
	
	
	void tick() { // 50 Hz
	
		blink.tick();
		buzz.tick();
		netCheck.tick();
	
	} // tick()
	
	
	void loop() {
	  
	  netCheck.loop();
	  
	} // loop()
