#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../include/main.h"
#include "../include/calendar_print.h"

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

bool leap_test(int year) {
	return (year%4 && year%100 && year%400);
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

