#include <stdio.h>
#define MAX_LINE_LENGTH 1000

void improve_lines();
void end_line(char line[], int line_length);
void remove_trailing_spaces(char line[], int line_length);
void remove_blank_lines(char line[], int line_length);

int main()
{
	improve_lines();
	return 0;
}

void improve_lines()
{
	int c, line_length;
	char current_line[MAX_LINE_LENGTH];

	line_length = 0;

	while ((c = getchar()) != EOF) {
		if (c != '\n') {
			current_line[line_length] = c;
			line_length++;
		}
		else {
			if (line_length > MAX_LINE_LENGTH)
				continue;

			end_line(current_line, line_length);
			remove_trailing_spaces(current_line, line_length);
			remove_blank_lines(current_line, line_length);

			if (current_line[0] != '\0')
				printf("%s\n", current_line);

			line_length = 0;
		}
	}
}

void end_line(char line[], int line_length)
{
	line[line_length] = '\0';
}

void remove_trailing_spaces(char line[], int line_length)
{
	int i;

	for (i = line_length; i >= 0; --i) {
		if (line[i] == ' ' || line[i] == '\t')
			line[i] = '\0';
		else 
			break;
	}
}

void remove_blank_lines(char line[], int line_length)
{
	int i, non_blank_chars;

	non_blank_chars = 0;

	for (i = line_length; i >= 0; --i) {
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\0') {
			++non_blank_chars;
			break;
		}
	}

	if (non_blank_chars == 0)
		line[0] = '\0';
}
