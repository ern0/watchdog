# define DEBUG (1)
# define LEDPIN 13
# define RELAYPIN 12

# include <SPI.h>
# include <Ethernet.h>
# include "SerialPrint.cpp"
# include "TimerInterrupt.cpp"
# include "Tick.cpp"
# include "Blink.cpp"

	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
	char server[] = "www.google.com";
	IPAddress ip(192,168,1,177);
	EthernetClient client;
	Tick tick;
	Blink blink;
	
	enum {
		ETH_CONNECT,
		HTTP_CONNECT
	} todo;


	void setup() {

    pinMode(LEDPIN,OUTPUT);
    pinMode(RELAYPIN,OUTPUT);
    
    setupSerialPrint();
    setupTimer();

		Ethernet.begin(mac,ip);				
		print("eth");
		delay(2000);

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
	} // interrupt()


	void loop() {

		if (client.available()) {
			char c = client.read();
			print(c);
		}

		/*
		if (!client.connected()) {
			Serial.println();
			Serial.println("--");
			client.stop();
		}

    while(true);
    */
	
	} // loop()
