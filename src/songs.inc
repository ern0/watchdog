# define SONG_BEGIN 1,
# define SONG_ZZZ 30,
# define SONG_END 0
# define TI 5, 25,
# define TA 30, 20,


static unsigned char initEthernetSong[] = {
	1,1,
SONG_END };

static unsigned char helloSong[] = { 70,
	TI TA
SONG_END };

static unsigned char retryEthernetSong[] = { 
	3,3,
SONG_END };

static unsigned char httpSong[] = {
	2,2,
SONG_END };

static unsigned char okaySong[] = { SONG_ZZZ
	TA TA TI TI TA
SONG_END };

static unsigned char alertSong[] = { SONG_BEGIN
	TI TI TA
SONG_END };

static unsigned char protectedSong[] = { 
	TI TI
SONG_END };
