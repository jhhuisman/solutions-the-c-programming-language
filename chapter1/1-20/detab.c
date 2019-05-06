#include <stdio.h>

#define MAXLINE 1000
#define TABBLANKS 4

void detab();

int main()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			detab();
		else
			putchar(c);
	}

	return 0;
}

void detab()
{
	int i;

	for (i = 0; i <= TABBLANKS; ++i)
		putchar(' ');
}
