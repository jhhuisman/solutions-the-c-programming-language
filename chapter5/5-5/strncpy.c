/* Solutions inpired on C Answer Book page 103 */
#include <stdio.h>

void my_strncpy(char *s, char *t, int n);
void my_strncat(char *s, char *t, int n);
int my_strncmp(char *s, char *t, int n);

int main()
{
	char src[] = "String to be copied";
	char dest[50];

	my_strncpy(dest, src, 4);

	printf("strncpy: %s\n", dest);

	char src2[] = "source string";
	char dest2[100] = "beginning of destination string ";

	my_strncat(dest2, src2, 3);

	printf("strcat: %s\n", dest2);

	char string1[] = "string 1";
	char string2[100] = "string 2";

	if (my_strncmp(string1, string2, 3) == 0)
		printf("first %d chars of '%s' and '%s' are equal!\n", 3, string1, string2);
	else
		printf("first %d chars of '%s' and '%s' are different!\n", 3, string1, string2);

	return 0;
}

void my_strncpy(char *s, char *t, int n)
{
	while ((*s++ = *t++) && --n > 0)
		continue;

	*s = '\0';
}

void my_strncat(char *s, char *t, int n)
{
	while (*s) /* Find end of s */
		s++;

	while (--n > 0 && (*s++ = *t++))
		continue;

	*s = '\0';
}

int my_strncmp(char *s, char *t, int n)
{
	while (n-- > 0 && (*s && *t)) { /* loop through n characters of s and t */
		if (*s++ != *t++) /* compare each character */
			return *s - *t; /* return difference when chars are different */
	}
}
