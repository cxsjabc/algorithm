#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int get_digits_cnt(int n)
{
	int c = 0;
	
	if(n == 0)
		return 1;

	while(n) {
		n /= 10;
		++c;
	}
	return c;
}

void print_each_digit(int n)
{
	int t = 0;
	int a[8];
	int i;

	if(n == 0) {
		printf("0 ");
		return;
	}
	
	while(n) {
		a[t++] = n % 10;
		n /= 10;	
	}

	for(i = 0; i < t / 2; ++i) {
		int temp = a[i];
		a[i] = a[t - i - 1];
		a[t - i - 1] = temp;
	}	

	for(i = 0; i < t; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

void print_each_digit_reverse(int n)
{
	int t = 0;
	int a[8];
	int i;

	if(n == 0) {
		printf("0 ");
		return;
	}
	
	while(n) {
		a[t++] = n % 10;
		n /= 10;	
	}

	for(i = 0; i < t; ++i)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%d\n", get_digits_cnt(n));
	print_each_digit(n);
	print_each_digit_reverse(n);

	return 0;
}
