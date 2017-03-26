#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int i;
	int newer = 0;
	char *s = "";
	int s1[3], s2[3];

	for(i = 0; i < 3; ++i)
		scanf("%d", &s1[i]);
	for(i = 0; i < 3; ++i)
		scanf("%d", &s2[i]);

	for(i = 0; i < 3; ++i) {
		if(s1[i] < s2[i]) {
			newer = 2;
			break;
		} else if(s1[i] > s2[i]) {
			newer = 1;
			break;
		}	
	}

	if(newer == 0)
		s = "Same";
	else if(newer == 1)
		s = "First";
	else if(newer == 2)
		s = "Second";
	printf("%s\n", s);
	return 0;
}
