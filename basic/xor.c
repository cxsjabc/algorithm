#include <stdio.h>

#define PN(n)	printf(#n " is %d\n", (n));

void swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;	
}
	

int main()
{
	int a = 2, b = 1;
	int c, d;
	FILE *fp, *fp1;
	int ret, ret1;
	//swap(&a, &b);
	
	//PN(a);
	//PN(b);

	fp = fopen("xor.in", "r");
	fp1 = fopen("xor.out", "r");	
	while(1)
	{
		ret = fscanf(fp, "%d %d", &a, &b);
		ret1 = fscanf(fp1, "%d %d", &c, &d);
		if(ret == 2)
		{
			swap(&a, &b);
			if(a == c && b == d)	
			{
				printf("Verify %d,%d to %d,%d Ok!\n", b, a, c, d);
			}
			else
			{
				printf("Verify %d,%d to %d,%d Failed!\n", b, a, c, d);
			}
		}
		else
			break;
	}
	return 0;
}
