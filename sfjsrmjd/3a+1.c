#include <stdio.h>

int main()
{
	long long n;   // avoid overflow for input value (<= 10^9)
	int j = 0;
	scanf("%lld", &n);
	
	while(n != 1) {
		if(n % 2 == 1)
			n = 3 * n + 1;
		else
			n /= 2;
		++j;
	}		
    printf("%d\n", j);
    return 0;
}
