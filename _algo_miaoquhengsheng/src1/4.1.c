#include "common_local.h"

void show_char_cnt()
{
	int c;
	int cb = 0, ct = 0, cn = 0;

	while((c = getchar()) != EOF) {
		if(c == ' ')
			++cb;
		else if(c == '\t')
			++ct;
		else if(c == '\n')
			++cn;
	}
	printf("blank count:%d, tab count:%d, new_line count:%d\n", cb, ct, cn);
}

int main()
{
	show_char_cnt();
    return 0;
}
