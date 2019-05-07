#include <stdio.h>
#define OUTSIDE 0 /* Outside comment */
#define POSSIBLE 1 /* Possible comment beginning / */
#define INSIDE 2 /* Inside comment */

int main()
{
	int c, prev, incomment;

	incomment = OUTSIDE;

	while ((c = getchar()) != EOF) {
		if (c == '*' && prev == '/') {
			incomment = INSIDE;
		}

		if (incomment == OUTSIDE && c == '/') {
			incomment = POSSIBLE;
		}

		if (incomment == POSSIBLE && prev == '/' && c != '*') {
			putchar('/');
			incomment = OUTSIDE;
		}

		if (incomment == OUTSIDE) {
			putchar(c);
		}

		if (incomment == INSIDE && c == '/' && prev == '*') {
			incomment = OUTSIDE;
		}

		prev = c;
	}

	return 0;
}
