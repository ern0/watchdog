# define DEBUG (1)
# define LEDPIN 13
# define RELAYPIN 12

# if DEBUG
# define print(x) Serial.println(x)
# else
# define print(x)
# endif

# include <SPI.h>
# include <Ethernet.h>


	byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
	char server[] = "www.google.com";
	IPAddress ip(192,168,1,177);
	EthernetClient client;
	
	enum {
		ETH_CONNECT,
		HTTP_CONNECT
	} todo;


	void setup() {

    pinMode(LEDPIN,OUTPUT);
    pinMode(RELAYPIN,OUTPUT);
    
		# if DEBUG
		Serial.begin(9600);
		# endif
    
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
