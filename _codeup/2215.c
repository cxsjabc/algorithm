#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

void trans_pos(int a[3][3], int out[3][3], int r, int c)
{
	int i, j;
	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			out[j][i] = a[i][j];
		}
	}
}

int main()
{
	int n = 3;
	int i = 0, j;
	int a[3][3], out[3][3];

	while(i < 3) {
		j = 0;
		while(j < 3) {
			scanf("%d", &a[i][j]);
			++j;
		}
		++i;
	}
	trans_pos(a, out, 3, 3);

	for(i = 0; i < 3; ++i) {
		for(j = 0; j < 3; ++j) {
			printf("%d ", out[i][j]);
		}
		printf("\n");
	}
	return 0;
}
