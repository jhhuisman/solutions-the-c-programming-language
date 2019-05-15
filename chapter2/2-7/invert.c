#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main()
{
	unsigned x;
	int p, n;

	x = 181;
	p = 5;
	n = 3;

	printf("Invert x=%x, p=%d, n=%d RESULT: %x\n", x, p, n, invert(x, p, n));

	return 0;
}

unsigned invert(unsigned x, int p, int n)
{
	return x ^ (~(~0 << n) << (p+1-n));
}
