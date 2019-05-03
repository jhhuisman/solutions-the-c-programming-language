#include <stdio.h>

/* Histogram for characters a, c and q (lowercase) */
main()
{
	int c, i, acount, ccount, qcount;

	acount = ccount = qcount = 0;

	while ((c = getchar()) != EOF) {
		if (c == 'a')
			++acount;
		else if (c == 'c')
			++ccount;
		else if (c == 'q')
			++qcount;
	}

	printf("a: ");
	for (i = 0; i < acount; ++i)
		putchar('|');

	printf("\nc: ");
	for (i = 0; i < ccount; ++i)
		putchar('|');

	printf("\nq: ");
	for (i = 0; i < qcount; ++i)
		putchar('|');

	putchar('\n');
}
