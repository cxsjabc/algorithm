#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <ctype.h> 

void print_char_count()
{
	char c;
	int ca, cd, cb, co;

	ca = cd = cb = co = 0;
	while((c = getchar()) != '\n') {
		if(isalpha(c))
			++ca;
		else if(isdigit(c))
			++cd;
		else if(c == ' ')
			++cb;
		else
			++co;
	}
	printf("%d %d %d %d \n", ca, cd, cb, co);
}

int main()
{
	print_char_count();
	return 0;
}
