#define _LOG_LEVEL	LOG_LEVEL_INFO

#include "common_local.h"
#include "array.h"

// start_value: 4, size: 5 , arr: 4 5 6 7 8 
void	init_basic_arr(int arr[], int size, int start_value)
{
	int i;
	for(i = 0; i < size; ++i)
		arr[i] = start_value + i;
}

// reset_value: 3, size: 5, arr: 3 3 3 3 3 
void	reset_basic_arr(int arr[], int size, int reset_value)
{
	int i;
	for(i = 0; i < size; ++i)
		arr[i] = reset_value;
}

// start_value: 4, size: 5, arr: 8 7 6 5 4 
void	init_reverse_basic_arr(int arr[], int size, int start_value)
{
	int i;
	for(i = size - 1; i >= 0; --i)
		arr[i] = start_value + (size - i - 1);
}


PArray array_create(int capacity)
{
	PArray arr = (PArray)malloc(sizeof(Array));
	int *buf;

	if(!arr)
		goto label_alloc_fail;

	buf = (int *)malloc(sizeof(int) * capacity);
	if(!buf)
		goto label_alloc_fail;	
	arr->capacity = capacity;
	arr->size = 0;
	arr->buf = buf;
	return arr;

label_alloc_fail:
	if(buf)
		free(buf);
	if(arr)
		free(arr);
	return NULL;

}

int		array_push_back(PArray arr, int value)
{
	if(arr->size < arr->capacity) {
		arr->buf[arr->size] = value;
		++(arr->size);
		LOG_V("Add value:%d", value);
		return 1;
	} else {
		// alloc a bigger buffer
		int *new_buf;
		new_buf = (int *)malloc(2 * arr->capacity * sizeof(int));
		if(!new_buf)
			goto label_alloc_fail;
		memcpy(new_buf, arr->buf, sizeof(int) * arr->capacity);
		free(arr->buf);

		arr->buf = new_buf;
		arr->buf[arr->size] = value;
		arr->capacity = 2 * arr->capacity;
		(arr->size)++;

		LOG_V("Add value:%d,real value:%d, size:%d", value, arr->buf[arr->size -1], arr->size);
		return 1;

	label_alloc_fail:
		return 0;
	}
}

int		array_pop_back(PArray arr)
{
	if(arr->size == 0)
		return 0;

	(arr->size)--;
	return 1;
}

void	array_free(PArray arr)
{
	if(arr->buf)
		free(arr->buf);
	if(arr)
		free(arr);
}

void	array_show(PArray arr)
{
	int i;

	for(i = 0; i < arr->size; ++i)
		printf("%d ", arr->buf[i]);

	printf("\n");
}
