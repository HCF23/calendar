#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "../include/main.h"
#include "../include/calendar_print.h"
#include "../include/times.h"

int term_width(void);
int months_per_line(void);

int main(int argc, char *argv[])
{
	int year;

    /* Rid output of compiler warns of unused argc */
	if (!(argc))
		exit(1);

	if (argv[1] == NULL)
		year = get_year();
	else
		year = atoi(argv[1]);

	print_year(months_per_line(), year);

	return 0;
}

int months_per_line(void)
{
	return (do_months_per_line(term_width()) < 0)
	    ? 1 : do_months_per_line(term_width());
}

int term_width(void)
{
	FILE *term;
	int width;

    /* Measure current terminal window width (cols) */
	term = popen("tput cols", "r");
	if (term != NULL) {
		while (1) {
			char *w;
			char buf[1000];
			w = fgets(buf, sizeof(buf), term);
			if (w != NULL) {
				width = atoi(w);
				break;
			}
		}
		pclose(term);
	} else {
        /* Set width JIC */
		width = 80;
	}

	return width;
}
