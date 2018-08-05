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
	char s[128], *p;
	int len;
	int i;

	p = fgets(s, 128, stdin);
	if(!p)
		return -1;
	len = strlen(p);

	if(p[len - 1] == '\n')
		--len;
	for(i = len - 1; i >= 0; --i)
		printf("%c", s[i]);
	
	return 0;
}
