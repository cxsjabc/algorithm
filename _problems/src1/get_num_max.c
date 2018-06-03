#include "common_local.h"

long get_num_max(int arr[], int size)
{
	long *p;
	int i;
	long max;

	p = (long *)malloc(size * sizeof(long));	
	assert(p);

	p[0] = arr[0];
	p[1] = arr[1];
	p[2] = MAX(arr[1], arr[0] + arr[2]);

	for(i = 3; i < size; ++i)
		p[i] = arr[i] + MAX(p[i - 2], p[i - 3]);

	max = p[0];
	for(i = 1; i < size; ++i)
		if(p[i] > max)
			max = p[i];

	free(p);
	return max;
}

int main(int argc, char *argv[])
{
#define N	10
	int arr[N];
	int c = 6;

	if(argc > 1)
		c = atoi(argv[1]);	
	if(c > N && c <= 0)
		c = N;
	gen_basic_arr(arr, c, 1, 30);
	print_arr(arr, c);

	PL(get_num_max(arr, c));
    return 0;
}
