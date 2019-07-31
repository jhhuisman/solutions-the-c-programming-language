#include <stdio.h>

#define MAXLINE 1000
#define TABBLANKS 8

void entab(int blankcount, int *pos_p);
int pos_after_tab(int *pos_p);

int main()
{
	int c, blankcount, pos;

	blankcount = 0;
	pos = 1;

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blankcount;
		else {
			entab(blankcount, &pos);
			putchar(c);
			blankcount = 0;

			if (c == '\n')
				pos = 1;
			else
				pos++;
		}
	}

	return 0;
}

void entab(int blankcount, int *pos_p)
{
	int endpos; /* end position after all tabs and spaces */

	endpos = *pos_p + blankcount;

	while (endpos >= pos_after_tab(pos_p)) {
		putchar('\t');
		*pos_p += pos_after_tab(pos_p);
	}

	while ((*pos_p)++ < endpos)
		putchar(' ');
}

int pos_after_tab(int *pos_p)
{
	int n_tabspaces; /* number of spaces needed for next tab */

	n_tabspaces = TABBLANKS - (*pos_p % TABBLANKS) + 1;

	return *pos_p + n_tabspaces;
}
