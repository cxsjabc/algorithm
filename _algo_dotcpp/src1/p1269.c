#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <math.h> 

#define INPUT(n)		scanf("%d", &(n))
#define INPUT2(n1, n2)	scanf("%d%d", &(n1), &(n2))
#define INPUT3(n1, n2, n3)	scanf("%d", &(n1), &(n2), &(n3))

typedef struct
{
	char name[21];
	int avg_score;
	int class_score;
	char	stu_leader;
	char 	is_western;
	int papers;
	int award;
}STU;

void cal_award(STU *s)
{
	if(s->avg_score > 80 && s->papers >= 1)
		s->award += 8000;
	if(s->avg_score > 85 && s->class_score > 80)
		s->award += 4000;
	if(s->avg_score > 90)
		s->award += 2000;
	if(s->avg_score > 85 && s->is_western == 'Y')
		s->award += 1000;
	if(s->class_score > 80 && s->stu_leader == 'Y')
		s->award += 850;
}

int main()
{
	int n;
	STU stu, stu_max;
	int award_total = 0;
	int first = 1;

	stu_max.award = 0;
	INPUT(n);

	while(n--) {
		if(first) {
			scanf("%s%d%d %c %c%d", stu_max.name, &stu_max.avg_score, &stu_max.class_score, 
				&stu_max.stu_leader, &stu_max.is_western, &stu_max.papers);
			first = 0;
			cal_award(&stu_max);
			award_total += stu_max.award;
		}
		else {
			stu.award = 0;
			scanf("%s%d%d %c %c%d", stu.name, &stu.avg_score, &stu.class_score, 
				&stu.stu_leader, &stu.is_western, &stu.papers);
			cal_award(&stu);
			award_total += stu.award;

			if(stu.award > stu_max.award) {
				memcpy(stu_max.name, stu.name, strlen(stu.name) + 1);
				stu_max.award = stu.award;
			}
		}	
	}

	printf("%s\n%d\n%d\n", stu_max.name, stu_max.award, award_total);
	return 0;
}
