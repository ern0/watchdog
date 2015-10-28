# define LEDPIN 6
# define BUZZPIN 8
# define RELAYPIN 7

# if ( defined(__unix__) || defined(__APPLE__) )
	# define TIMER2 ( 1000 / 100 )   
	# include "../../posixino/src/posixino.cpp"
	# define DEBUG (1)
# else
	# include <SPI.h>
	# include <Ethernet.h>
	# define DEBUG (0)
# endif


# include "songs.inc"

# include "../../blinkino/lib/TimerInterrupt.cpp"
# include "../../blinkino/lib/Task.cpp"
# include "../../blinkino/lib/Blink.cpp"
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
