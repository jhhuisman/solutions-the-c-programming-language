#include <stdio.h>

int lower(int c);

int main()
{
	printf("Result: %c\n", lower('Q'));

	return 0;
}

int lower(int c)
{
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A' : c;
}
