# ifndef _NetCheck_hpp
# define _NetCheck_hpp

# include "../lib/Task.hpp"


class NetCheck : public Task {

	private:
		static unsigned char mac[];
		EthernetClient client;		

	protected:
		void callState(int state);
		
	public:
		void setup();
		void loop();
		void initEthernet();
		void doneEthernet();
		
}; // class NetCheck
# endif
