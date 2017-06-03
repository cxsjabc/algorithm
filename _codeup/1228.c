#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n = 15;
	int i, j;
	int a[15];
	int v;
	int index = -1;

	for(i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &v);

	i = 0, j = n - 1;
	while(1) {
		int k;
		if(i > j)
			break;
		k = (i + j) / 2;
		if(a[k] == v) {
			index = k;
			break;
		} else if(a[k] > v) {
			j = k - 1;
		} else
			i = k + 1;
	}
	
	if(index == -1)
		printf("NO\n");
	else
		printf("%d\n", index);
	
	return 0;
}
