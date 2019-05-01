#include <stdio.h>

main()
{
	int c, prev;

	while ((c = getchar()) != EOF) {
		if (c != ' ')
			putchar(c);
		if (c == ' ')
			if (prev != ' ')
				putchar(c);
		prev = c;
	}
}
