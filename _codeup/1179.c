#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int process_ch(int ch)
{
	if(ch >= 'A' && ch <= 'Z')
		return ch + 32;
	else
		return ch;	
}

int main()
{
	int ch;

	ch = getchar();

	printf("%c\n", process_ch(ch));

	return 0;
}
