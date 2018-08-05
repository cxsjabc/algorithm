#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

void show_results(int n)
{
	char s[1000];
	
	while(n--) {
		char *p;

		p = fgets(s, 1000, stdin);
		if(!p)
			return;
		printf("%s\n", p);
	}
	while(scanf("%s", s) == 1) {
		printf("%s\n\n", s);
	}
}

int main()
{
	int n;
	int c;

	INPUT(n);
	while((c = getchar()) != '\n')
		;
	show_results(n);
	return 0;
}
