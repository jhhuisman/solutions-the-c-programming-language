#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getint(int *pn);
int getch(void);
void ungetch(int);

int main()
{
	int n, array[SIZE];

	for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
		;

	printf("Number 1 %d\n", array[0]);
	printf("Number 2 %d\n", array[1]);
	printf("Number 3 %d\n", array[2]);

	return 0;
}

int getint(int *pn)
{
	int c, sign;

	while (isspace(c = getch())); /* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c); /* it's not a number */
		return 0;
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '+' || c == '-') {
		c = getch();

		if (!isdigit(c) && c != EOF) {
			ungetch(c); /* it's not a number */
			return 0;
		}
	}

	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');

	*pn *= sign;

	if (c != EOF)
		ungetch(c);

	return c;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) /* push character back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
