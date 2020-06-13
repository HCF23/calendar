#include <time.h>

#define P(...) 			printf(__VA_ARGS__)
#define DAY_MEM_SIZE 		(3) // char + char + \0
#define PLACE 			(0)
#define WIDTH			(20)
#define MIN_WIDTH		(20)
#define MAX_WIDTH		(132)

#define KEYSTROKE_UP 		/*(0x48)*/ (72)
#define KEYSTROKE_LEFT 		/*(0x4B)*/ (75)
#define KEYSTROKE_RIGHT 	/*(0x4D)*/ (77)
#define KEYSTROKE_DOWN 		/*(0x50)*/ (80)

char* day[] = {"Mo", "Tu", "We", "Th", "Fr", "Sa", "Su"};

struct months {
	const char *name;
	int days, start_wday, place;
} month[12] = {
		{ "January", 	31, 0, 0 },
		{ "February", 	28, 0, 0 },
		{ "March", 	31, 0, 0 },
		{ "April", 	30, 0, 0 },
		{ "May", 	31, 0, 0 },
		{ "June", 	30, 0, 0 },
		{ "July", 	31, 0, 0 },
		{ "August", 	31, 0, 0 },
		{ "September", 	30, 0, 0 },
		{ "October", 	31, 0, 0 },
		{ "November", 	30, 0, 0 },
		{ "December", 	31, 0, 0 }
};

int get_year(void);
