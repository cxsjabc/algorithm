#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

char	get_score_level(int score)
{
	char ret = 'E';

	if(score >= 60)
		ret = ret - (score - 60) / 10 - 1;
	if(ret < 'A')
		ret = 'A';

	return ret;
}

int main()
{
	int score;

	scanf("%d", &score);
	printf("%c\n", get_score_level(score));
	return 0;
}
