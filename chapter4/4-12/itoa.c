#include <stdio.h>

char *itoa(int n, char s[]);

int main()
{
	char number[100];

	printf("-90 to string = %s\n", itoa(-90, number));
	
	return 0;
}

char *itoa(int n, char s[])
{
	static int i = 0;

	if (n < 0) {
		s[i++] = '-';
		n = -n; /* does not work for largest negative number in two complement */
	}

	if (n / 10)
		itoa(n /10, s);

	s[i++] = n % 10 + '0';
	s[i] = '\0';

	return s;
}
