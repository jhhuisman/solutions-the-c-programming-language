#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{
	unsigned x, y;
	int p, n;

	x = 171;
	y = 170;
	p = 5;
	n = 3;

	printf("Setbits x=%x, y=%x, p=%d, n=%d RESULT: %x\n", x, y, p, n, setbits(x, p, n, y));

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	return (x & ~(~(~0 << n) << (p+1-n))) | (y & ~(~0 << n)) << (p+1-n);
}
