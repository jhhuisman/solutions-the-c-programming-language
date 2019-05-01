#include <stdio.h>

main()
{
	float celsius, fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	celsius = lower;

	printf("Celsius  Fahr\n");

	while (celsius <= upper) {
		fahr = celsius * (9.0/5.0) + 32;
		printf("%7.0f %5.1f\n", celsius, fahr);

		celsius = celsius + step;
	}
}
