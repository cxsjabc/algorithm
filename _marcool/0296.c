#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int parse_str_to_int(char **ps, int *value)
{
	int v = 0;
	char *s = *ps;
	
	while(*s == ' ') ++s;

	while(*s) {
		if(*s == ' ') { break; }
		if(*s >= '0' && *s <= '9') {
			v = v * 10 + *s - '0';
			++s;
		}
	}
	if(value)
		*value = v;
	//printf("get value:%d\n", v);
	*ps = s;
	return v != 0;
}


int main()
{
	int leiting = 0, maci = 0;
	int temp;
	char s[1024];
	char *ps = s;

	gets(s);

	while(parse_str_to_int(&ps, &temp)) {
		leiting += temp;	
		if(*ps == '\0')
			break;
	}

	gets(s);
	ps = s;
	while(parse_str_to_int(&ps, &temp)) {
		maci += temp;	
		if(*ps == '\0')
			break;
	}

	printf("%s\n", leiting > maci ? "Good Job!Thunder." : "What a pity,Thunder!");

	return 0;
}
