#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main()
{
	char first[] = "First string";
	char second[] = "string";

	if (strend(first, second))
		printf("'%s' ends with '%s'\n", first, second);
	else
		printf("'%s' does not end with '%s'\n", first, second);

	return 0;
}

int strend(char *s, char *t)
{
	int len = strlen(t);

	while (*s) s++; /* find end s */
	while (*t) t++; /* find end t */

	s -= len;
	t -= len;

	return strcmp(s, t) == 0;
}
