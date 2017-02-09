#include <stdio.h>

#define FILE_NAME  decimal

#define DATA_IN   "decimal.in"
#define DATA_OUT  "decimal.out"

int main()
{
	int a, b, c;
	freopen(DATA_IN, "r", stdin);
	freopen(DATA_OUT, "w", stdout);

	while(scanf("%d%d%d", &a, &b, &c) == 3 && !(a == 0 && b == 0 && c == 0)) {
		double result = 0;
		char str[128] = {0};
		int i = 0;
		int integer = a / b;
		int integer1 = integer;
		int remain = a - b * integer;
		if(remain == 0) {
			while(i < c)
				str[i++] = '0';
			str[i] = '\0'; 
		} else {
			while(remain > 0 && i < c) {
				integer = 10 * remain / b;
				remain = 10 * remain - b * integer;
				str[i++] = integer + '0';
			}	
			while(i < c) 
				str[i++] = '0';
			str[i] = '\0';
		}
		printf("%d.%s\n", integer1, str);
	}
    return 0;
}
