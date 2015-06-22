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
	
	void (*loopJump)(void);
	void (*timeoutJump)(void);


	void jump(void (*lj)(void),void (*tj)(void)) {
		loopJump = lj;
		timeoutJump = tj;
	} // jump()
	

	void interrupt() {				
		tick.inc();
		blink.tick();
	} // interrupt()


	void loop() {
		if (loopJump != NULL) loopJump();
	} // loop();
	
	
	void idleEnter();
	void idleLoop();
	void httpConnect();
	void httpRead();
	

	void setup() {
	
    pinMode(LEDPIN,OUTPUT);
    pinMode(RELAYPIN,OUTPUT);
    
    idleTask.setTick(&tick);
    setupSerialPrint();
    tick.init(90000);
    blink.play(initSong);

    setupTimerInterrupt();
    
    jump(&idleEnter,NULL);
    return;
    
		Ethernet.begin(mac);			
		delay(1000);	
	
	} // setup()


	void idleEnter() {
		
		idleTask.reset();				
		print("|");
		jump(&idleLoop,NULL);
		
	} // idleEnter()
				

	void idleLoop() {
	
		if (idleTask.delay(TICKSEC(1))) {
			print(".");
			jump(NULL,NULL);
		}

	} // idleLoop()


	void httpConnect() {

		if (client.connect(server,80)) {
			client.println("GET / HTTP/1.1");
			client.println("Host: example.com");
			client.println("Connection: close");
			client.println();
		} // if conn
		else {
			print("connection failed");
		} // else conn		

	} // httpConnect()
	
	
	void httpRead() {
	
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
			
	} // httpRead()
