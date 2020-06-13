/* Calendar
 *
 * 1) print 	months 		[x]
 * 		weekdays	[x]
 * 		dates		[x]
 * 		
 * 2) print correct date/day of week	[]
 *
 * 3) account for leap years			[]
 * 		leap_test needs testing		[]
 * 		account for feb 29		[]
 *
 * 4) reorganise file srtucture
 *
 * NTH
 * 	we need a scroll function to view past and future dates
 *	some linked list starting at $current_date
 *	buffering a year either side
 *	forgetting the rest should it be viewed and not
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../include/main.h"
#include "../include/calendar_print.h"


int main(void)
{	
	struct tm * date = {0};
	time_t current;
 
    int print_width = WIDTH;
	int months_per_line = do_months_per_line(print_width);
	
	if (months_per_line < 0) exit(1);
	
//	int user_input;
	int year = get_year();

	print_year(months_per_line, year);

	return 0;
}

/*
 * init_months
 * 		gets current date
 */
int get_year(void){
	
	time_t current;
    struct tm * date;

	time(&current);
	date = localtime(&current);
	P("\n%s",asctime(date));

	return (1900 + date->tm_year);

}


/*	while(1) {	
		
		if (scanf("%d", &user_input) > 0) {
			P("\n\n\tYou Entered: %d\n\n", user_input);
			
			switch (user_input) {
				case 'y': scanf("%d", &year); break;
				case KEYSTROKE_UP:      
				case KEYSTROKE_LEFT: year--; break;     
				case KEYSTROKE_DOWN:			     
				case KEYSTROKE_RIGHT: year++; break;
				       
			}


			print_year(months_per_line, year);
			P("Scroll with arrow keys or press 'y' to enter a year\n\n");
		}
	}
*/

