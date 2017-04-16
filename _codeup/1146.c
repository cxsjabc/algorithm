#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int a, b, c;
	int m1, m2, m3;

	scanf("%d%d%d", &a, &b, &c);
	
	if(a > b)
		m1 = b, m2 = a;
	else
		m1 = a, m2 = b;

	if(c >= m2)
		m3 = c;
	else if(c <= m1)
		m3 = m2, m2 = m1, m1 = c;
	else
		m3 = m2, m2 = c;

	printf("%d %d %d\n", m1, m2, m3);
	return 0;
}
