#include "common_local.h"

void print_line(int n)
{
	while(n-- > 0) {
		printf("@");
	}
	printf("\n");
}

void print_triangle(int n)
{
	while(n >= 1) {
		print_line(n);
		--n;
	}
}

int main()
{
	print_triangle(5);
    return 0;
}
