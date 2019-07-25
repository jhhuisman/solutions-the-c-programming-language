#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char *s)
{
	int index;

	for (index = strlen(s); index >= 0; --index)
		ungetch(s[index]);
}
