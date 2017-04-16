#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int t;

	scanf("%d", &t);
	while(t--) {
		int n;
		int first = 1, f = 0;

		scanf("%d", &n);

		while(n != 1) {
			if(n % 2 == 1) {
				if(!first)
					printf(" ");
				else
					first = 0;
				f = 1;
				printf("%d", n);
			}

			if(n % 2 == 0)
				n /= 2;
			else
				n = 3 * n + 1;
		}

		if(f == 0)
			printf("No number can be output !\n");
		else
			printf("\n");
	}


	return 0;
}
