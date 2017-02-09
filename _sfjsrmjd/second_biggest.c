#include "common.h"

int main()
{
	int n;
	int b, sb;
	int cnt;
	int first = 1;
	scanf("%d", &cnt);

	while(cnt-- > 0) {
		scanf("%d", &n);
		if(first++ == 1)
			b = sb = n;
		else {
			if(n > b) 
				sb = b, b = n; 
			else if(n > sb)
				sb = n;
		}
	}
	printf("sb:%d\n", sb);
    return 0;
}
