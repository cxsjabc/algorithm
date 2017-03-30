#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char a[2] = {'A'}, b[2] = {'B'};
	int s1 = 0, s2 = 0;
	char result;
	char temp[2];
	int s;
	
	while(scanf("%s%d", temp, &s) == 2) {
		if(temp[0] == 'A')
			s1 += s;
		else if(temp[0] == 'B')
			s2 += s;
	}
	
	if(s1 > s2)
		result = a[0];
	else if(s1 < s2)
		result = b[0];
	else
		result = 'X';

	printf("%c\n", result);
	return 0;
}
