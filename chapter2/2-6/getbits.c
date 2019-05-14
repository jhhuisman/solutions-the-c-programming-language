#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
	printf("%d\n", getbits(15, 3, 2));

	return 0;
}

unsigned getbits(unsigned x, int p, int n) {
	return (x >> (p+1-n)) & ~(~0 << n);
}

/*
x = number
p = position
n = number (of bits?)

Example:
x = 15
p = 3
n = 4

return (15 >> (3+1-4)) & ~(~0 << 4);
	   (15 >> (3+1-4)) & ~(~0 << 4);
	   (15 >> 0) & ~(~0 << 4);
	   15 & ~(11111111 << 4);
	   15 & ~(11110000);
	   15 & 00001111;
	   00001111 & 00001111;
	   00001111;
	   15;
	   
Example 2:
x = 15
p = 3
n = 2

return (15 >> (3+1-2)) & ~(~0 << 2);
	   (15 >> 2) & ~(~0 << 4);
	   (00001111 >> 2) & ~(~0 << 4);
	   00000011 & ~(~0 << 4);
	   00000011 & ~(11111111 << 4);
	   00000011 & ~11110000;
	   00000011 & 00001111;
	   00000011;
	   3;
*/
