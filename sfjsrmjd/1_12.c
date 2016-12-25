#include <stdio.h>

int main()
{
	int a, b, c;
	int max, mid, min;

	scanf("%d%d%d", &a, &b, &c);

	if(a < b) {
		if(a < c) {
			min = a;
			if(b > c)
				max = b, mid = c;
			else
				max = c, mid = b;
		} else {
			max = b, mid = a, min = c;
		}
	} else {
		if (a > c) {
			max = a;
			if(b > c)
				mid = b, min = c;
			else
				mid = c, min = b;
		} else {
			max = c, mid = a, min = b;
		}
	}

	printf("%d %d %d\n", min, mid, max);

    return 0;
}
