#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

char arr[100000];

int get_time(int i, int u, int f, int d)
{
	int r = 0;

	if(arr[i] == 'u' || arr[i] == 'd')
		r += (u + d);
	else
		r += (f * 2);
	return r;
}

int	get_result(int m, int t, int u, int f, int d)
{
	int r = 0;
	int i = 0;
	
	while(i < t && r <= m) {
		r += get_time(i, u, f, d);
		if(r > m) {
			--i;
			break;
		} else
			++i;
	}

	return i + 1;	
}

int main()
{
	int m, t, u, f, d;
	int i;
	char s[8];

	scanf("%d%d%d%d%d", &m, &t, &u, &f, &d);
	i = 0;
	while(i < t) {
		scanf("%s", s);
		arr[i] = s[0];
		++i;
	}
	printf("%d\n", get_result(m, t, u, f, d));
	return 0;
}
