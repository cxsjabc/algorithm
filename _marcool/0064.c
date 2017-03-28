#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h> 

char *s[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int main()
{
	char str[1025];
	int i, j;

	scanf("%s", str);
	
	for(i = 0; i < strlen(str); ++i) {
		for(j = 0; j < sizeof(s) / sizeof(s[0]); ++j) {
			char *p = strchr(s[j], str[i]);
			if(p) {
				 printf("%c%ld", str[i], p - s[j] + 1);
			}
		}			
	} 
	printf("\n");

	return 0;
}
