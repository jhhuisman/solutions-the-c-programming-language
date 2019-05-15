#include <stdio.h>

int rightrot(int x, int n);
int getbitcount(int x);

int main()
{
	int x, n;

	x = 181;
	n = 3;

	printf("rightrot x=%d, n=%d RESULT: %d\n", x, n, rightrot(x, n));

	return 0;
}

int rightrot(int x, int n)
{
	return (x >> n) | ((x & ~(~0 << n)) << (getbitcount(x) - n));
}

int getbitcount(int x)
{
	int count = 0;
	int number = x;

	while (number > 0) {
		count++;
		number = number >> 1;
	}

	return count;
}
