#include "common_local.h"

int  is_ugly(int n)
{
	if(n == 1)
		return 1;
	while(n % 2 == 0)
		n /= 2;
	while(n % 3 == 0)
		n /= 3;
	while(n % 5 == 0)
		n /= 5;

	return n == 1;
}

int main()
{
	int i = 0;
	int cnt, n = 1;
	scanf("%d", &cnt);		

	if(cnt == 1) {
		printf("result:%d\n", 1);
		return 0;
	}

	while(i < cnt - 1) {
		++n;
		if(is_ugly(n))
			++i;
	}	

	printf("The %d ugly number is: %d\n", cnt, n);
    return 0;
}
