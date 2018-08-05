#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_3n_1_results(int i, int j)
{
	int m;
	int steps, max_steps = 0;
	int t;
	int flag = 0;

	if (i > j)
		t = i, i = j, j = t, flag = 1;
	for(m = i; m <= j; ++m) {
		int temp = m;
		steps = 0;
		while(temp != 1) {
			++steps;
			if(temp % 2 == 0) {
				temp /= 2;
			}
			else {
				temp = 3 * temp + 1;
			}
		}
		++steps;
		if(steps > max_steps)
			max_steps = steps;
	}
	if(flag)
		printf("%d %d %d\n", j, i, max_steps);
	else
		printf("%d %d %d\n", i, j, max_steps);
}

int main()
{
	int i, j;

	while(INPUT2(i, j) == 2) {
		show_3n_1_results(i, j);
	}
	return 0;
}
