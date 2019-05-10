#include <stdio.h>

void strcat_kr(char s[], char t[]);

int main()
{
	char hello[11];
	char bye[4];

	hello[0] = 'h';
	hello[1] = 'e';
	hello[2] = 'l';
	hello[3] = 'l';
	hello[4] = 'o';
	hello[5] = '\0';

	bye[0] = 'b';
	bye[1] = 'y';
	bye[2] = 'e';
	bye[3] = '\0';

	strcat_kr(hello, bye);

	printf("%s\n", hello);

	return 0;
}

/* strcat: concatenate t to the end of s; s must be big enough */
void strcat_kr(char s[], char t[])
{
	int i, j;

	i = j = 0;

	/* Find end of s */
	while (s[i] != '\0')
		i++;

	while ((s[i++] = t[j++]) != '\0')
		;
}
