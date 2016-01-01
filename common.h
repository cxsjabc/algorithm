#ifndef COMMON_H
#define COMMON_H

#define PN(n)	printf(#n " is %d\n", (n));

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

#endif
