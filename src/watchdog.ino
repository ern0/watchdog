# define DEBUG (1)
# define LEDPIN 8
# define RELAYPIN 0

# include <SPI.h>
# include <Ethernet.h>
# include "app/SerialPrint.cpp"
# include "app/TimerInterrupt.cpp"
# include "app/Tick.cpp"
# include "app/Blink.cpp"
# include "songs.inc"


	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEE };
	char server[] = "a13";
	IPAddress ip(192,168,1,222);
	EthernetClient client;
	Tick tick;
	Blink blink;

	void setup() {

    setupSerialPrint();
    pinMode(LEDPIN,OUTPUT);
    pinMode(RELAYPIN,OUTPUT);
    setupTimer();
    blink.play(song1);

		Ethernet.begin(mac,ip);			
		delay(1000);	

		print("connecting");
		
		if (client.connect(server,80)) {
			client.println("GET / HTTP/1.1");
			client.println("Host: example.com");
			client.println("Connection: close");
			client.println();
		} // if conn
		else {
			print("connection failed");
		} // else conn		
    
	} // setup()
	
	
	void interrupt() {				
		blink.tick();
	} // interrupt()


	void loop() {

		while (client.available()) {
			char c = client.read();
			print(c);
			return;
		}

		if (!client.connected()) {
			Serial.println();
			Serial.println("--");
			client.stop();
			while(true);
		}

	
	} // loop()
