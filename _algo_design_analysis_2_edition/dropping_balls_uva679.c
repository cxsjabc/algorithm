#include "common_local.h"

const int D = 20;	// max depth
int s[1 << D];		// store the node status

// has bugs
int main()
{
	int D, I;
	while(scanf("%d%d", &D, &I) == 2) {
		memset(s, 0, sizeof(s));
		int i;
		int k;
		for(i = 0; i < I; ++i) {	// for each node
			k = 1;				// the first node index
			while(1) {
				int j = k;
				k = s[k] ? 2 * k + 1 : 2 * k;
				s[j] = !s[j];
				if(k >= 1 << D)
					break;
			}
		}
		printf("%d\n", k / 2);
	}

    return 0;
}
