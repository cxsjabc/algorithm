#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

#define MAX 	10001
int t[MAX];

int main()
{
	int L, M;
	int s, e;
	int i;
	int r = 0;

	INPUT2(L, M);
	
	for(i = 0; i <= L; ++i)
		t[i] = 1;
	while(M--) {
		INPUT2(s, e);
		for(i = s; i <= e; ++i)
			t[i] = 0;	
	}

	for(i = 0; i <= L; ++i)
		if(t[i] == 1)
			++r;	

	printf("%d\n", r);
	return 0;
}
