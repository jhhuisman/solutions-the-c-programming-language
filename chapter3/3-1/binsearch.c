#include <stdio.h>
#include <time.h>

int binsearch(int x, int v[], int n);
int binsearch2(int x, int v[], int n);

int main()
{
	int x, v[5];

	x = 13;

	v[0] = 1;
	v[1] = 8;
	v[2] = 12;
	v[3] = 13;
	v[4] = 113;

    clock_t time; 
    time = clock(); 
  
	printf("binsearch result: %d\n", binsearch(x, v, 5));

    time = clock() - time; 
    double time_taken = ((double)time) / CLOCKS_PER_SEC;
    printf("binsearch took %f seconds to execute \n", time_taken); 

    clock_t time2; 
    time2 = clock(); 
  
	printf("binsearch2 result: %d\n", binsearch2(x, v, 5));

    time2 = clock() - time; 
    double time_taken2 = ((double)time2) / CLOCKS_PER_SEC;
    printf("binsearch2 took %f seconds to execute \n", time_taken2); 

	return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low+high) / 2;

		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}

	return -1;
}

int binsearch2(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low < high) {
		mid = (low+high) / 2;

		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
	}

	return (x == v[low-1]) ? low - 1 : -1;
}
