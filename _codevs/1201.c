#include <stdio.h> 

int main()
{
	int n;
	long data;
	long max, min;
	int i;

	scanf("%d", &n);
	scanf("%ld", &data);
	max = min = data;

	for(i = 1; i < n; ++i) {
		scanf("%ld", &data);
		if(data > max)
			max = data;
		else if(data < min)
			min = data;
	}

    printf("%ld %ld\n", min, max) ;
    return 0;
}
