#include "common_local.h"

void print_digit(int n)
{
	if(n >= 10)
		print_digit(n / 10);
	printf("%d", n % 10);
}

int main()
{
	int n;

	while(scanf("%d", &n) == 1) {
		print_digit(n);
	}
    return 0;
}
