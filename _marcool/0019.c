#include <stdio.h> 
#include <stdlib.h> 

#define 	N		100

static inline int int_compare(const void *v1, const void *v2)
{
	return *(int *)v2 - *(int *)v1;
}

int get_rank_backup(int arr[], int size, int score)
{
	int i = 1, prev = arr[0];
	int rank = 1;
	
	if(arr[0] == score)
		return 1;
	
	++rank;
	while(i < size) {
		if(arr[i] == prev) {
			++i;
			continue;
		}
		if(arr[i] == score)
			return rank;
		prev = arr[i];
		//printf("prev:%d, rank:%d, i:%d\n", prev, rank, i);
		++rank;
		++i;
	}
	return -1;
}

int get_rank(int arr[], int size, int score)
{
	int i = 1, prev = arr[0];
	int rank = 1;
	
	if(arr[0] == score)
		return 1;
	
	++rank;
	while(i < size) {
		if(arr[i] == score)
			return rank;
		++rank;
		++i;
	}
	return -1;
}

int main()
{
	int n, arr[N];
	int i;
	int score;
	int rank;

	scanf("%d", &n);
    for(i = 0; i < n; ++i)
    	scanf("%d", &arr[i]);
	scanf("%d", &score);
	
	qsort(arr, n, sizeof(int), int_compare);	
	rank = get_rank(arr, n, score);
	printf("%d\n", rank);	

	return 0;
}
