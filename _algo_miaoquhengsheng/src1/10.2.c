#include "common_local.h"

void print_max2()
{
	int n = 10;
	int max, max2;
	int first = 1;
	int v;

	while(n > 0) {
		scanf("%d", &v);
		if(first) {
			max = max2 = v;
			first = 0;
		}
		else {
			if(v > max) {
				int temp = max;
				max = v;
				max2 = temp;
			}
			else if(v > max2)
				max2 = v;
		}
		--n;
	}
	printf("max:%d, max2:%d\n", max, max2);	
}

int main()
{
	print_max2();	
    return 0;
}
