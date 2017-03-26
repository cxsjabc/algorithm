#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	int s1, s2, s3;
	int t1, t2, t3;
	int newer;
	char *s = "";

	scanf("%d%d%d", &s1, &s2, &s3);
	scanf("%d%d%d", &t1, &t2, &t3);

	if(s1 > t1)
		newer = 1;
	else {
		if(s1 == t1) {
			if(s2 > t2)
				newer = 1;
			else if(s2 == t2) {
				if(s3 > t3)
					newer = 1;
				else if(s3 == t3)
					newer = 0;
				else
					newer = 2;
			} else {
				newer = 2;
			}
		} else {
			newer = 2;
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
