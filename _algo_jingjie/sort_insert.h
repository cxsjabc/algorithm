#ifndef SORT_INSERT_H
#define	SORT_INSERT_H

typedef int (*compare)(const void *d1, const void *d2);

int	insert_sort(void *data, int data_cnt, int ele_size, compare);

int	insert_sort_int(void *data, int data_cnt);
int	insert_sort_int1(int a[], int size, int dir, unsigned long long *record_exec_cnt);

#endif
