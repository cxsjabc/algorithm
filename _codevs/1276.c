#include <stdio.h> 

const char icon[3][3] = {
  {'*', 'x', '*'},
  {' ', 'x', 'x'},
  {'*', ' ', '*'},
};

void icon_scale(int k)
{
	int i, j;

	for(i = 0; i < 3; ++i) {	// each line
		int t = 0;
		while(t++ < k) {	// repeat k times of each line
			for(j = 0; j < 3; ++j) {	// each column
				int s = 0;
				while(s++ < k)		// repeat k times of each column on the line
					putchar(icon[i][j]);
			}
			putchar('\n');
		}
	}	
}

int main()
{
	int scale;
	scanf("%d", &scale);
	icon_scale(scale);
    return 0;
}
