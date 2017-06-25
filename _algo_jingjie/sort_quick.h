#ifndef SORT_QUICK_H
#define	SORT_QUICK_H

typedef int (*compare)(const void *d1, const void *d2);


int	quick_sort_int(int a[], int size);

#endif
