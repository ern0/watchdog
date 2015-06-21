# include "TimerInterrupt.hpp"


	void setupTimer() {

	  cli();
	  
		// set timer1 interrupt at 50Hz (50.00)
	  TCCR1A = 0;
	  TCCR1B = 0;
	  TCNT1 = 0;
	  
	  OCR1A = 39999;
	  TCCR1B |= (1 << WGM12);
	  TCCR1B |= (1 << CS11);
	  TIMSK1 |= (1 << OCIE1A);
	
	  sei();

	} // setupTimer()


	ISR(TIMER1_COMPA_vect) {
		interrupt();
	}
