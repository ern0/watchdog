# if (0)
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
# include "app/Jump.cpp"
# include "songs.inc"


	Blink blink;
	Tick tick;
	Task idleTask;
	Jump jump;
	

	void interrupt() {				
		tick.inc();
		blink.tick();
		jump.tick();
	} // interrupt()


	void networkInit();
	void networkProc();
	void networkTimeout();
	void httpConnect();
	void httpRead();

	void idleLoop();

	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE };
	char server[] = "a13";
	EthernetClient client;
	int ethernetOkay = 0;	


	void setup() {
	
    pinMode(LEDPIN,OUTPUT);
    pinMode(RELAYPIN,OUTPUT);
    
    idleTask.setTick(&tick);
    setupSerialPrint();
    tick.init(90000);

    setupTimerInterrupt();
    
    jump.next(&networkInit);
    
	} // setup()


	void loop() {
		jump.loop();
	} // loop();


	void networkInit() {
    
    jump(&networkProc,&networkTimeout,TICKSEC(2));
    
    blink.play(initSong);
		//ethernetOkay = Ethernet.begin(mac);	
				
	} // networtkInit()


	void networkProc() {
		
		if (ethernetOkay > 0) {
			blink.play(deadSong);
			jump.next(NULL);
			return;
		}
		
		jump.next(httpConnect);

	} // networkProc()
	

	void networkTimeout() {

		blink.play(deadSong);
		jump.next(NULL);	

	} // networkTimeout()



	void idleEnter() {
		
		idleTask.reset();				
		print("|");
		jump.next(&idleLoop);
		
	} // idleEnter()
				

	void idleLoop() {
	
		if (idleTask.delay(TICKSEC(1))) {
			print(".");
			jump.next(NULL);
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
