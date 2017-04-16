#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char s[128];	// just assume max char arr size is: 128
	int first = 1;

	while(gets(s)) {
		int i = 0;
		double sum = 0;
		int cnt = 0;
		char *p = s;
		int err = 0;
		
		if(!first)
			printf("\n");
		else
			first = 0;

		while(*p) {
			if(*p == 'A')
				sum += 4, ++cnt;
			else if(*p == 'B')
				sum += 3, ++cnt;
			else if(*p == 'C')
				sum += 2, ++cnt;
			else if(*p == 'D')
				sum += 1, ++cnt;
			else if(*p == 'F')
				sum += 0, ++cnt;
			else if(*p == ' ') {
				++p;
				continue;
			}
			else {
				err = 1;
				break;
			}
			++p;
		}
		if(!err)
			printf("%.2f", sum / cnt);
		else
			printf("Unknown");
	}

	return 0;
}
