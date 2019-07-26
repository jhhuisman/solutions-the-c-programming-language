/* Based on the solution in The C Answer Book page 91 */
#include <stdio.h>

#define swap(t,x,y) { 	t _tempv; \
						_tempv = y; \
						y = x; x = _tempv; }

int main()
{
	int number1 = 5;
	int number2 = 10;

	printf("Number 1 is %d\n", number1);
	printf("Number 2 is %d\n", number2);

	swap(int, number1, number2);

	printf("-------\n");
	printf("Number 1 is %d\n", number1);
	printf("Number 2 is %d\n", number2);

	return 0;
}
