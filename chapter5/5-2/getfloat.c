/* Based on C Answer Book page 99 */
#include <stdio.h>
#include <ctype.h>

#define SIZE 100

int getfloat(float *pn);
int getch(void);
void ungetch(int);

int main()
{
	int n;
	float array[SIZE];

	for (n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
		;

	printf("Number 1 %f\n", array[0]);
	printf("Number 2 %f\n", array[1]);
	printf("Number 3 %f\n", array[2]);

	return 0;
}

int getfloat(float *pn)
{
	int c, sign;
	float power;

	while (isspace(c = getch())); /* skip white space */
		;

	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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

	for (*pn = 0.0; isdigit(c); c = getch())
		*pn = 10.0 * *pn + (c - '0'); /* integer part */

	if (c == '.')
		c = getch();

	for (power = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0'); /* fractional part */
		power *= 10.0;
	}

	*pn *= sign / power;

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
