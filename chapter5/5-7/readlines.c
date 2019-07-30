/* Based on C Answer Book page 109 */
#include <stdio.h>

#define MAXLEN 1000 /* max length of any input line */
#define MAX_STORAGE 5000 /* max length of any input line */

/* readlines: read input lines */
int readlines(char *lineptr[], char buffer[], int maxlines)
{
	int len, nlines;
	char line[MAXLEN];
	char *p = buffer;
	char *line_end = buffer + MAX_STORAGE;

	nlines = 0;

	while ((len = getline(line, MAXLEN)) > 0)
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
