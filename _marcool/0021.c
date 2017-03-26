#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n, m;
	int dis;
	scanf("%d%d", &n, &m);
	dis = n - m;
	if(dis < 0)
		dis = -dis;
	printf("%d\n", dis);
	return 0;
}
