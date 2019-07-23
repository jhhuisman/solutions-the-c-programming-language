/* Solution based on solution by C. Tondo and S. Gimpel - page 65 of 'The C Answer Book' */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define abs(x) ((x) < 0 ? -(x) : (x))

char *itob(int n, char s[], int b);
char *reverse(char s[]);

int main()
{
	int number = 1976;
	char string[100];
	int base = 16;

	printf("%d to base-%d = %s\n", number, base, itob(number, string, base));

	return 0;
}

char *itob(int n, char s[], int b)
{
	int i, original_number, positive;

	original_number = n;
	i = 0;

	do {
		positive = abs(n % b); /* get next digit */
		s[i++] = (positive <= 9) ? positive + '0' : positive + 'a' - 10;
	} while ((n /= b) != 0); /* delete it */

	if (original_number < 0)
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
