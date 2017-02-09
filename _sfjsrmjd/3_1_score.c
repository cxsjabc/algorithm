#include "common.h"

const char *s = "OOXXOXXOOO";

int main()
{
	int O_score = 1;
	int X_score = 0;
	int score = 0;	

	while(*s) {
		if(*s == 'O')
			score += O_score, ++O_score;
		else if(*s == 'X')
			score += X_score, O_score = 1;
		++s;
	}

    printf("score: %d\n", score);
    return 0;
}
