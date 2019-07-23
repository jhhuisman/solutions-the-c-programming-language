#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main()
{
	char fstring[] = "22.5e-2";

	printf("%s to double = %f\n", fstring, atof(fstring));

	return 0;
}

/* atof: convert string to double */
double atof(char s[])
{
	double val, power;
	int i, sign, exponent;

	for (i = 0; isspace(s[i]); i++) /* skip white space */
		; 

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++; /* skip sign */

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');

	if (s[i] == '.')
		i++;

	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	val = sign * val / power;

	if (s[i] != 'e' && s[i] == 'E')
		return val;

	/* Handle possible scientific e notation */
	if (s[i] == 'e' || s[i] == 'E')
		i++;

	sign = (s[i] == '-') ? -1 : 1;

	if (s[i] == '+' || s[i] == '-')
		i++; /* skip sign */

	for (exponent = 0; isdigit(s[i]); i++)
		exponent = 10 * exponent + (s[i] - '0');

	if (sign == 1)
		while (exponent-- > 0)
			val *= 10;
	else
		while (exponent-- > 0)
			val /= 10;

	return val;
}
