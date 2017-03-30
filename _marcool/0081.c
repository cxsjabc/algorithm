#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int is_square(long n)
{
    long i;
    for(i = 1; n > 0; i += 2)   // square num is always: 1, 1 + 3, 1 + 3 + 5, ...
        n -= i;
    return !(n);
}

int main()
{
	int i, j;
	for(i = 1; i <= 9; ++i) {
		for(j = 0; j <= 9; ++j) {
			int s = 1100 * i + 11 * j;
			//if(s == (int)sqrt(s) * (int)sqrt(s)) 
			if(is_square(s))
			{
				printf("%d\n", s);
			}
		}
	}
	return 0;
}
