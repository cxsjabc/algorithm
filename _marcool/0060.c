#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

int s[101];
int s_max_cnt[101];
int main()
{
	int n, max_cnt;
	int i;
	int k = 0;
	
	while(scanf("%d", &n) == 1) {
		s[n]++;
		if(getchar() == '\n')
			break;
	}

	max_cnt = 0;
	s_max_cnt[k++] = 0;

	for(i = 1; i < 101; ++i) {
		if(s[i] > s[max_cnt]) {
			k = 0, s_max_cnt[k++] = max_cnt = i;
		} else if(s[i] == s[max_cnt]) {
			s_max_cnt[k++] = i;
		}
	}
	
	for(i = 0; i < k; ++i) {
		if(i != k - 1)
			printf("%d ", s_max_cnt[i]);
		else
			printf("%d", s_max_cnt[i]);
	}
	printf("\n");
	
	return 0;
}
