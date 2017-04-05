#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int i;
	int v;

	scanf("%d", &n);
	for(i = 0; i < n; ++i) {
		scanf("%d", &v);
		printf("%c", (char)v);
	}
	return 0;
}
