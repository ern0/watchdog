# define DEBUG (1)
# define RELAYPIN 9
# define BUZZPIN 8
# define LEDPIN 13

# if ( defined(__unix__) || defined(__APPLE__) )
	# define TIMER2 ( 1 / 1000 )   
	# include "../../posixino/src/posixino.cpp"
# else
	# include <SPI.h>
	# include <Ethernet.h>
# endif

# include "../lib/SerialPrint.cpp"
# include "../lib/TimerInterrupt.cpp"
# include "../lib/Tick.cpp"
# include "../lib/Task.cpp"
# include "../lib/Blink.cpp"
# include "../lib/Jump.cpp"
# include "songs.inc"


	Blink blink;
	Tick tick;
	Task idleTask;
	Jump jump;
	

	void interrupt() {				
		tick.inc();
		blink.tick();
		jump.interrupt();
	} // interrupt()

 
	void loop() {
		jump.loop();
	} // loop();


	void networkInit();
	void networkInitTimeout();
	void networkInitOkay();
	
	void test1();
	void test2();
	
	void httpConnect();
	void httpRead();

	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE4 };
	EthernetClient client;
	bool isEthernetOkay = false;	
	
	int httpPass = 0;
	int httpPort[2];
	char httpHost[2][80];	


	void setup() {

    pinMode(LEDPIN,OUTPUT);
    pinMode(RELAYPIN,OUTPUT);
    
    digitalWrite(LEDPIN,HIGH);
    
    httpPass = 0;
    strcpy(httpHost[0],"a13");
    httpPort[0] = 80;
    strcpy(httpHost[1],"example.com");
    httpPort[1] = 80;

		blink.init();
    idleTask.setTick(&tick);
    setupSerialPrint();
    tick.init(90000);

    setupTimerInterrupt(); 
    networkInit();    
    
	} // setup()


	void networkInit() {
   
    blink.play(ethernetInitSong);
    jump.timeout(&networkInitTimeout,TICKSEC(3));

		isEthernetOkay = ( Ethernet.begin(mac) != 0 );
		if (jump.isTimedOut()) return;			
		
		if (isEthernetOkay) {
			jump.next(&networkInitOkay,0);
		} else {
			blink.play(ethernetRetrySoonSong);
			jump.next(&networkInit,TICKSEC(5));
		}
		
	} // networtkInit()


	void networkInitTimeout() {
		blink.play(ethernetRetrySoonSong);
		jump.next(&networkInit,0);
	} // networkInitTimeout()


	void networkInitOkay() {
		jump.next(&test1,TICKSEC(1));
	} // networkInitOkay()
	
	
	
	void test1() {
		pri("t1");
		blink.play(ethernetRetrySoonSong);
		jump.next(&test2,TICKSEC(2));
	}
	
	void test2() {
		pri("t2");
		blink.play(httpSong);
		jump.next(&test1,TICKSEC(5));
	}
		

	void httpConnect() {
		pri("http conn");

		if (client.connect(httpHost[httpPass],httpPort[httpPass])) {
			client.println("GET / HTTP/1.1");
			client.print("Host: ");
			client.println(httpHost[httpPass]);
			client.println("Connection: close");
			client.println();
		} // if conn
		else {
			pri("connection failed");
		} // else conn		

	} // httpConnect()
	
	
	void httpRead() {
	
		while (client.available()) {
			char c = client.read();
			pri(c);
			return;
		}

		if (!client.connected()) {
			Serial.println();
			Serial.println("--");
			client.stop();
		}	
			
	} // httpRead()
