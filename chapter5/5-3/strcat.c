#include <stdio.h>

void strcatp(char *s, char *t);

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

	strcatp(hello, bye);

	printf("%s\n", hello);

	return 0;
}

void strcatp(char *s, char *t)
{
	while (*s) /* Find end of s */
		s++;

	while (*s++ = *t++)
		;
}
