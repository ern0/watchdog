# define SONG_ZZZ 30,
# define SONG_END 0
# define TI 5, 25,
# define TA 30, 20,


static unsigned char ethernetInitSong[] = {
	1,1,
SONG_END };

static unsigned char ethernetRetrySoonSong[] = {
	5,5,
SONG_END };

static unsigned char httpSong[] = { SONG_ZZZ 
	TI TI TA 
SONG_END };

