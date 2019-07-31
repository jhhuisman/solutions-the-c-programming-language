#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 1000
#define TABBLANKS 8
#define MAXTABSTOPS 100 /* max tab stops passed as command line option */

int tabstops[MAXTABSTOPS];
int tabstops_count = 0;

void entab(int blankcount, int *pos_p);
int next_tstop_pos(int pos);

int main(int argc, char *argv[])
{
	int c, blankcount, pos;

	blankcount = 0;
	pos = 1;

	/* Set tab stops as global array to be used in other functions */
	while (argc-- > 1)
		tabstops[tabstops_count++] = atoi(*++argv);

	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++blankcount;
		else {
			if (blankcount > 0)
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

	while (endpos >= next_tstop_pos(*pos_p)) {
		putchar('\t');
		*pos_p = next_tstop_pos(*pos_p);
	}

	while ((*pos_p)++ < endpos)
		putchar(' ');
}

int next_tstop_pos(int pos)
{
	int n_tabspaces; /* number of spaces needed for next tab stop */
	int index;

	/* Loop through optional given command line tab stops */
	for (index = 0; index < tabstops_count; index++)
		/* Check if tab stop is yet to come */
		if (tabstops[index] > pos)
			return tabstops[index];

	/* If there is no comming tab stop, then use defaults */
	n_tabspaces = TABBLANKS - (pos % TABBLANKS) + 1;

	return pos + n_tabspaces;
}
