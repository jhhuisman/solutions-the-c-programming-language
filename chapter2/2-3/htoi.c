#include <stdio.h>

int htoi(char s[]);

int main()
{
	char hex[7];

	hex[0] = 'f';
	hex[1] = 'f';
	hex[2] = 'f';
	hex[3] = 'f';
	hex[4] = 'f';
	hex[5] = 'f';
	hex[6] = '\0';

	printf("%s to int: %d\n", hex, htoi(hex));

	return 0;
}

int htoi(char s[]) {
	int i, n, hexdigit;

	n = 0;
	i = 0;

	/* Skip optional 0x or 0X at start */
	if (s[i] == '0') {
		++i;

		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}

	for (i = i; s[i] != '\0'; ++i) {
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if(s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else {
			n = 0;
			printf("Invalid hexidecmical string.\n");
			break;
		}

		n = 16 * n + hexdigit;
	}

	return n;
}
