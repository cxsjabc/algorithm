#define LOG_LEVEL DEBUG
#include "common.h"

int main()
{
	int n;
	int cnt;
	int arr[10];		// stores the count of the number: 0, 1, 2
	
	scanf("%d", &cnt);
	while(cnt-- > 0) {
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);

		while(n > 0) {
			int m = n;
			while( m > 0) {
				arr[m % 10]++;
				log_v("arr[%d]:%d\n", m % 10, arr[m % 10]);
				m /= 10;
			}
			--n;
		}
		for(int i = 0; i < 10; ++i)
    		printf("%d ",arr[i]);
		printf("\n");
	}
    return 0;
}
