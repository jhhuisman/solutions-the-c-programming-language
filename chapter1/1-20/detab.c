/* Inspired by C Answer Book page 31 */
#include <stdio.h>

#define MAXLINE 1000
#define TABBLANKS 8

void detab();

int main()
{
	int c;
	int pos = 1; /* position in line */

	while ((c = getchar()) != EOF) {
		if (c == '\t')
			detab(&pos);
		else if (c == '\n') {
			putchar(c);
			pos = 1;
		}
		else {
			putchar(c);
			pos++;
		}
	}

	return 0;
}

void detab(int *pos_p)
{
	int nspaces; /* number of spaces needed */
	
	nspaces = TABBLANKS - (*pos_p % TABBLANKS) + 1;

	while (nspaces-- > 0) {
		putchar(' ');
		(*pos_p)++;
	}
}
