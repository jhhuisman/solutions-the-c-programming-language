/* Based on the C Answer Book page 113 */
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *ppday);

int main()
{
	int year, month, day, yearday;

	year = 2019;
	month = 7;
	day = 30;
	yearday = day_of_year(year, month, day);

	printf("Day of year for %d-%d-%d = %d\n", day, month, year, yearday);

	month_day(year, yearday, &month, &day);

	printf("Day %d of year %d corresponds to date %d-%d-%d\n", yearday, year, day, month, year);

	return 0;
}

static char daytab[2][13] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	if (year < 0 || month < 1 || month > 12 || day < 1 || day > daytab[leap][month])
		return -1; /* invalid values */

	p = daytab[leap];

	while (--month)
		day += *++p;

	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;

	if (year < 0) {
		*pmonth = -1; /* invalid values */
		*pday = -1;
		return; /* invalid values */
	}

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	p = daytab[leap] + 1; /* set pointer to first month */

	while (yearday > *p)
		yearday -= *p++;

	if (*pmonth > 13 || *pmonth < 0 || *pday < 1 || *pday > *p) {
		*pmonth = -1; /* invalid values */
		*pday = -1;
	}
	else {
		*pmonth = p - daytab[leap];
		*pday = yearday;
	}
}
