# ifndef _NetCheck_hpp
# define _NetCheck_hpp

# include "../lib/Task.hpp"


class NetCheck : public Task {

	private:
		void (NetCheck::*nextState)();
		static unsigned char mac[];
		EthernetClient client;		

	protected:
		void setNextState(void (NetCheck::*state)(),int delay);
		virtual void callNextState();
		
	public:
		void setup();
		void loop();
		void initEthernet();
		void doneEthernet();
		
}; // class NetCheck
# endif
