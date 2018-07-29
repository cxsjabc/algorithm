#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int is_qingheshu(int i, int j)
{
	int p = 1;
	int si = 0, sj = 0;

	while(p < i) {
		if(i % p == 0)
			si += p;
		++p;
	}

	p = 1;
	while(p < i) {
		if(j % p == 0)
			sj += p;
		++p;
	}
	if(si == j && sj == i)
		return 1;
	return 0;
}

int main()
{
	int m;
	int i, j;

	INPUT(m);
	while(m--) {
		INPUT2(i, j);
		printf("%s\n", is_qingheshu(i, j) ? "YES" : "NO");
	}
	return 0;
}
