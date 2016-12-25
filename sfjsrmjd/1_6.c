#include <stdio.h>

int main()
{
	int n;
	int i, j;
	scanf("%d", &n);
	
	i = n % 10;
	j = n / 10 % 10;
	printf("%c%c%d", (i == 0) ? ' ' : i + '0', (j == 0) ? ' ' : j + '0', n / 100);
    return 0;
}
