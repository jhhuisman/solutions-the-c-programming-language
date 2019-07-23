#include <stdio.h>

#define MAXLINE 1000

int getline_kr(char line[], int max);
int strindex(char source[], char searchfor[]);
int strrindex(char source[], char searchfor[]);

/* find all lines matching pattern */
int main()
{
	char line[MAXLINE];
	char pattern[] = "ould";
	int found = 0;

	while (getline_kr(line, MAXLINE) > 0) {
		printf("%d\n", strrindex(line, pattern));

		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	}

	return found;
}

/* get line into s, return length */
int getline_kr(char s[], int lim)
{
	int c, i;

	i = 0;

	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;

	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';

	return i;
}

/* strrindex: return rightmoast occurence index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
	int i, j, k;

	int rightmost_index = -1; /* defaults to -1 = no match found, updates when match found */

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++) {
		}

		if (k > 0 && t[k] == '\0')
			rightmost_index = i;
	}

	return rightmost_index;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++, k++) {
		}

		if (k > 0 && t[k] == '\0')
			return i;
	}

	return -1;
}
