#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

long long fact(int n)
{
	long long ret = 1;

	while(n > 1)
		ret *= n, --n;
	
	return ret;
}

double mypow(double x, int n)
{
	double ret = 1;
	while(n--) {
		ret *= x;
	}
	return ret;
}

double get_result(double x, int n)
{
	int flag = 1;
	double result = 0;
	int i = 1;

	while(i <= n) {
		result += flag * ((double)mypow(x, i) / fact(i));
		++i;
		flag = -flag;
	}
	return result;

}

int main()
{
	int n;
	double x;

	scanf("%lf", &x);
	scanf("%d", &n);

	printf("%.4f\n", get_result(x, n));

	return 0;
}
