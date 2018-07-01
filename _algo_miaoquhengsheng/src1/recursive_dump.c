#include "common_local.h"

void printf_level(int level)
{
	while(level-- > 0) {
		printf("\t");
	}
}

int	f(int n, int level)
{
	int r;
	
	++level;
	printf_level(level);
	printf("call %d\n", n);

	if(n == 1)
		return 1;
	r = n * f(n - 1, level);

	--level;
	printf_level(level);
	printf("return %d\n", r);
	return r;
}

int main()
{
	int r;

	r = f(3, 0);
	PD(r);

    return 0;
}
