# include <stdio.h>
# include <unistd.h>

	# define LEDPIN 0
	int currentValue = -1;
	void digitalWrite(int pin,int value) {
		currentValue = value;
	}

	# include "../app/Blink.cpp"

	int main() {
	
		Blink blink;
		
		const static unsigned char song[] = { 1,3,1,2,0 };
		blink.play(song);
		
		for (int frame = 0; frame < 30; frame++) {
			blink.tick();
			printf("%5d: %d \n",frame,currentValue);
		}
	
	} // main()
