# define SONG_ZZZ 30,
# define SONG_END 0
# define TI 5, 25,
# define TA 30, 20,


static unsigned char initEthernetSong[] = {
	1,1,
SONG_END };

static unsigned char failEthernetSong[] = { SONG_ZZZ
	TA TA TA
SONG_END };

static unsigned char timeoutSong[] = { SONG_ZZZ
	TA TA TA TA
SONG_END };

static unsigned char httpSong[] = {
	2,2,
SONG_END };

static unsigned char okaySong[] = { SONG_ZZZ
	TA TA TI TI TA
SONG_END };
