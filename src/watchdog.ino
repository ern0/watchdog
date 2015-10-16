# define DEBUG (1)
# define RELAYPIN 9
# define BUZZPIN 8
# define LEDPIN 13

# if ( defined(__unix__) || defined(__APPLE__) )
	# define TIMER1 ( 1000 * 1000 )   
	# include "../../posixino/src/posixino.cpp"
# else
	# include <SPI.h>
	# include <Ethernet.h>
# endif

# include "../lib/SerialPrint.cpp"


void setup()
{
pinMode(13,OUTPUT);
digitalWrite(13,0);
  cli();
  
//set timer1 interrupt at 1Hz (1.00)
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  
  OCR1A = 62499;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);

  sei();
}


ISR(TIMER1_COMPA_vect){

  digitalWrite(13, 1 - digitalRead(13));
}

void loop() {
  // your program here...
}
