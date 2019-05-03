#include <stdio.h>
#define LONG_LINE_SIZE 80
#define MAX_LINE_SIZE 1000

void print_long_lines();

int main()
{
	print_long_lines();
	return 0;
}

void print_long_lines()
{
	int c, line_length;
	char current_line[MAX_LINE_SIZE];

	line_length = 0;

	while ((c = getchar()) != EOF) {
		if (c != '\n') {
			current_line[line_length] = c;
			++line_length;
		}
		else {
			if (line_length > LONG_LINE_SIZE) {
				current_line[line_length] = '\0';
				printf("%s\n", current_line);
				line_length = 0;
			}
		}
	}
}
