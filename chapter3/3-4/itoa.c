/* Solution by C. Tondo and S. Gimpel - page 65 of 'The C Answer Book' */
#include <stdio.h>
#include <string.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

char *itoa(int n, char s[]);
char *itoa_kr(int n, char s[]);
char *reverse(char s[]);

int main()
{
	char number[3];

	printf("%d as a string: %s\n", 90, itoa(90, number));

	return 0;
}

char *itoa(int n, char s[])
{
	int i, sign;

	sign = n; /* record sign*/
	i = 0;

	do {
		s[i++] = abs(n % 10) + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */

	if (sign < 0)
		s[i++] = '-';

	s[i] = '\0';

	reverse(s);

	return s;
}

char *itoa_kr(int n, char s[])
{
	int i, sign;

	if ((sign = n) < 0)
		/* 
		 * Code below does not work for the largest negative number: 2^wordsize-1.
		 * This can not be converted to a positive number
		 * Because the largest positive number is (2^wordsize-1) - 1
		 */
		n = -n; /* make n positive */

	i = 0;

	do {
		s[i++] = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */

	if (sign < 0)
		s[i++] = '-';

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
