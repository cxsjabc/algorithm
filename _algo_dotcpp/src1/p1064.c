#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_results()
{
	double r = 0;
	int i = 1;
	double temp = 1;

	while(i <= 30) {
		temp *= i;
		r += temp;
		++i;
	}
	printf("%.2e\n", r);
}

int main()
{
	show_results();
	return 0;
}
