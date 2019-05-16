#include <stdio.h>

void escape(char s[], char t[]);

int main()
{
	char s[6], t[15];

	s[0] = 'H';
	s[1] = '\n';
	s[2] = 'l';
	s[3] = '\t';
	s[4] = 'o';
	s[5] = '\0';

	t[0] = '\0';

	printf("%s\n", s);

	escape(s, t);

	printf("%s\n", t);

	return 0;
}

void escape(char s[], char t[])
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++, j++) {
		switch (s[i]) {
			case '\n':
				t[j++] = '\\';
				t[j] = 'n';
				break;
			case '\t':
				t[j++] = '\\';
				t[j] = 'T';
				break;
			default:
				t[j] = s[i];
				break;
		}
	}

	t[j] = '\0';
}
