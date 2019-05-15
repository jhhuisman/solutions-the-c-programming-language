#include <stdio.h>

int bitcount(unsigned x);

int main()
{
	unsigned x = 8;

	printf("bitcount x=%x RESULT %d\n", x, bitcount(x));

	return 0;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x)
{
	int b;

	/*
		x &= (x-1) deletes rightmost 1-bit in x
		
		Example:
		x 		= 7 = b0111
		x - 1 	= 6 = b0110

			0111 & 0110
		= 	0110 --> Last 1 deleted

		Example 2:
		x 		= 8 = b1000
		x - 1 	= 7 = b0111

			1000 & 0111
		= 	0000 --> last 1 deleted
    */
	for (b = 0; x != 0; x &= (x-1))
		b++;

	return b;
}
