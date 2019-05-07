#include <stdio.h>
#define EVEN 0
#define UNEVEN 1

#define OUTSIDE 0 /* Outside comment */
#define INSIDE 1 /* Inside comment */

int main()
{
	int c, prev, incomment, parentheses, brackets, braces, single_quotes, double_quotes;

	parentheses = brackets = braces = single_quotes = double_quotes = EVEN;

	incomment = OUTSIDE;

	while ((c = getchar()) != EOF) {
		if (c == '*' && prev == '/') {
			incomment = INSIDE;
		}

		if (incomment == INSIDE && c == '/' && prev == '*') {
			incomment = OUTSIDE;
		}

		if (incomment == INSIDE) {
			prev = c;
			continue;
		}

		if (c == '(')
			parentheses = UNEVEN;

		if (c == ')' && parentheses == UNEVEN)
			parentheses = EVEN;

		if (c == '[')
			brackets = UNEVEN;

		if (c == ']' && brackets == UNEVEN)
			brackets = EVEN;

		if (c == '{')
			braces = UNEVEN;

		if (c == '}' && braces == UNEVEN)
			braces = EVEN;

		if (c == '\'') {
			if (single_quotes == EVEN)
				single_quotes = UNEVEN;
			else
				single_quotes = EVEN;
		}

		if (c == '"') {
			if (double_quotes == EVEN)
				double_quotes = UNEVEN;
			else
				double_quotes = EVEN;
		}

		prev = c;
	}

	if (parentheses == UNEVEN)
		printf("Error: unbalanced parentheses.\n");

	if (brackets == UNEVEN)
		printf("Error: unbalanced brackets.\n");

	if (braces == UNEVEN)
		printf("Error: unbalanced braces.\n");

	if (single_quotes == UNEVEN)
		printf("Error: unbalanced quotes (single).\n");

	if (double_quotes == UNEVEN)
		printf("Error: unbalanced quotes (double).\n");

	return 0;
}
