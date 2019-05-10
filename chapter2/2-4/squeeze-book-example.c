#include <stdio.h>

void squeeze(char s[], int c);

int main()
{
	char hello[9];

	hello[0] = 'h';
	hello[1] = 'e';
	hello[2] = 'l';
	hello[3] = 'l';
	hello[4] = 2;
	hello[5] = 'o';
	hello[6] = 2;
	hello[7] = 2;
	hello[8] = '\0';

	squeeze(hello, 2);

	printf("%s\n", hello);

	return 0;
}

void squeeze(char s[], int c)
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c)
			s[j++] = s[i];

	s[j] = '\0';
}
