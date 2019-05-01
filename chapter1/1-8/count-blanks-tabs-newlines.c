#include <stdio.h>

main()
{
	int blankcount, tabcount, linecount;
	int c;

	blankcount = 0;
	tabcount = 0;
	linecount = 0;

	while ((c = getchar()) != EOF)
		if (c == ' ')
			++blankcount;
		else if (c == '\t')
			++tabcount;
		else if (c == '\n')
			++linecount;

	printf("Number of blanks: %d\n", blankcount);
	printf("Number of tabs: %d\n", tabcount);
	printf("Number of lines: %d\n", linecount);
}
