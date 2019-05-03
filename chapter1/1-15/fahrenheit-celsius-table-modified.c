#include <stdio.h>

float fahrenheit_to_celsius(float fahr);

/* Print Fahrenheit-Celsius table */
main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;

	printf("Fahr  Celsius\n");

	while (fahr <= upper) {
		printf("%4.0f %8.1f\n", fahr, fahrenheit_to_celsius(fahr));
		fahr = fahr + step;
	}
}

float fahrenheit_to_celsius(float fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
