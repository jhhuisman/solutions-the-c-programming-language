#include <stdio.h>

char buf;
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	int ch;

	if (bufp == 1)
		ch = buf;
	else
		ch = getchar();

	bufp = 0;
	return ch;
}

void ungetch(int c) /* push character back on input */
{
	bufp = 1;
	buf = c;
}
