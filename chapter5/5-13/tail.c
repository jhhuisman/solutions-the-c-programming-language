#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char buffer[], int maxlines);

int main(int argc, char *argv[])
{
	char buffer[5000];
	int nlines; /* number of input lines read */
	int nprint; /* number of lines to print */
	int lindex; /* index line to print */

	nprint = 10; /* default number of lines to print */
	nlines = readlines(lineptr, buffer, MAXLINES);

	if (argc == 2)
		nprint = atoi(&argv[1][1]);

	/* Make sure there are enough lines to be printed */
	if (nprint > nlines)
		nprint = nlines;

	for (lindex = nlines -1; nprint > 0; nprint--, lindex--)
		printf("%s\n", lineptr[lindex]);

        return 0;
}

#define MAXLEN 1000 /* max length of any input line */
#define MAX_STORAGE 5000 /* max length of any input line */

int my_getline(char *s, int lim);

/* readlines: read input lines */
int readlines(char *lineptr[], char buffer[], int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = buffer;
	char *line_end = buffer + MAX_STORAGE;

	nlines = 0;

	while ((len = my_getline(line, MAXLEN)) > 0)
		if (nlines >= maxlines || (p + len) > line_end)
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
			p += len;
		}

	return nlines;
}

int my_getline(char *s, int lim)
{
	int c;
	char *firstp = s;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		*s++ = c;

	if (c == '\n')
		*s++ = c;

	*s = '\0';

	return s - firstp;
}
