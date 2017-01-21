#include <stdio.h>

int gen_yuan(int n)
{
	int ret = n;
	while(n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main()
{
	int n;
	int i;
	int found = 0;
	scanf("%d", &n);
	
	for(i = 1; i <= 100000; ++i) {
		int yuan = gen_yuan(i);
		if(yuan == n) {
			found = 1;
			printf("%d\n", i);
			break;
		}
	}

	if(found == 0)
		printf("0\n");
    return 0;
}
