/* Based on C Answer Book page 91 */
#include <stdio.h>
#include <ctype.h>
#include "calc.h"

/* getop: get next operator or numeric operand */
int getop(char s[])
{
	int i, c;
	static int lastch = 0;

	if (lastch == 0)
		c = getch();
	else {
		c = lastch;
		lastch = 0;
	}

	while ((s[0] = c) == ' ' || c == '\t')
		c = getch();

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-')
		return c; /* not a number */

	i = 0;

	/* differentiate between negative sign and substract operator */
	if (c == '-') {
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c; /* negative number */
		else {
			if (c != EOF)
				lastch = c;
			return '-'; /* substract operator */
		}
	}

	if (isdigit(c)) /* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.') /* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		lastch = c;

	return NUMBER;
}
