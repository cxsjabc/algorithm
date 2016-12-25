#include <stdio.h>

int main()
{
	int m, n;
	int temp;
	scanf("%d%d", &m, &n);

	temp = m;
	m = n;
	n = temp;
	
	printf("%d %d\n", m, n);

    return 0;
}
