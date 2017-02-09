#include "common.h"

int main()
{
	int n;
	int i = 0;
	int m = 1;
	scanf("%d", &n);

	while(m < n) {
		++i;
		m *= 2;
	}
	--i;
	printf("%d\n", i);

    return 0;
}
