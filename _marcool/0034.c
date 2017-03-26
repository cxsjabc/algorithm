#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

long add_sum()
{
	long ret = 0;
	long n;
	char ch;

	while(scanf("%ld", &n) == 1) {
		ret += n;
		ch = getchar();
		if(ch == '\n')
			break;
	}
	return ret;
}

int main()
{
	long ret;
	ret = add_sum();
	printf("%ld\n", ret);
	return 0;
}
