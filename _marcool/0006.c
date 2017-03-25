#include <stdio.h> 
#include <stdlib.h> 

#define N 	100
#define M 	20

static inline int int_compare(const void *v1, const void *v2)
{
	return *(int *)v1 - *(int *)v2;
}

int main()
{
    int balls[N], stu[M];
    int n, m;
    int i, j;
    int sum = 0;

    scanf("%d%d", &n, &m);
    for(i = 0; i < n; ++i)
    	scanf("%d", &balls[i]);
	for(i = 0; i < m; ++i)
    	scanf("%d", &stu[i]);

    // sort 
    qsort(balls, n, sizeof(int), int_compare);
    qsort(stu, m, sizeof(int), int_compare);

    for(i = 0; i < m; ++i) {
    	int cnt = 0;
    	static int k = 0;
    	for(j = k; j < n; ++j) {
    		if(stu[i] >= balls[j]) {
    			++sum;
    			++cnt;
    			++k;
    			if (cnt > 1)
    				break;
    		} else
    			break;

    	}
    }
    printf("%d", sum);

    return 0;
}
