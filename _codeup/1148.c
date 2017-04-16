#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_exact_div_by_3_5(int n)
{
	return (n % 3 == 0 && n % 5 == 0);
}

int main()
{
	int n;
	
	scanf("%d", &n);
	printf("%s\n", is_exact_div_by_3_5(n) ? "can" : "cannot");
	return 0;
}
