# ifndef _Tick_hpp
# define _Tick_hpp


typedef signed long int tick_t;
# define TICKMIN(m) (50 * 60 * m)
# define TICKSEC(s) (50 * s)
# define TICKMILLI(ms) (50 * ms / 1000)

class Tick {
	
	protected:
		tick_t limit;
		tick_t value;
		tick_t last;
		
	public:
		Tick(tick_t l); // ctor
		Tick(); // ctor
		void init(tick_t l);
		tick_t getValue();
		void inc();
		int elapsed(tick_t base);	
		bool changed();
		
}; // class Tick

# endif
