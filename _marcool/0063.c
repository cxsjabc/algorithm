#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	long m, n;
	char c;
	long s;

	// bugs: maybe blanks..	
	scanf("%ld%c%ld", &m, &c, &n);
	if(c == '+')
		s = m + n;
	else if(c == '-')
		s = m - n;
	else if(c == 'X' || c == 'x' || c == '*')
		s = m * n;

	printf("%ld\n", s);
	return 0;
}
