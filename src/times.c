#include <stdio.h>
#include <time.h>
#include "../include/times.h"

#ifndef MAIN_H
#define MAIN_H
	#include "../include/main.h"
#endif

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

int gauss_weekday_jan1st(int year){
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

