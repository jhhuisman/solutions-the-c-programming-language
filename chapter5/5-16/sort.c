#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000 /* max #lines to be sorted */

char *lineptr[MAXLINES]; /* pointers to text lines */
int fold = 0; /* 1 if case insensitive */
int directory = 0; /* 1 if directory order: compare only letters,
		      numbers and blanks*/

int readlines(char *lineptr[], char buffer[], int maxlines);
int my_getline(char *s, int lim);
int my_strcmp(char *s, char *t);
void writelines(char *lineptr[], int nlines, int reverse);
void qsort_kr(void *lineptr[], int left, int right,
	      int (*comp)(void *, void *));
int numcmp(char *, char *);

/* sort input lines */
int main(int argc, char *argv[])
{
	char buffer[5000];
	int option;
	int nlines; /* number of input lines read */
	int numeric = 0; /* 1 if numeric sort */
	int reverse = 0; /* 1 if reverse sort */

	while (argc-- > 1 && (*++argv)[0] == '-') {
		while (option = *++argv[0]) {
			switch(option) {
			case 'n':
				numeric = 1;
				break;
			case 'r':
				reverse = 1;
				break;
			case 'f':
				fold = 1;
				break;
			case 'd':
				directory = 1;
				break;
			}
		}
	}

	if ((nlines = readlines(lineptr, buffer, MAXLINES)) >= 0) {
		qsort_kr((void **) lineptr, 0, nlines-1,
			(int (*)(void*,void*))(numeric ? numcmp : my_strcmp));

		writelines(lineptr, nlines, reverse);

		return 0;
	}
	else {
		printf("input too big to sort\n");
		return 1;
	}
}

/* qsort_kr: sort v[left]...v[right] into increasing order */
void qsort_kr(void *v[], int left, int right, int (*comp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int, int);

	if (left >= right) /* do nothing if array containts < 2 elements */
		return;

	swap(v, left, (left + right)/2);

	last = left;

	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);

	swap(v, left, last);
	qsort_kr(v, left, last-1, comp);
	qsort_kr(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

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

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines, int reverse)
{
	int i;

	if (reverse == 1)
		for (i = nlines - 1; i >= 0; i--)
			printf("%s\n", lineptr[i]);
	else
		for (i = 0; i < nlines; i++)
			printf("%s\n", lineptr[i]);
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

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int my_strcmp(char *s, char *t)
{
	char a, b;

	for ( ; *s != '\0'; s++, t++) {
		/* compare letters, numbers and blanks */
		if (directory == 1) {
			while (!isalnum(*s) || *s == ' ')
				s++;
			while (!isalnum(*t) || *t == ' ')
				t++;
		}

		a = *s;
		b = *t;

		/* case insensitive */
		if (fold == 1) {
			a = tolower(a);
			b = tolower(b);
		}

		if (a != b)
			return a - b;
	}

	return 0;
}
