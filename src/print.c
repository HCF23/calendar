/* Calendar
 *
 * 1) print 	months 		[x]
 * 		weekdays	[]
 * 		dates		[]
 * 		
 * 2) start from current date
 *    print correct date/day of week
 *
 *
 * NTH
 *	we need a calendar to print days of the month
 *	in regular week format
 *	with the month starting on different days of the week
 *
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

#define P(...) 		printf(__VA_ARGS__)
#define DAY_MEM_SIZE 	(3) // char + char + \0
#define PLACE 		(0)
#define WIDTH		(20)
#define MIN_WIDTH	(20)
#define MAX_WIDTH	(132)



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

/*
 * init_months
 * 		gets current date
 */
void init_months(struct tm * date){
	
	time_t current;
 
	time(&current);
	date = localtime(&current);
	P("\n%s",asctime(date));

}

/*
 * space()
 *		prints nice spacing between dates
 */
void space(int n) { while(n-- > 0) putchar(' '); }

/*
 * print_month()
 *		prints all month names on a line
 */
void print_month(int w, int i)
{
	space((w / 2));
	P("%s\n", month[i].name);
}

/*
 * print_days()
 *		for months to print on a line
 *		print days of the week
 *		starting on start day for that month
 */
void print_days(int start, int width)
{
	for (int m=0; m<width; m++)
		for (int n=start; n<(DAY_MEM_SIZE*7); n+=DAY_MEM_SIZE)
		       	P(" %s ", *(day)+n);
		P("\n");		
}

void print_dates(int num_months, int m)
{
	for(int i=1; i<=month[m].days; i++)
		(i%7) ? P(" %.2d ", i) : P(" %.2d \n", i);

	P("\n");

}
int do_months_per_line(int width)
{
	if ((width < MIN_WIDTH) || (width > MAX_WIDTH))
		return (-1);
	return (width / 20);
}

void print_year(int num_months_on_line)
{
	int day_place = 0;

	for (int months=0; months<12; months++){
		print_month(num_months_on_line, months);
		print_days(day_place, num_months_on_line);
		print_dates(num_months_on_line, months);
	}
}

int main(void)
{	
	struct tm * date = {0};
	time_t current;
 
	time(&current);
	date = localtime(&current);
	P("\nToday's date:\t%s\n",asctime(date));

       	int print_width = WIDTH;
	int months_per_line = do_months_per_line(print_width);
	P("Printing %d months per line\n", months_per_line);
	
	if (months_per_line < 0) exit(1);

	print_year(months_per_line);

	return 0;
}


