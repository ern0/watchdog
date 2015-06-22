# if (1)
	# define DEBUG (1)
	# define LEDPIN 8
	# define RELAYPIN 0
# else
	# define DEBUG (0)
	# define LEDPIN 13
	# define RELAYPIN 12
# endif

# include <SPI.h>
# include <Ethernet.h>
# include "app/SerialPrint.cpp"
# include "app/TimerInterrupt.cpp"
# include "app/Tick.cpp"
# include "app/Task.cpp"
# include "app/Blink.cpp"
# include "songs.inc"


	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE };
	char server[] = "a13";
	EthernetClient client;
	Blink blink;
	Tick tick;
	Task idleTask;

	enum {
		CHECK_WEB_CONNECT,
		CHECK_WEB_FETCH,
		
		IDLE_ENTER,
		IDLE_LOOP
	} jump;


	void setup() {
	
    pinMode(LEDPIN,OUTPUT);
    pinMode(RELAYPIN,OUTPUT);
    
    idleTask.setTick(&tick);
    setupSerialPrint();
    tick.init(90000);
    blink.play(initSong);

    setupTimerInterrupt();
    
    jump = IDLE_ENTER;
    return;
    
		Ethernet.begin(mac);			
		delay(1000);	
	
	} // setup()


	void interrupt() {				
		tick.inc();
		blink.tick();
	} // interrupt()


	void loop() {
		switch (jump) {


			case IDLE_ENTER: {
			
				idleTask.reset();				
				print("|");
				jump = IDLE_LOOP;
				
			} break;
			

			case IDLE_LOOP: {
				
				if (idleTask.delay(TICKSEC(1))) {
					print(".");
				}
				
			} break;
			

			case CHECK_WEB_CONNECT: {

				if (client.connect(server,80)) {
					client.println("GET / HTTP/1.1");
					client.println("Host: example.com");
					client.println("Connection: close");
					client.println();
				} // if conn
				else {
					print("connection failed");
				} // else conn		

			} break;


			case CHECK_WEB_FETCH: {

				while (client.available()) {
					char c = client.read();
					print(c);
					return;
				}

				if (!client.connected()) {
					Serial.println();
					Serial.println("--");
					client.stop();
				}	
			
			} break;


		} // switch		
	} // loop()
