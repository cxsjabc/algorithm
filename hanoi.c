#include <stdio.h>

#include "common.h"


void hanoi(int from, int use, int dest, int cnt)
{
	if(cnt == 1)
		printf("Move %d from %c to %c\n", cnt, (char)from, (char)dest);
	else {
		hanoi(from, dest, use, (cnt - 1));
		printf("Move %d from %c to %c\n", cnt, (char)from, (char)dest);
		hanoi(use, from, dest, (cnt - 1));
	}
}

int main()
{
	hanoi('A', 'B', 'C', 6);	
	return 0;
}
