#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void print(char c, int times)
{
	int i = 0;

	while(i < times) {
		putchar(c);
		++i;
	}
}

int main()
{
	int n;
	int i;
	int star_cnt, jing_cnt;

	scanf("%d", &n);
	jing_cnt = 1;

	// head
	print('*', n);
	printf("\n");

	while(jing_cnt < n) {
		star_cnt = (n - jing_cnt) / 2;

		print('*', star_cnt);
		print('#', jing_cnt);
		print('*', star_cnt);

		jing_cnt += 2;
		printf("\n");
	}

	jing_cnt -= 4;
	while(jing_cnt > 0) {
		star_cnt = (n - jing_cnt) / 2;

		print('*', star_cnt);
		print('#', jing_cnt);
		print('*', star_cnt);

		jing_cnt -= 2;
		printf("\n");
	}

	// tail
	print('*', n);
	printf("\n");

	return 0;
}
