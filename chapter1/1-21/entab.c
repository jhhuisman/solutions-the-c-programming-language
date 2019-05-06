#include <stdio.h>

#define MAXLINE 1000
#define TABBLANKS 4

void entab(int blankcount);

int main()
{
	int c, blankcount;

	blankcount = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blankcount;
		else {
			entab(blankcount);
			putchar(c);
			blankcount = 0;
		}
	}

	return 0;
}

void entab(int blankcount)
{
	while (blankcount >= 4) {
		putchar('\t');
		blankcount = blankcount - 4;
	}

	for (blankcount; blankcount > 0; --blankcount)
		putchar(' ');
}
