#include "common_local.h"

int is_circular_rotation(const char *s1, const char *s2)
{
	int i;
	int len1, len2;

	len1 = strlen(s1);
	len2 = strlen(s2);
	if(len1 != len2)
		return 0;

	for(i = 0; i < len1; ++i) {
		int j = i;
		int k = 0;
		int flag1 = 0;
		for(; k < len1 - i; ++k) {
			if(s1[i + k] != s2[k]) {
				flag1 = 1;
				break;
			}	
		}		
		if(flag1 == 1)
			continue;
		for(k = 0; k < j; ++k) {
			if(s1[k] != s2[len1 - i + k]) {
				flag1 = 1;
				break;
			}
		}

		if(flag1 == 1)
			continue;

		return 1;
	}
	return 0;
}


int main()
{
	const char *s1 = "ACTGACG";
	const char *s2 = "TGACGAC";
	printf("%d\n", is_circular_rotation(s1, s2));
    return 0;
}
