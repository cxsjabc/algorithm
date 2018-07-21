#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define INPUT_N(n)		scanf("%d", &(n))

int get_length(int n)
{
	int r = 0;

	if(n == 0)
		return 1;
	while(n) {
		++r;
		n /= 10;
	}
	return r;
}

void show_digits(int n, int no, int len)
{
	if(n == no && n == 0) {
		printf("0\n");
		return;
	}
	if(n == 0) {
		return;
	}
	show_digits(n / 10, no, len - 1);
	printf("%d%s", n % 10, get_length(no) == len ? "" : " ");
}

void show_reverse(int n)
{
	if(n == 0) {
		printf("\n");
		return;
	}
	printf("%d", n % 10);
	show_reverse(n / 10);
}

int main()
{
	int n;

	INPUT_N(n);
	printf("%d\n", get_length(n));
	show_digits(n, n, get_length(n));
	printf("\n");
	if(n)
		show_reverse(n);
	else
		printf("0");
	return 0;
}
