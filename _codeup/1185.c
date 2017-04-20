#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

char get_grade(int s)
{
	char g;	
	
	if(s >= 90)
		g = 'A';
	else if(s >= 80)
		g = 'B';
	else if(s >= 70)
		g = 'C';
	else if(s >= 60)
		g = 'D';
	else
		g = 'E';
	return g;
}

int main()
{
	int s;

	scanf("%d", &s);
	printf("%c\n", get_grade(s));
	return 0;
}
