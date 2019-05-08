#include <stdio.h>
#define LIMIT 1000

int main()
{
	int i, c, lim;

	lim = LIMIT;
	char s[LIMIT];

	/* Credit for akiracadet https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_2 */
	for (i = 0; (i < lim -1) + ((c = getchar()) != '\n') + (c != EOF) == 3; ++i) 
		s[i] = c;
}
