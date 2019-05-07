/*
 * Used this solution by Jeremy Yu:
 * https://github.com/ccpalettes/the-c-programming-language-second-edition-solutions/blob/master/Chapter2/Exercise%202-01/ranges.c
 */

#include <stdio.h>
#include <limits.h>

int main()
{
	printf("Range of char: [%d, %d].\n", CHAR_MIN, CHAR_MAX);
	printf("Range of singed char: [%d, %d].\n", SCHAR_MIN, SCHAR_MAX);
	printf("Range of unsinged char: [%d, %d].\n", 0, UCHAR_MAX);

    printf("Range of signed short int is [%hd, %hd].\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int is [%hu, %hu].\n", 0, USHRT_MAX);

    printf("Range of signed int is [%d, %d].\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int is [%u, %u].\n", 0, UINT_MAX);

    printf("Range of signed long int is [%ld, %ld].\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int is [0, %lu].\n", ULONG_MAX);

	return 0;
}
