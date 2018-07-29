#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void do_things()
{
	int n;
	int i = 20;
	int total = 0, pos_cnt = 0, neg_cnt = 0;

	while(i--) {
		INPUT(n);
		if(n < 0)
			++neg_cnt;
		else if(n > 0) {
			++pos_cnt;
			total += n;
		}
	}
	printf("%d\n", neg_cnt);
	printf("%.2f\n", (double)total / pos_cnt);
}

int main()
{
	do_things();
	return 0;
}
