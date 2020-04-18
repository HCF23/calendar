#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void space(int n) { while(n-- > 0) putchar(' '); }

void print_month(int w, int i)
{
	space((w / 2));
	P("%s\n", month[i].name);
}

void print_days(int start, int width)
{
	for (int i=start; i<=width; i+=DAY_MEM_SIZE)
		P(" %s ", *(day)+i);
	P("\n");		
}

void print_dates(void)
{
	while(1){
		
	}
}

int do_months_per_line(int width)
{
	if ((width < MIN_WIDTH) || (width > MAX_WIDTH))
		return (-1);
	return (width / 20);
}

void print_year(int num_months_on_line)
{
	for (int months=0; months<12; months++){
		print_month(num_months_on_line, months);
		print_days(day_place, num_months_on_line);
		print_dates(num_months_on_line);
	}
}

int main(void)
{
	int day_place = PLACE;
       	int print_width = WIDTH;
	int months_per_line = do_months_per_line(print_width);
	
	if (months_per_line < 0) exit(1);

	init_months();
	print_year(months_per_line);
	return 0;
}


