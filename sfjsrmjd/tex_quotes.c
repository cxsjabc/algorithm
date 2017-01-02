#include <stdio.h>
#include <string.h>

char str[128] = "\"To be or not to be,\" quoth the Bard, \"that\nis the question\".";

int main()
{
	char temp[128];
	int first_quote = 1;
	char *s = temp;
	//scanf("%s", temp);
	strcpy(s, str);	

	while(*s) {
		if(*s == '\"') {
			if(first_quote) {
				printf("``");
				first_quote = 0;
			}
			else {
				printf("\"");
				first_quote = 1;
			}
		} else {
			printf("%c", *s);
		}
		++s;
	}
    return 0;
}
