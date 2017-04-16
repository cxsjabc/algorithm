#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int v1[3], v2[3];
		int i;
		int new = 0;
		char *p;

		for(i = 0; i < 3; ++i)
			scanf("%d", &v1[i]);		
		for(i = 0; i < 3; ++i)
			scanf("%d", &v2[i]);		

		for(i = 0; i < 3; ++i) {
			if(v1[i] > v2[i]) {
				new = 1;
				break;
			}
			else if(v1[i] < v2[i]) {
				new = -1;
				break;
			}
		}

		if(new == 1)
			p = "First";
		else if(new == -1)
			p = "Second";
		else
			p = "Same";	

		printf("%s", p);
		if(t != 0)
			printf("\n");	
	}

	return 0;
}
