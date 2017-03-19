#include <stdio.h>

#define PN(n)	printf(#n "is %d\n", (n));

void printDigit(int n)
{
	printf("%d", n);
}

void print(int n)
{
	if(n >= 10)
		print(n / 10);
	printDigit(n % 10);
}

int main()
{
	print(76234);
	return 0;
}
