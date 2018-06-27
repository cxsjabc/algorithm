#include "common_local.h"

void	base_10_to_2(int n)
{
	int s[16];
	int i = 0;

	if(n == 0) {
		printf("0\n");
		return;
	}
	
	while(n) {
		s[i++] = n % 2;
		n /= 2;
	}

	--i;
	for(; i >= 0; --i) {
		printf("%d", s[i]);
	}
}

int main()
{
	int n;

	scanf("%d", &n);
	base_10_to_2(n);
    return 0;
}
