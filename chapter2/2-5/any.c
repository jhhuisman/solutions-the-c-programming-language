#include <stdio.h>

int any(char s1[], char s2[]);

int main()
{
	char hello[6];
	char lol[4];
	
	hello[0] = 'h';
	hello[1] = 'e';
	hello[2] = 'l';
	hello[3] = 'l';
	hello[4] = 'o';
	hello[5] = '\0';

	lol[0] = 'l';
	lol[1] = 'o';
	lol[2] = 'l';
	lol[3] = '\0';

	printf("%d\n", any(hello, lol));

	return 0;
}

int any(char s1[], char s2[])
{
	int i, j;

	for (i = 0; s1[i] != '\0'; i++) {
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j])
				return i;
		}
	}

	return -1;
}
