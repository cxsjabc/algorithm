#include "common_local.h"

int	get_fac_tailing_zero(int n)
{
	int cnt_5 = 0;

	while(n >= 5) {
		int k = n;
		while(k) {
			if(k % 5 == 0) {
				++cnt_5;
				k /= 5;
			} else
				break;
		}
		--n;
	}
	return cnt_5;
}

int main()
{
	int n;

	scanf("%d", &n);
    printf("%d\n", get_fac_tailing_zero(n));
    return 0;
}
