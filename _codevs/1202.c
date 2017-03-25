#include <stdio.h> 

int main()
{
	int n;
	long sum = 0, data;
	int i;

	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		scanf("%ld", &data);
		sum += data;
	}

    printf("%ld\n", sum) ;
    return 0;
}
