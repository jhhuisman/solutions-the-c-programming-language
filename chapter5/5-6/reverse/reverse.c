#include <stdio.h>
#include <string.h>

void reverse(char *s);

int main()
{
	char string[] = "String";

	reverse(string);

	printf("%s\n", string);
	
	return 0;
}

void reverse(char *s)
{
	char *sp; /* second pointer */
	char temp; /* temp variable needed to swap chars */

	for (sp = s + (strlen(s) - 1); s < sp; s++, sp--) {
		temp = *s;
		*s = *sp;
		*sp = temp;
	}
}
