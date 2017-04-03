#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define N	100

typedef struct _Milk
{
	char 	n[21];
	int		p;
}
Milk;

Milk all_milk[N];
Milk un_qualified_milk[N];

int		is_str_in_milk_arr(const char *s, Milk *m, int size)
{
	int i = 0;

	while(i < size) {
		if(strcmp(s, m[i].n) == 0)
			return 1;
		++i;
	}
	return 0;
}

int main()
{
	int n, m;
	int i;
	int p;
	int index;
	int no_dup = 0;

	scanf("%d%d", &n, &m);
	for(i = 0; i < m; ++i)
		scanf("%s", un_qualified_milk[i].n);	
	for(i = 0; i < n; ++i)
		scanf("%d%s", &(all_milk[i].p), all_milk[i].n);

	p = all_milk[0].p, index = 0;	
	if(is_str_in_milk_arr(all_milk[0].n, un_qualified_milk, m))
		index = -1;
	for(i = 1; i < n; ++i) {
		if(is_str_in_milk_arr(all_milk[i].n, un_qualified_milk, m))
			continue;
		if(all_milk[i].p < p || index == -1)
			no_dup = 1, p = all_milk[i].p, index = i;
		else if(all_milk[i].p == p)
			no_dup = 0;
	}
	if(index != -1 && no_dup == 1) {
		printf("%s\n", all_milk[index].n);
	} else
		printf("no answer.\n");	

	return 0;
}
