#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

char *itoa(int n, char s[], int w);
char *reverse(char s[]);

int main()
{
	char number[10];

	printf("%d as a string: (%s)\n", 90, itoa(90, number, 4));

	return 0;
}

char *itoa(int n, char s[], int w)
{
	int i, sign, blanks;

	sign = n; /* record sign*/
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0'; /* get next digit */
	} while ((n /= 10) != 0); /* delete it */

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	/* Add padding blanks */
	for (blanks = w - strlen(s); blanks > 0; --blanks) {
		s[i++] = ' ';
	}

	s[i] = '\0';

	reverse(s);

	return s;
}

char *reverse(char s[])
{
	int c, i, j;

	for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}

	return s;
}
