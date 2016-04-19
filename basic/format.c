#include <stdio.h>

#include "common.h"

// CO
#define real 	float

#if 0 // CE
int a;
void a()
{
}
#endif

#if 0
int main()
{
#if 0
// CO
#define	int		char	
#endif

	float f = 7. / 3;
#if 0	
	printf("%f\n", f);	
	printf("%.2f\n", f);	
	printf("%6.2f\n", f);	
#endif

#if 0
{
	int ab = 0;
	a/**/b = 1;
}		
#endif

#if 1
{
	real f1 = 1.2;
	int n = 1;
	printf("sizeof(n):%d\n", sizeof(n));
	//printf("%f\n", f1);
}
#endif

	return 0;
}
#else
//main() // CW
//int main; // no CE, but int main() will

int main()
{
	//printf("hello, maomao!\n");
	//int for; 		// CE
	//int printf; 	// CE
	//int while;	// CE
	
	{
		float f = 1. / 3;
		int a = -1;
		int n;
		//printf("%3.1f,%.f,%.-1f\n", f, f, f);		
		printf("%E,%e,%F,%G,%g\n", f, f, f, f, f);
		printf("decimal:%d,%u\n", a, a);
		printf("oct:%o,%o\n", a, a);  // unsigned value
		printf("%d,%i,%n\n", a, a, &n);
		printf("|% +-6d|, |%5.2d|\n", n, n);
		printf("|%Fd|\n", a);
	}

	return 0;
}

#endif

