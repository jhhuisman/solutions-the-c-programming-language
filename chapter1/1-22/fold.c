#include <stdio.h>
#define MAXLINE 55

void fold(char line[], int length);

int main()
{
	int c, index;
	char line[1000];

	index = 0;

	while ((c = getchar()) != EOF) {
		line[index] = c;

		if (c == '\n') {
			line[index] = '\0';

			if (index > MAXLINE)
				fold(line, index);

			printf("%s\n", line);
			index = 0;
		}
		else {
			index++;
		}
	}

	return 0;
}

void fold(char line[], int length)
{
	int i, marker_high, marker_low;

	marker_high = MAXLINE;
	marker_low = 0;

	for (i = marker_high; i >= marker_low; --i) {
		if (line[i] == ' ' || line[i] == '\t') {
			line[i] = '\n';
			marker_low = i;
			marker_high = marker_high + MAXLINE;
			i = marker_high;
		}
	}
}
