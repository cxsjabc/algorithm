#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int n;
	int a, b, c;
	int res = 0;

	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);

	if(a == 0 || b == 0 || c == 0)
		res = 1;
	else {
		if(n < c)
			res = 1;
	}

	printf("%s\n", res == 0 ? "Oh,my GOD!" : "Yeah!");
	return 0;
}
