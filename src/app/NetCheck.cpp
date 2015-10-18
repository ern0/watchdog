# include "NetCheck.hpp"


	unsigned char NetCheck::mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE4 };


	void NetCheck::setup() {
		setNextState(INIT_ETHERNET);		
	} // setup()


	void NetCheck::setPin(int p) {
		pin = p;
	} // setPin()
	
	
	void NetCheck::setHost(const char* h) {
		host = h;
	} // setHost()
	
	
	void NetCheck::setPort(int p) {
		port = p;
	} // setPort()


	void NetCheck::callState(int state) {
		switch (state) {
			case INIT_ETHERNET: return initEthernet();
			case FAIL_ETHERNET: return failEthernet();
			case TIMEOUT_ETHERNET: return timeoutEthernet();
			case HTTP_CONN: return httpConnect();
			case HTTP_READ: return httpRead();
			case DELAY: return delay();
			case ALERT: return alert();
			case TURN_OFF_ROUTER: return turnOffRouter();
			case TURN_ON_ROUTER: return turnOnRouter();
		} // switch
	} // callNextState()

	
	void NetCheck::callTimeout(int state) {
		
		switch (state) {
			case 1: return timeoutEthernet();
			
		} // switch
		
	} // callTimeout()
	

	void NetCheck::initEthernet() {

		blink.play(initEthernetSong);
		setTimeout(SEC(5));
		
		bool isEthernetOkay = ( Ethernet.begin(mac) != 0 );

		if (isEthernetOkay) {
			setNextState(HTTP_CONN);
		} else {
			setNextState(FAIL_ETHERNET);
		}

	} // initEthernet()
	
	
	void NetCheck::failEthernet() {	
		blink.play(failEthernetSong);	
	} // failEthernet()


	void NetCheck::timeoutEthernet() {	
		blink.play(timeoutSong);	
	} // timeoutEthernet()


	void NetCheck::httpConnect() {
	
		blink.play(httpSong);

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
		setNextState(HTTP_CONN,SEC(10));
	} // delay()
	
	
	void NetCheck::alert() {
		printf("alert \n");
	} // alert()
	
	
	void NetCheck::turnOffRouter() {
	} // turnOffRouter()
	
	
	void NetCheck::turnOnRouter() {
	} // turnOnRouter()
