#include <stdio.h>
#include <ctype.h>

int atoi(char *s);

int main()
{
	char number[] = "5243";

	printf("'%s' = %d\n", number, atoi(number));

	return 0;
}

int atoi(char *s)
{
	int i, n, sign;

	while (isspace(*s))
		s++; /* skip white space */

	sign = (*s == '-') ? -1 : 1;

	if (*s == '+' || *s == '-')
		s++; /* skip sign */

	for (n = 0; isdigit(*s); s++)
		n = 10 * n + (*s - '0');

	return sign * n;
}
