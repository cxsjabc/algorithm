#include "common_local.h"

char fruit[][10] = {"apple", "orange", "banana", "pineapple", "pear"};

int get_fruit_count()
{
	int x, y, z;
	int cnt = 0;

	for(x = 1; x <= 5; ++x) {
		for(y = 1; y <= 5; ++y) {
			for(z = 1; z <= 5; ++z) {
				if(x != y && y != z && z != x) {
					++cnt;
					printf("%s %s %s\n", fruit[x - 1], fruit[y - 1], fruit[z - 1]);
				}
			}
		}
	}
	return cnt;
}

int main()
{
    printf("%d\n", get_fruit_count());
    return 0;
}
