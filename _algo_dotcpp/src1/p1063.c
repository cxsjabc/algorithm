#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_char_cnt()
{
	int c;
	int ca, cb, cd, co;

	ca = cb = cd = co = 0;

	while((c = getchar()) != '\n') {
		if(isalpha(c))
			++ca;
		else if(c == ' ')
			++cb;
		else if(isdigit(c))
			++cd;
		else
			++co;
	}
	printf("%d\n%d\n%d\n%d\n", ca, cb, cd, co);
}

int main()
{
	show_char_cnt();
	return 0;
}
