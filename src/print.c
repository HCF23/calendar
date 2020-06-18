#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/*theres generic constants and functions defined here*/
#ifndef MAIN_H
#define MAIN_H
	#include "../include/main.h"
#endif

#ifndef CAL_PRINT_H
#define CAL_PRINT_H
	#include "../include/calendar_print.h"
#endif

#include "../include/times.h"

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
	P("\t%s\n", month[i].name);
}

/*
 * print_days()
 *		for months to print on a line
 *		print days of the week
 *		starting on start day for that month
 */
void print_days(int m)
{
	int start = month[m].start_wday;

	for (int n=start; n<(DAY_MEM_SIZE*7); n+=DAY_MEM_SIZE)
		P("%4s", *(day)+n);
	P("\n  --------------------------\n");		
}

void print_dates(int num_months, int m)
{
	for(int i=1; i<=month[m].days; i++)
		(i%7) ? P("%4.2d", i) : P("%4.2d\n", i);

	P("\n\n\n");

}

int do_months_per_line(int width)
{
	if ((width < MIN_WIDTH) || (width > MAX_WIDTH))
		return (-1);
	return (width / 20);
}

void print_year(int num_months_on_line, int year_to_display)
{
	bool is_leap = leap_test(year_to_display);
	
	P("isleap(%d)\n", is_leap);
	
	for (int months=0; months<12; months++){
		print_month(num_months_on_line, months);
		print_days(months);
		print_dates(num_months_on_line, months);
	}
}

