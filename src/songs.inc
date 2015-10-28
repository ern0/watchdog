# define SONG_BEGIN 2,
# define SONG_ZZZ 60,
# define SONG_END 0
# define TI 10, 50,
# define TA 60, 40,


static unsigned char initEthernetSong[] = {
	2,2,
SONG_END };

static unsigned char helloSong[] = { 70,
	TI TA
SONG_END };

static unsigned char retryEthernetSong[] = { 
	6,6,
SONG_END };

static unsigned char httpSong[] = {
	4,4,
SONG_END };

static unsigned char okaySong[] = { SONG_ZZZ
	TA TA TI TI TA
SONG_END };

static unsigned char alertSong[] = { SONG_BEGIN
	1, 2,
SONG_END };

static unsigned char protectedSong[] = { 
	TI TI
SONG_END };
