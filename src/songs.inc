# define SONG_BEGIN 60,
# define SONG_END 0
# define TI 5, 25,
# define TA 30, 20,


static unsigned char initSong[] = { 1, 
	1,1,
SONG_END };

static unsigned char deadSong[] = { SONG_BEGIN
	TI TI TI TI TA
SONG_END };

static unsigned char httpSong[] = { SONG_BEGIN
	TI TI TA 
SONG_END };

static unsigned char idleSong[] = { SONG_BEGIN
	TI
SONG_END };
