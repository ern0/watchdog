# ifndef _NetCheck_hpp
# define _NetCheck_hpp

# if ( defined(__unix__) || defined(__APPLE__) )
# else
# include <SPI.h>
# include <Ethernet.h>
# endif

 
# include "../lib/Task.hpp"


class NetCheck : public Task {

	private:
		int pin;
		static unsigned char mac[];
		EthernetClient client;		
		const char* host;
		int port;

	protected:
		enum { 
			INIT_ETHERNET = 11,FAIL_ETHERNET = 12,TIMEOUT_ETHERNET = 13,
			HTTP_CONN = 21,HTTP_READ = 22,DELAY = 23,
			ALERT = 31,TURN_OFF_ROUTER = 32,TURN_ON_ROUTER = 33
		};
		void callState(int state);
		void callTimeout(int state);
		
	public:
		void setup();
		void setPin(int pin);
		void setHost(const char* host);
		void setPort(int port);
		void initEthernet();
		void failEthernet();
		void timeoutEthernet();
		void httpConnect();
		void httpRead();
		void delay();
		void alert();
		void turnOffRouter();
		void turnOnRouter();
		
}; // class NetCheck
# endif
