#include "common_local.h"

void	swap1(int *pa, int *pb)
{
	int a, b;

	a = *pa;
	b = *pb;

	a ^= b;
	b ^= a;
	a ^= b;

	*pa = a;
	*pb = b;
}

// bug: if pa == pb
void	swap2(int *pa, int *pb)
{
	*pa ^= *pb;
	*pb ^= *pa;
	*pa ^= *pb;
}

int main()
{
	int a = 1, b = 2;
	int *pa, *pb;

	scanf("%d%d", &a, &b);
	
	pa = &a;
	pb = &a;

	swap1(pa, pb);
    printf("%d\n", *pa);

	a = 6;
	swap2(pa, pb);
    printf("%d\n", *pa);
	
    //printf("%d %d\n", *pa, *pb);
    return 0;
}
