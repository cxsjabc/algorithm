#include "common_local.h"

void dfs(int index, int n, int *arr, int *book)
{
	int i;

	if(n < 1)
		return;	

	if(index == n) {
		print_arr(arr, n);
		return;
	}

	for(i = 0; i < n; ++i) {
		if(book[i] == 0) {
			arr[index] = i + 1;	
			book[i] = 1;
			dfs(index + 1, n, arr, book);
			book[i] = 0;
		}
	}
}

int main()
{
	int n;
	int temp[32], data[32], *book, *arr;

	while(INPUT(n) == 1) { 
		if(n > 32) {
			book = (int *)malloc(n * sizeof(int));
			if(!book)
				return -1;
			arr = (int *)malloc(n * sizeof(int));
			if(!arr) {
				free(book);
				return -1;
			}
		} else {
			book = temp;
			arr = data;
		}

		memset(book, 0, n * sizeof(int));
		memset(arr, 0, n * sizeof(int));

		dfs(0, n, arr, book);

		if(n > 32) {
			free(arr);
			free(book);
		}
	}
	
    return 0;
}
