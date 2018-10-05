#include "common_local.h"

int main()
{
	char s[128], p[128];
	size_t len, mid;
	int i;
	int next;
	int top;

	gets(s);
    printf("%s\n", s);
	len = strlen(s);	
	mid = len / 2 - 1;
	top = 0;
	for(i = 0; i <= mid; ++i)
		p[top++] = s[i];
	if(len % 2 == 0)
		next = mid + 1;
	else
		next = mid + 2;
	
	--top;	
	for(i = next; i < len; ++i) {
		if(s[i] != p[top])
			break;	
		--top;
	}
	
	if(i == len)
		printf("huiwen!\n");
	else
		printf("not huiwen!\n");

    return 0;
}
