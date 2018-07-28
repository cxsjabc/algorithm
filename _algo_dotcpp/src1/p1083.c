#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void translate_ascii()
{
	int n;

	while(scanf("%d", &n) == 1) {
		printf("%c", n);
	}
}

int main()
{
	translate_ascii();
	return 0;
}
