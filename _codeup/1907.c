#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int	get_eat_methods(int n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 2;
	return get_eat_methods(n - 1) + get_eat_methods(n - 2);
}

int main()
{
	int n;

	while(scanf("%d", &n) != EOF) {
		int methods;
		methods = get_eat_methods(n);
		printf("%d\n", methods);
	}
	return 0;
}
