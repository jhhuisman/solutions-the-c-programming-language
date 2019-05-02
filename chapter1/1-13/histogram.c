#include <stdio.h>

main()
{
	int c, prev, i, nc, nw;

	nc = nw = 0;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\t' || c == '\n') {
			if (prev != ' ' && prev != '\t' && prev != '\n') {
				++nw;

				printf("%4d ", nw);

				for (i = 0; i < nc; ++i)
					putchar('|');

				putchar('\n');
				nc = 0;
			}
		}
		else {
			++nc;
		}

		prev = c;
	}
}
