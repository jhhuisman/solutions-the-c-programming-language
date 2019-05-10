#include <stdio.h>
#define YES 1
#define NO 0

void squeeze(char s1[], char s2[]);

int main()
{
	char hello[6];
	char hey[4];

	hello[0] = 'h';
	hello[1] = 'e';
	hello[2] = 'l';
	hello[3] = 'l';
	hello[4] = 'o';
	hello[5] = '\0';

	hey[0] = 'l';
	hey[1] = 'o';
	hey[2] = 'l';
	hey[3] = '\0';

	squeeze(hello, hey);

	printf("%s\n", hello);

	return 0;
}

/* Deletes each character in s1 that matches any character in s2 */
void squeeze(char s1[], char s2[])
{
	int i, j, k, instring;

	i = j = 0;

	while (s1[i] != '\0') {
		instring = NO;

		for (k = 0; s2[k] != '\0'; k++) {
			if (s1[i] == s2[k]) {
				instring = YES;
				break;
			}
		}

		if (instring == NO)
			s1[j++] = s1[i];

		i++;
	}

	s1[j] = '\0';
}
