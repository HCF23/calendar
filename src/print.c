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
		{ "February", 	28, 0, 1 },
		{ "March", 	31, 0, 2 },
		{ "April", 	30, 0, 3 },
		{ "May", 	31, 0, 4 },
		{ "June", 	30, 0, 5 },
		{ "July", 	31, 0, 6 },
		{ "August", 	31, 0, 7 },
		{ "September", 	30, 0, 8 },
		{ "October", 	31, 0, 9 },
		{ "November", 	30, 0, 10 },
		{ "December", 	31, 0, 11 }
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
void print_month(int w, int i, int y)
{
	space((w / 2));
	P("\t%s\n", month[i].name);
	month[i].start_wday = sakamoto_day_of_the_week(y,i);
}

/*
 * print_days()
 *		print day names of the week
 */
void print_days(int m)
{
	for (int n=0; n<(DAY_MEM_SIZE*7); n+=DAY_MEM_SIZE)
		P("%4s", *(day)+n);
	P("\n  --------------------------\n");		
}

/*
 * print_dates()
 *		print numerical dates of the month
 * 		week by week
 * 		starting on correct day of the week
 */
void print_dates(int num_months, int m)
{
	//sakamoto indexes from 1
	int weekday = month[m].start_wday - 1;
	
	//print spaces to point at correct cords
	if (month[m].start_wday > 1)
		for (int i=weekday; i!=0; --i)
			P("    ");
	
	//print date, if date%7==0 then \n
	for (int i=1; i<=month[m].days; i++) {
		((i + weekday)%7) ? P("%4.2d", i) : P("%4.2d\n", i);
	}
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
	
	if (is_leap)
		month[1].days = 29;
	else
		month[1].days = 28;
	
	for (int months=0; months<12; months++) {
		print_month(num_months_on_line, months, year_to_display);
		print_days(months);
		print_dates(num_months_on_line, months);
	}
}

