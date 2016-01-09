#ifndef COMMON_H
#define COMMON_H

#include <stdio.h>

#define PN(n)	printf(#n " is %d\n", (n));
#define PU(n)	printf(#n " is %u\n", (n));
#define PL(n)	printf(#n " is %ld\n", (n));

#define P_HERE()	printf("execute %s@%d\n", __FUNCTION__, __LINE__);

#ifndef MAX
#define MAX(a, b)  ((a) > (b) ? (a) : (b))
#endif

#ifndef MIN
#define MIN(a, b)  ((a) < (b) ? (a) : (b))
#endif

#ifndef MAX3
#define MAX3(a, b, c)  (MAX(MAX((a), (b)), (c)))
#endif

#ifndef MIN3
#define MIN3(a, b, c)  (MIN(MIN((a), (b)), (c)))
#endif


#define ARR_SIZE(arr)		(sizeof(arr) / sizeof(arr[0]))

static inline void swap_by_addr(int *pa, int *pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

static inline void print_arr(int *arr, int size)
{
	int i = 0;

	while(i < size) {
		printf("%d ", arr[i]);
		++i;
	}
	printf("\n");
}

static int max_in_arr(int arr[], int start, int end)
{
	int max = arr[start];
	int i = start + 1;
	int max_index = start;
	while(i <= end) {
		if(arr[i] > max) {
			max = arr[i];
			max_index = i;
		}
		++i;
	}
	return max_index;
}

void print_by_byte(const void *p, int size);

#endif
