#include "common_local.h"

void print_mul()
{
	int i, j;

	for(i = 1; i <= 9; ++i) {
		for(j = 1; j <= i; ++j) {
			printf("%d*%d=%-3d ", j, i, i * j);
		}
		printf("\n");
	}
}

int main()
{
	print_mul();
    return 0;
}
