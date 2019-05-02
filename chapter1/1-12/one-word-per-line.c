#include <stdio.h>

/* Print input one word per line */
main()
{
	int c, previous;

	while((c = getchar()) != EOF) {
		if (c == '\t' || c == ' ' || c == '\n') {
			if (previous != '\t' && previous != ' ' && previous != '\n')
				putchar('\n');
		}
		else
			putchar(c);
		previous = c;
	}
}
