#include <stdio.h>

#include "common.h"


#define RECORD_NUM (32)

int climb_record[RECORD_NUM];
int *p_climb_record = climb_record;

void print_steps(int element_cnt)
{
	int i;
	for(i = 0; i < element_cnt; ++i) {
		//printf("%d ", p_climb_record[i]);
	}
	//printf("\n");
}
	

int climb(int step_total, int step_index)
{
	int cnt = 0;
	static int init_call = 0;
	if(init_call == 0) {
		if(step_total > 32) {
			p_climb_record = (int *)malloc(step_total * sizeof(int));
			if(!p_climb_record) {
				printf("Error, no mem!\n");
				return -1;
			}
		}
	}

	if(step_total == 0) {
		print_steps(step_index + 1);
		++cnt;
		return cnt;
	}

	if(step_total == 1) {
		p_climb_record[step_index] = 1;
		print_steps(step_index + 1);
		++cnt;
	}
	else if(step_total == 2) {
		p_climb_record[step_index] = 1;
		p_climb_record[step_index + 1] = 1;
		print_steps(step_index + 2);
		++cnt;
		p_climb_record[step_index] = 2;
		print_steps(step_index + 1);
		++cnt;
		
	} else {
		p_climb_record[step_index] = 1;
		cnt += climb(step_total - 1, step_index + 1);
		p_climb_record[step_index] = 2;
		cnt += climb(step_total - 2, step_index + 1);
	}
	return cnt;	
}

int main(int argc, char *argv[])
{
	//printf("argc:%d\n", argc);
	if(argc == 1) {
		PN(climb(6, 0));
		return 0;
	}

	if(argc == 2) {
		//printf("argc:%d, argv[1]:%s\n", argc, argv[1]);
		PN(climb(atoi(argv[1]), 0));
	}
	
	return 0;
}

