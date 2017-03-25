#include <stdio.h> 

#define N	10

int main()
{
	int n;
	int i;
	double result;
	double all_credit = 0, all_score = 0;	
	double credit, score;

	scanf("%d", &n);

	for(i = 0; i < n; ++i) {
		scanf("%lf%lf", &credit, &score);
		all_credit += credit;
		all_score += credit * score;
	}
	result = all_score / all_credit;
	printf("%.2lf\n", result);

    return 0;
}
