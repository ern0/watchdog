# include "Tick.hpp"

		
	Tick::Tick(tick_t l) {
		init(l);
	} // Tick(l) ctor	


	Tick::Tick() {
		init(1000);
	} // Tick() ctor


	void Tick::init(tick_t l) {
	
		limit = l;
		value = 0;
		last = value;
		
	} // init()

	
	tick_t Tick::getValue() {
		return value;
	} // getValue()
	
	
	void Tick::inc() {
		
		value++;
		if (value == limit) value = 0;
		
	} // inc()
	
	
	 int Tick::elapsed(tick_t base) {	
	
		tick_t result = value - base;
		if (result >= 0) {
			return result;
		} else {
			return result + limit;
		}
		
	} // elapsed()


	bool Tick::changed() {
		
		bool result = ( last != value );
		last = value;
		
		return result;		
	} // changed()
