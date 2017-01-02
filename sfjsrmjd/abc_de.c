#include <stdio.h>
#include <string.h>

int is_n_in_chars(int n, char *s) 
{
	if(n == 0) {
		return strchr(s, '0') != NULL;
	} else {
		while(n > 0) {
			int mod = n % 10;
			if(strchr(s, mod + '0') == NULL)
				return 0;
			n /= 10;
		}
		//printf("%d : %d\n", n, 1);
		return 1;
	}
}

int main()
{
	int abc, de;
	char nums[10];
	scanf("%s", nums);

	for(abc = 100; abc <= 999; ++abc) {
		for(de = 10; de <= 99; ++de) {
			int abce = abc * (de % 10);
			int abcd = abc * (de / 10);
			if(is_n_in_chars(abc, nums) && is_n_in_chars(de, nums) && is_n_in_chars(abce, nums) && is_n_in_chars(abcd, nums) && is_n_in_chars(abcd * 10 + abce, nums)) {
				printf("%5d\n", abc);	
				printf("X%4d\n", de);
				printf("-----\n");
				printf("%5d\n", abce);
				printf("%5d\n", abcd);	
				printf("-----\n");
				printf("%5d\n", 10 * abcd + abce);
			}				
		}
	}
	
    return 0;
}
