/* Based on C Answer book page 107 */
#include <stdio.h>

int strindex(char *s, char *t);

int main()
{
	int position;

	char string1[] = "First string";
	char string2[] = "string";

	position = strindex(string1, string2);

	if (position != -1)
		printf("'%s' appears in '%s' at index position %d\n", string2, string1, position);
	else
		printf("'%s' does not appear in '%s'\n", string2, string1);

	return 0;
}

int strindex(char *s, char *t)
{
	char *start = s;
	char *sp, *tp;

	for ( ; *s; ++s) { /* loop through all characters of s */
		for (sp = s, tp = t; *tp && *sp == *tp; sp++, tp++) /* loops through all characters of t as long as char corresponds to char in s */
			continue;

		if (tp > t && *tp == '\0') /* checks if end of t is reached and thus appears in s */
			return s - start; /* return index of s where string t begins */
	}

	return -1;
}
