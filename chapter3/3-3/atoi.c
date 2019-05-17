#include <stdio.h>
#include <ctype.h>

int atoi(char s[]);

int main()
{
	char s[3];
	
	s[0] = '3';
	s[1] = '3';
	s[2] = '3';

	printf("%s to integer = %d\n", s, atoi(s));

	return 0;
}

int atoi(char s[])
{
	int i, n, sign;

	for (i = 0; isspace(s[i]); i++) /* skip white spaces */
		;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-') /* skip sign */
		i++;

	for (n = 0; isdigit(s[i]); i++)
		n = 10 * n + (s[i] - '0');

	return sign * n;
}
