# define LEDPIN 9
# define BUZZPIN 8
# define RELAYPIN 7

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
		
		netCheck.setup();		
		netCheck.setPin(RELAYPIN);
		netCheck.setHost("google.com");
		netCheck.setPort(80);
		
		setupTimerInterrupt();
	
	} // setup()
	
	
	void tick() { // 50 Hz
	
		blink.tick();
		netCheck.tick();
	
	} // tick()
	
	
	void loop() {
	  
	  //blink.play(timeoutSong); while(true) sleep(1);
	  netCheck.loop();
	  
	} // loop()
