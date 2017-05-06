#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int main()
{
	char s1[128], s2[128], s3[128];
	char *max_s;
	int max;

	gets(s1);
	gets(s2);
	gets(s3);

	max_s = s1;
	max = 1;
	if(strcmp(s2, s1) > 0)
		max_s = s2, max = 2;
	if(strcmp(s3, max_s) > 0)
		max_s = s3, max = 3;

	printf("%s\n", max_s);
	return 0;
}
