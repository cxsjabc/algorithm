#ifndef ARRAY_H
#define	ARRAY_H


void	init_basic_arr(int ar[], int size, int start_value);
void	reset_basic_arr(int arr[], int size, int reset_value);
void	init_reverse_basic_arr(int arr[], int size, int start_value);

typedef struct 
{
	int		capacity;
	int		size;

	int		*buf;
}Array;

typedef Array *	PArray;

PArray array_create(int capacity);
int		array_push_back(PArray arr, int value);
int		array_pop_back(PArray arr);

void	array_free(PArray arr);

void	array_show(PArray arr);

#endif
