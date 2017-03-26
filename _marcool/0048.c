#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

#define SCANF_3(a, b, c)	scanf("%d%d%d", &(a), &(b), &(c))

#define	N	10
char arr[N][N];

int main()
{
	int r, c, e;
	int i, j;
	int er = 0, ec;
	int fa[N][N] = {0};	
	int step = 0;
	int path[N][N] = {0};
	char ch;

	SCANF_3(r, c, e);
	ec = e - 1;

	while((ch = getchar()) == '\n' );
	ungetc(ch, stdin);

	for(i = 0; i < r; ++i) {
		for(j = 0; j < c; ++j) {
			scanf("%c", &arr[i][j]);
			if(arr[i][j] == '\n')
				--j;
		}
	}

	while(1) {
		//printf("er:%d, ec:%d, fa[er][ec]:%d, arr[er][ec]:%c\n", er, ec, fa[er][ec], arr[er][ec]);
		//sleep(1);
		if(er >= r || er < 0 || ec >= c || ec < 0) {
			printf("%d\n", step);
			break;
		}
		if(fa[er][ec] == 1) {	// loop
			printf("%d %d\n", path[er][ec], step - path[er][ec]);
			break;
						
		}
		if(arr[er][ec] == 'N')	{
			fa[er][ec] = 1;
			path[er][ec] = step;
			--er;
		}
		else if(arr[er][ec] == 'E')	{
			fa[er][ec] = 1;
			path[er][ec] = step;
			++ec;
		}
		else if(arr[er][ec] == 'S')	 {
			fa[er][ec] = 1;
			path[er][ec] = step;
			++er;
		}
		else if(arr[er][ec] == 'W') {
			fa[er][ec] = 1;
			path[er][ec] = step;
			--ec;
		}
		++step;
	}	

	return 0;
}
