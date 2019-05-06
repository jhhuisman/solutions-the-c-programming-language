#include <stdio.h>
#define MAXLINE 1000

void reverse(char string[], int length);

int main()
{
	int i, c;
	char line[MAXLINE];

	for (i = 0; i <= MAXLINE && (c = getchar()) != EOF; ++i) {
		line[i] = c;

		if (c == '\n') {
			line[i] = '\0';
			reverse(line, i);
			printf("%s\n", line);
			i = -1;
		}
	}

	
	return 0;
}

void reverse(char string[], int length)
{
	int i, n;
	char reverse[MAXLINE];

	n = 0;

	for (i = length; i >= 0; --i) {
		if (string[i] != '\0') {
			reverse[n] = string[i];
			++n;
		}
	} 

	reverse[length] = '\0';

	for (i = 0; i <= length; ++i) 
		string[i] = reverse[i];
}
