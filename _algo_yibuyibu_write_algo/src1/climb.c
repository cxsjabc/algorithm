#include "common_local.h"

int	climb(int n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;
	return climb(n - 1) + climb(n - 2);
}

int climb1(int n)
{
	int *p;
	int i;

	p = (int *)malloc(sizeof(int) * n);
	assert(p);
	p[0] = 1;
	p[1] = 2;
	for(i = 2; i < n; ++i)
		p[i] = p[i - 1] + p[i - 2];
	return p[n - 1];
}

void show_climb(int n)
{
	if(n == 1) {
		printf("1");
	} else if(n == 2) {
		
	}
}

int main()
{
	int n;

	while(scanf("%d", &n) == 1) {
		if(n > 0)
			PD(climb1(n));
			PD(climb(n) == climb1(n));
	}
    return 0;
}
