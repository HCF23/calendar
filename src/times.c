#include <stdio.h>
#include <time.h>
#include "../include/times.h"

#ifndef MAIN_H
#define MAIN_H
	#include "../include/main.h"
#endif

/*
 * get_year
 * 		gets current date
 *		incase no input is given
 */
int get_year(void) {
	
	time_t current;
    struct tm * date;

	time(&current);
	date = localtime(&current);
	P("\n%s",asctime(date));

	return (1900 + date->tm_year);

}

/*
 * sakamoto_day_of_the_week
 *			given the year and the month
 *			returns day of the week 1-7
 *
 */
int sakamoto_day_of_the_week(int year, int month) {
	static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};
	int y = year;
	int m = month+1;
	
	y -= m < 3; //y-1 if jan or feb
	return ((y + (y/4) - (y/100) + (y/400) + t[m-1] + 1)%7);
}

int gauss_weekday_jan1st(int year) {
/*
 * the weekday of jan1 in year Y
 * R(1+5(R(Y-1,4))+4(R(Y-1,100))+6(Y-1,400),7)
 *
 * R=y%m
 */ 
	int a,b,c,x,weekday;
 
	a=(year-1)%4;
	b=(year-1)%100;
	c=(year-1)%400;
	x = 1+(5*a)+(4*b)+(6*c);
	weekday = x%7;
	
	if ((weekday >= 0) && (weekday < 7)) 
		goto exit;
	else
		weekday = -1;
	
exit:	
	return weekday;
}

bool leap_test(int year) {
	return (year%4 && year%100 && year%400);
}

