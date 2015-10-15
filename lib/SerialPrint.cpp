# if DEBUG
# define pri(x) Serial.println(x)
# else
# define pri(x)
# endif


	void setupSerialPrint() {

		# if DEBUG
		Serial.begin(9600);
		# endif
		
	} // setupSerialPrint()
	
