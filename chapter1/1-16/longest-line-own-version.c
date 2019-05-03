#include <stdio.h>
#define MAXLINE 1000

int get_longest_line_length();
void set_longest_line(char line[], char longest[], int length);

int main()
{
	char longest[MAXLINE];
	int longest_line_length;

	longest_line_length = get_longest_line_length(longest);

	printf("Longest line is:\n%s\n", longest);

	return 0;
}

/* Sets longest char array
 * Returns longest line length as int */
int get_longest_line_length(char longest[])
{
	int c, i, length, max;
	char current_line[MAXLINE];

	length = max = 0;

	while ((c = getchar()) != EOF) {
		if (c != '\n') {
			current_line[length] = c;
			length++;
		}
		else {
			if (length > max) {
				set_longest_line(current_line, longest, length);
				max = length;
			}
			length = 0;
		}
	}

	return max;
}

void set_longest_line(char line[], char longest[], int length)
{
	int i;

	for (i = 0; i < length; ++i)
		longest[i] = line[i];
}
