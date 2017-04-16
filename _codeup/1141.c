#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char n[1024];
	int s;
	int t = 50;

	while(t--) {
		scanf("%s%d", n, &s);
		if(s >= 80)
			printf("%s %d\n", n, s);
	}
	
	return 0;
}
