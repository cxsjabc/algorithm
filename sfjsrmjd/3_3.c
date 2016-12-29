#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRACE  0

int main()
{
	int arr_small[20][20] = {0};
	int n;
	int **p_arr;
	int a, b;
	int index = 1;

	scanf("%d", &n);
	if(n < 0)  // will crash when running 
		p_arr = (int **)arr_small;
	else {
		int i, j;
		p_arr = (int **)malloc(sizeof(int *) * n);
		if(!p_arr) {
			printf("No mem...\n");
			return -1;
		}
		memset(p_arr, 0, sizeof(int *) * n);
		for(i = 0; i < n; ++i) {
			p_arr[i] = (int *)malloc(sizeof(int) * n);
			if(!p_arr[i]) {
				printf("No mem...\n");
				for(j = 0; j < i; ++j) {
					if(p_arr[j])
						free(p_arr[j]);
				}	
				free(p_arr);
				return -2;
			}
		}
	}
	
	a = 0;
	b = n - 1;

	while(index <= n * n) {
		while(a < n && !p_arr[a][b]) {
			p_arr[a++][b] = index++;
			#if TRACE
			printf("a:%d,b:%d, value:%d\n", a - 1, b, index - 1);
			#endif
		}
		--a, --b;
		while(b >= 0 && !p_arr[a][b]) {
			p_arr[a][b--] = index++;
			#if TRACE
			printf("a:%d,b:%d, value:%d\n", a, b + 1, index - 1);
			#endif
		}
		++b, --a;	
		while(a >= 0 && !p_arr[a][b]) {
			p_arr[a--][b] = index++;
			#if TRACE
			printf("a:%d,b:%d, value:%d\n", a + 1, b, index - 1);
			#endif
		}
		++a, ++b;
		while(b < n && !p_arr[a][b]) {
			p_arr[a][b++] = index++;
			#if TRACE	
			printf("a:%d,b:%d, value:%d\n", a, b - 1, index - 1);
			#endif
		}
		--b, ++a;
	}

	for(a = 0; a < n; ++a) {
		for(b = 0; b < n; ++b)	{
			printf("%3d ", p_arr[a][b]);
		}
		printf("\n");
	}	
	printf("\n");

	if(n > 20) {
		int i, j;
		for(i = 0; i < n; ++i)
			free(p_arr[i]);
		free(p_arr);
	}
    return 0;
}
