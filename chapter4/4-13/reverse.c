#include <stdio.h>
#include <string.h>

char *reverse(char s[]);
char *r_reverse(char s[], int len);

int main()
{
	char string[] = "example";

	printf("%s reversed = %s\n", string, reverse(string));

	return 0;
}

char *reverse(char s[])
{
	return r_reverse(s, strlen(s) - 1);
}

char *r_reverse(char s[], int r_index)
{
	static int l_index = 0;
	int c;

	c = s[l_index];
	s[l_index] = s[r_index];
	s[r_index] = c;

	if (l_index++ < r_index--)
		r_reverse(s, r_index);

	return s;
}
