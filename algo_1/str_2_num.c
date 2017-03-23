#include "common_local.h"

#if 0
#ifdef atoi_xi
#warning "atoi_xi is defined!"
#endif
#endif

int	atoi_xi(const char *s, int *value)
{
	int ret = 1;
	int flag = 1;
	int n = 0;
	
	if(value == NULL)
		return 0;

	while(*s == ' ') ++s;
	if(*s == '+')
		flag = 1, ++s;
	else if(*s == '-')
		flag = -1, ++s;

	while(*s >= '0' && *s <= '9') {
		n = 10 * n + (*s - '0');
		++s;
	}		
	if(*s && !(*s >= '0' && *s <= '9'))
		return 0;

	// Todo: overflow ...

	*value = n * flag;
	return ret;
}

int main()
{
	char s[128];
	while(scanf("%s", s) > 0) {
		int ret, value;
		ret = atoi_xi(s, &value);
		if(ret == 1)
			printf("value:%d\n", value);
		else
			printf("Format wrong!\n");
	}
    return 0;
}
