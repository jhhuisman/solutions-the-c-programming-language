#include <stdio.h>
#define LIMIT 1000

int main()
{
	int i, c, lim;

	i = 0;
	lim = LIMIT;
	char s[LIMIT];

	while ((c = getchar()) != EOF) {
		if (c != '\n') {
			for (i = 0; i < lim - 1; ++i)
				s[i] = c;
		}
	}
}
