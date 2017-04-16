#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int n;
		int a[10];
		int i;
		int min, smin;

		scanf("%d", &n);

		scanf("%d", &a[0]);
		min = smin = a[0];
		for(i = 1; i < n; ++i) {
			scanf("%d", &a[i]);
			if(a[i] < min)
				smin = min, min = a[i];
			else if(a[i] > min && a[i] < smin)
				smin = a[i];
			else if(a[i] > smin && smin == min)
				smin = a[i];
		}
		
		if(min != smin)	
			printf("%d\n", smin);
		else
			printf("NO\n");
	}
	return 0;
}
