#ifndef SORT_H
#define	SORT_H

typedef int (*compare)(const void *d1, const void *d2);

int	insert_sort(void *data, int data_cnt, int ele_size, compare);

int	insert_sort_int(void *data, int data_cnt);

#endif
