#include <stdio.h>

int main()
{
	int n;
	int i, j;
	int m;
	scanf("%d", &n);
	
	i = n % 10;
	j = n / 10 % 10;
	m = 100 * i + 10 * j + n / 100;
	printf("%03d\n", m);

    return 0;
}
