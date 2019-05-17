#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main()
{
	char s1[20], s2[100];

	s1[0] = '*';
	s1[1] = 'a';
	s1[2] = '-';
	s1[3] = 'z';
	s1[4] = '*';
	s1[5] = 'A';
	s1[6] = '-';
	s1[7] = 'Z';
	s1[8] = '*';
	s1[9] = '0';
	s1[10] = '-';
	s1[11] = '9';
	s1[12] = '*';
	s1[13] = '\0';

	expand(s1, s2);

	printf("s2: %s\n", s2);

	return 0;
}

void expand(char s1[], char s2[])
{
	int i, j;
	char c;

	for (i = 0, j = 0; i < strlen(s1); i++, j++) {
		if (s1[i] == 'a' && s1[i+1] == '-' && s1[i+2] == 'z') {
			for (c = 'a'; c <= 'z'; c = c + 1)
				s2[j++] = c;

			i = i + 3; /* Continue after a-z */
		}
		else if (s1[i] == 'A' && s1[i+1] == '-' && s1[i+2] == 'Z') {
			for (c = 'A'; c <= 'Z'; c = c + 1)
				s2[j++] = c;

			i = i + 3; /* Continue after A-Z */
		}
		else if (s1[i] == '0' && s1[i+1] == '-' && s1[i+2] == '9') {
			for (c = '0'; c <= '9'; c = c + 1)
				s2[j++] = c;

			i = i + 3; /* Continue after 0-9 */
		}

		s2[j] = s1[i];
	}

	s2[j] = '\0';
}
