#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int get_symmetry(int n)
{
	int t = n * n;
	char a[32];
	int i = 0;
	int j;

	while(t) {
		int temp = t % 10;
		a[i++] = temp;
		t /= 10;
	}
	for(j = 0; j <= i / 2; ++j)
		if(a[j] != a[i - 1 - j])
			return 0;
	return 1;
}

int main()
{
	int i, n = 256;

	for(i = 0; i <= n; ++i)
		if(get_symmetry(i))
			printf("%d\n", i);
	return 0;
}
