#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int main()
{
	char s[][5] = {"  *  ", " * * ", "*   *", " * * ", "  *  "};
	int i, j;

	for(i = 0; i < 5; ++i) {
		for(j = 0; j < 5; ++j) {
			printf("%c", s[i][j]);
		}
		printf("\n");
	}
	return 0;
}
