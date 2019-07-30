#include <stdio.h>
#include <string.h>

void itoa(int n, char *s);
void reverse(char *s);

int main()
{
	char number[50];

	itoa(-4938, number);

	printf("-4938 as a string: '%s'\n", number);

	return 0;
}

void itoa(int n, char *s)
{
	int original;
	char *start = s;

	if ((original = n) < 0) /* record original number */
		n = -n; /* make n positive */

	do {
		*s++ = n % 10 + '0'; /* get next digit */
	} while ((n /= 10) > 0); /* delete it */

	if (original < 0)
		*s++ = '-';

	*s = '\0';

	reverse(start);
}

void reverse(char *s)
{
	char *sp; /* second pointer */
	char temp; /* temp variable needed to swap chars */

	for (sp = s + (strlen(s) - 1); s < sp; s++, sp--) {
		temp = *s;
		*s = *sp;
		*sp = temp;
	}
}
