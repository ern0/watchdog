# if DEBUG
# define print(x) Serial.println(x)
# else
# define print(x)
# endif


	void setupSerialPrint() {

		# if DEBUG
		Serial.begin(9600);
		# endif
		
	} // setupSerialPrint()
	
