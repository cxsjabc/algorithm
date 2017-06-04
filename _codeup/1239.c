#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main()
{
	int a1[10], a2[10];
	int i;
	int g, e, l;

	for(i = 0; i < 10; ++i)
		scanf("%d", &a1[i]);
	for(i = 0; i < 10; ++i)
		scanf("%d", &a2[i]);
	
	g = e = l = 0;
	for(i = 0; i < 10; ++i) {
		if(a1[i] > a2[i])
			++g;
		else if(a1[i] < a2[i])
			++l;
		else
			++e;
	}

	printf("%d %d %d\n", g, e, l);
	if(g > l)
		printf("a>b\n");
	else if(g < l)
		printf("a<b\n");
	else
		printf("a=b\n");
	return 0;
}
