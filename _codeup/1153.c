#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

int	get_oct(int n, char *s)
{
	int i = 0;
	int flag = 1;
	int len;
	char *sb = s;

	if(n < 0)
		flag = -1, n = -n;

	if(n == 0) {	
		*s = '0';
		++s;
		*s = '\0';
		return 1;
	}

	if(flag == -1)
		*s++ = '-';

	while(n) {
		int temp;
		temp = n % 8;
		*s = temp + '0';

		n /= 8;
		++s;
	}
	*s = '\0';

	len = strlen(sb);
	if(flag == -1)
		--len, i = 0, sb++;
	for(; i < len / 2; ++i) {
		char temp = sb[i];
		sb[i] = sb[len - i - 1];
		sb[len - i - 1] = temp;
	}

	return 1;	
}

int	get_hex(int n, char *s)
{
	int i = 0;
	int flag = 1;
	int len;
	char *sb = s;

	if(n < 0)
		flag = -1, n = -n;

	if(n == 0) {	
		*s = '0';
		++s;
		*s = '\0';
		return 1;
	}

	if(flag == -1)
		*s++ = '-';

	while(n) {
		int temp;
		temp = n % 16;
		if(temp >= 0 && temp <= 9)
			*s = temp + '0';
		else
			*s = temp - 10 + 'a';
		n /= 16;
		++s;
	}
	*s = '\0';

	len = strlen(sb);
	if(flag == -1)
		--len, i = 0, ++sb;
	for(i = 0; i < len / 2; ++i) {
		char temp = sb[i];
		sb[i] = sb[len - i - 1];
		sb[len - i - 1] = temp;
	}
	return 1;	
}

int main()
{
	int t = 8;

	while(t--) {
		int n;
		char s[128], s1[128];

		scanf("%d", &n);
		get_oct(n, s);		
		get_hex(n, s1);		
		printf("%s %s\n", s, s1);
	}

	return 0;
}
