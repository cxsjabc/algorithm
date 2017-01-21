#include "common.h"

int main()
{
	int cnt = 0;
	int n;
	
	// input numbers which is not 0	
	while(scanf("%d", &n) == 1 && n != 0) {
		++cnt;
	}

	printf("count: %d\n", cnt);
    return 0;
}
