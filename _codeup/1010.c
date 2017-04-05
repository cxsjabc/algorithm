#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// too slow! I don't know why ?

char s[] = {'A', 'B', 'C', 'D', 'F'};
int	 score[] = {4, 3, 2, 1, 0};

int	is_in_s(char c)
{
	return c == 'A' || c == 'B' || c == 'C' || c == 'D' || c == 'F';
}

int	get_score(char c)
{
	int ret;
	switch(c) {
		case 'A':
			ret = 4;
		break;
		case 'B':
			ret = 3;
		break;
		case 'C':
			ret = 2;
		break;
		case 'D':
			ret = 1;
		break;
		case 'F':
			ret = 0;
		break;
		default:
			ret = -1;
		break;
	}
	return ret;
}

int main()
{
	double sum = 0;
	char ch;
	int ch_in_abcde = 1;
	int cnt = 0;

	while(1) {
		ch = getchar();
		if(ch == '\n') {
			if(ch_in_abcde)
				printf("%.2f\n", sum / cnt);
			else
				printf("Unknown\n");
			cnt = 0;
			ch_in_abcde = 1;
			sum = 0;
		}
		else if(is_in_s(ch))
			sum += get_score(ch), ++cnt;
		else if(ch == ' ')
			continue;
		else
			ch_in_abcde = 0;
	}	

	return 0;
}
