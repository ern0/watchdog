# include "NetCheck.hpp"


	unsigned char NetCheck::mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE4 };


	void NetCheck::setup() {
		setNextState(INIT_ETHERNET);		
	} // setup()


	void NetCheck::setPin(int p) {
		pin = p;
		pinMode(pin,OUTPUT);			
	} // setPin()
	
	
	void NetCheck::setHost(const char* h) {
		host = h;
	} // setHost()
	
	
	void NetCheck::setPort(int p) {
		port = p;
	} // setPort()


	void NetCheck::callState(int state) {
		
		# if DEBUG
			Serial.print("state: ");
			Serial.println(state);
		# endif
		
		switch (state) {
			case INIT_ETHERNET: return initEthernet();
			case RETRY_ETHERNET: return retryEthernet();
			case HTTP_CONN: return httpConnect();
			case HTTP_READ: return httpRead();
			case DELAY: return delay();
			case ALERT: return alert();
			case TURN_OFF_ROUTER: return turnOffRouter();
			case TURN_ON_ROUTER: return turnOnRouter();
			case PROTECTED_PERIOD: return protectedPeriod();
		} // switch
	} // callNextState()

	
	void NetCheck::initEthernet() {

		blink.play(initEthernetSong);
		
		bool isEthernetOkay = ( Ethernet.begin(mac) != 0 );

		if (isEthernetOkay) {
			setNextState(HTTP_CONN);
		} else {
			setNextState(RETRY_ETHERNET);
		}

	} // initEthernet()
	
	
	void NetCheck::retryEthernet() {	

		blink.play(retryEthernetSong);	
		buzz.play(helloSong,2);

		setNextState(INIT_ETHERNET,SEC(2));

	} // retryEthernet()


	void NetCheck::httpConnect() {
	
		blink.play(httpSong);
		buzz.stop();

		if (client.connect(host,port)) {
			client.println("GET / HTTP/1.1");
			client.print("Host: ");
			client.println(host);
			client.println("Connection: close");
			client.println();
			
			setNextState(HTTP_READ);
			
		} // if conn
		
		else {
			setNextState(ALERT);
		} // else conn		

	} // httpConnect()
	
	
	void NetCheck::httpRead() {
	
		# if DEBUG
			char buffer[200];
			int index = 0;
		# endif
	
		while (true) {
		
			while (client.available()) {
				char c = client.read();
				# if DEBUG
					if (index < 200) {
						buffer[index] = c;
						index++;
						buffer[index] = 0;
					}
				# endif
			} // while read

			if (!client.connected()) break;
			
		} // forever

		client.stop();

		# if DEBUG
			printf("\n%s\n",buffer);
		# endif
		
		setNextState(DELAY);
			
	} // httpRead()
	
	
	void NetCheck::delay() {
	
		blink.play(okaySong);
		setNextState(HTTP_CONN,SEC(30));
		
	} // delay()
	
	
	void NetCheck::alert() {
	
		blink.play(alertSong,2);
		buzz.play(alertSong,1);
		
		setNextState(TURN_OFF_ROUTER,SEC(1));
		
	} // alert()
	
	
	void NetCheck::turnOffRouter() {
	
		digitalWrite(pin,HIGH);
		setNextState(TURN_ON_ROUTER,SEC(2));
		
	} // turnOffRouter()
	
	
	void NetCheck::turnOnRouter() {

		digitalWrite(pin,LOW);
		setNextState(PROTECTED_PERIOD,SEC(1));
		
	} // turnOnRouter()


	void NetCheck::protectedPeriod() {
	
		blink.play(protectedSong);
		setNextState(DELAY,SEC(90));
	
	} // protectedPeriod()
