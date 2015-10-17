# include "NetCheck.hpp"


	static unsigned char mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xE4 };


	void NetCheck::setNextState(void (NetCheck::*state)(),int delay) {
		nextState = state;
		setNextDelay(delay);
	} // setNextState()
	

	void NetCheck::callNextState() {
		(this->*nextState)();
	} // callNextState()
	

	void NetCheck::setup() {
		setNextState(&NetCheck::initEthernet,0);
		pinMode(8,OUTPUT);
	} // setup()

	
	void NetCheck::loop() {
		
	} // loop()


	void NetCheck::initEthernet() {
	
		//isEthernetOkay = ( Ethernet.begin(mac) != 0 );

printf("init \n");
		digitalWrite(8,1);
		setNextState(&NetCheck::doneEthernet,50);

	} // initEthernet()
	
	
	void NetCheck::doneEthernet() {

printf("done \n");
		digitalWrite(8,0);

	} // doneEthernet()
