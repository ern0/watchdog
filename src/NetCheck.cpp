# include "NetCheck.hpp"


	static unsigned char mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE4 };


	void NetCheck::callState(int state) {
		switch (state) {
			case 1: return initEthernet();
			case 2: return doneEthernet();
		} // switch
	} // callNextState()
	

	void NetCheck::setup() {
		setNextState(1,0);
		pinMode(8,OUTPUT);
	} // setup()

	
	void NetCheck::loop() {
		
	} // loop()


	void NetCheck::initEthernet() {
		//isEthernetOkay = ( Ethernet.begin(mac) != 0 );

		digitalWrite(8,1);
		setNextState(2,50);

	} // initEthernet()
	
	
	void NetCheck::doneEthernet() {

		digitalWrite(8,0);

	} // doneEthernet()
