# include "TimerInterrupt.hpp"


	void setupTimer() {
	
return;
		cli();
  
		//set timer2 interrupt at 1000Hz (1000.00)
		TCCR2A = 0;
		TCCR2B = 0;
		TCNT2 = 0;
		
		OCR2A = 249;
		TCCR2A |= (1 << WGM21);
		TCCR2B |= (1 << CS22);
		TIMSK2 |= (1 << OCIE2A);
			
		sei();

	} // setupTimer()


	int irqdiv = 0;

/*
	ISR(TIMER2_COMPA_vect) {
	
		irqdiv++;
		if (irqdiv < 15) return;
		irqdiv = 0;
		
		interrupt();
	}

*/
