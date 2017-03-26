#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

char *fix_scan_err(char *s)
{
	char *s1 = s;
	while(*s) {
		switch(*s) {
			case 'O':
				*s = '0';
				break;
			case 'l':
				*s = '1';
				break;
			case 'Z':
				*s = '2';
				break;
			case 'S':
				*s = '5';
				break;
			case 'b':
				*s = '6';
				break;
			case 'B':
				*s = '8';
				break;
			case 'q':
				*s = '9';
				break;
			default:
				break;
		}
		++s;
	}
	return s1;	
}

int main()
{
	char s[128];
	gets(s);
	printf("%s\n", fix_scan_err(s));
	return 0;
}
