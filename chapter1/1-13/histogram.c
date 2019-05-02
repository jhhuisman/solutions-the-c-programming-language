#include <stdio.h>

main()
{
	int c, prev, i, nc;

	nc = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (prev != ' ' && prev != '\t' && prev != '\n') {
				for (i = 0; i < nc; ++i)
					putchar('|');

				putchar('\n');
				nc = 0;
			}
		}
		else {
			++nc;
			putchar(c);
		}

		prev = c;
	}
}
