#include <stdio.h>

int main()
{
	int n, m;
	int chicks, rabbits; 
	scanf("%d%d", &n, &m);

	chicks = 2 * n - m / 2;
	rabbits = (m - 2 * n) / 2;
	if( m % 2 == 1 || chicks <= 0 || rabbits <= 0)
		printf("No answer\n");
	else
		printf("%d %d\n", 2 * n - m / 2, (m - 2 * n) / 2);
	
    return 0;
}
