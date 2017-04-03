#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int v1[100], v2[100];
	int i;
	int n;
	int r = 0;
	char *s;
	
	scanf("%d", &n);
	for(i = 0; i < n; ++i)
		scanf("%d", &v1[i]);
	for(i = 0; i < n; ++i)
		scanf("%d", &v2[i]);
		
	for(i = 0; i < n; ++i) {
		if(v1[i] > v2[i]) {
			r = 1;
			break;
		}
		else if(v1[i] < v2[i]) {
			r = -1;
			break;
		}
	}

	if(r == 1)
		s = "first";
	else if(r == -1)
		s = "second";
	else if(r == 0)
		s = "same";
	printf("%s\n", s);
	return 0;
}
