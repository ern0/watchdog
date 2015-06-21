# include "TimerInterrupt.hpp"


	void setupTimer() {

		cli();
  
		//set timer0 interrupt at 100Hz (100.00)
		TCCR0A = 0;
		TCCR0B = 0;
		TCNT0 = 0;
  
		OCR0A = 155;
		TCCR0A |= (1 << WGM01);
		TCCR0B |= (1 << CS02) | (1 << CS00);
		TIMSK0 |= (1 << OCIE0A);
		
		sei();

	} // setupTimer()


	ISR(TIMER0_COMPA_vect){
		interrupt();
	}
