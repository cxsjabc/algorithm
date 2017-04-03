#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

typedef struct _Farmer
{
	int p;
	int a;
}Farmer;

static inline int int_compare(const void *v1, const void *v2)
{
	Farmer *fv1 = (Farmer *)v1;
	Farmer *fv2 = (Farmer *)v2;
	
	return fv1->p - fv2->p;
}

void print_farmer(Farmer *f, int size)
{
	int i = 0;

	while(i < size) {
		printf("F:a:%d,p:%d\n", f[i].a, f[i].p);
		++i;
	}
}

int main()
{
	int n, m;
	int i;
	Farmer *far;
	int sum = 0;
	int fee = 0;

	scanf("%d%d", &n, &m);
	far = (Farmer *)malloc(m * sizeof(Farmer));
	if(!far) {
		printf("no mem!\n");
		return -1;
	}
	for(i = 0; i < m; ++i) {
		scanf("%d%d", &(far[i].p), &(far[i].a));
	}

	qsort(&far[0], m, sizeof(Farmer), int_compare);
	//print_farmer(&far[0], m);

	i = 0;
	while(sum < n) {
		if(far[i].a <= n - sum)
			sum += far[i].a, fee += far[i].p * far[i].a;
		else
			fee += (far[i].p * (n - sum)), sum += (n - sum);
		//printf("sum:%d,fee:%d\n", sum ,fee);
		++i;
	}

	free(far);
	printf("%d\n", fee);
	return 0;
}
