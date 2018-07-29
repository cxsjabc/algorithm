#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int arr[10];

int main()
{
	int n = 10;
	int max_abs_index;
	int temp;
	int i = 0;

	while(i < n)
		INPUT(arr[i]), ++i;

	max_abs_index = 0;
	n = 1;
	while(n <= 9) {
		if(abs(arr[n]) < abs(arr[max_abs_index]))
			max_abs_index = n;
		++n;	
	}
	temp = arr[max_abs_index];
	arr[max_abs_index] = arr[9];
	arr[9] = temp;	

	n = 0;
	while(n <= 9) {
		printf("%d ", arr[n]);
		++n;
	}
	return 0;
}
