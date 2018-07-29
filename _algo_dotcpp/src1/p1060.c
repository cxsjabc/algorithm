#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_results()
{
	int i;
	for(i = 10; i <= 1000; ++i) {
		if(i % 2 == 0 && i % 3 == 0 && i % 7 == 0)
			printf("%d\n", i);
	}
}

int main()
{
	show_results();
	return 0;
}
