#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int i, num = 0;

	scanf("%d", &n);
	for(i = 1; i <= n; i++) {
		n -= i;
		++num;

		if(n == 0)
			break;
		if(n < 0) {
			n += i;
			--num;
			break;
		}
	}
	
	if(num % 2 == 0) {
		if (n == 0)
			printf("%d/%d", num, 1);
		else
			printf("%d/%d", num + 2 - n, n);
	} else {
		if (n == 0)
			printf("%d/%d", 1, num);
		else
			printf("%d/%d", n, num + 2 - n);
	}

	return 0;
}
