#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

int main()
{
	int m, n;
	char arr[16] = {'\0'};
	int cnt = 0;
	char op;	

	while(scanf("%d%c%d=%s", &m, &op, &n, arr) == 4) {
		if(arr[0] == '?') {
			memset(arr, 0, 16);
			continue;
		}
		if(op == '+' && m + n == atoi(arr))
			++cnt;
		else if(op == '-' && m - n == atoi(arr))
			++cnt;	
	}

	printf("%d\n", cnt);
	return 0;
}
