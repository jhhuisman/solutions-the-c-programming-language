#include <ctype.h>

int getch(void);
void ungetch(void);

/* getop: get next operator or numeric operand */
int getop(char *s)
{
	int c;
	char startp = s;

	while ((*s = c = getch()) == ' ' || c == '\t')
		;

	*++s = '\0';

	if (!isdigit(c) && c != '.')
		return c; /* not a number */

	s = startp;

	if (isdigit(c))
		while (isdigit(*++s = c = getch()))
			;

	if (c == '.') /* collect fraction part */
		while (isdigit(*++s = c = getch()))
			;

	*s = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}
