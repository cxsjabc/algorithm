#include "common_local.h"

void	get_chicks()
{
	int x, y, z;

	for(x = 1; x < 100; ++x) {
		for(y = 1; y < 100; ++y) {
			for(z = 1; z < 100; ++z) {
				if(x + y + z == 100 && z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100) {
					printf("%d %d %d\n", x, y, z);
				}
			}
		}
	}
}

void	get_chicks1()
{
	int x, y, z;

	for(x = 1; x < 20; ++x) {
		for(y = 1; y < 34; ++y) {
			for(z = 3; z < 100; z += 3) {
				if(x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100) {
					printf("%d %d %d\n", x, y, z);
				}
			}
		}
	}
}

void	get_chicks2()
{
	int x, y, z;

	for(x = 1; x < 20; ++x) {
		for(y = 1; y < 34; ++y) {
			z = 100 - x - y;
			if(z % 3 == 0 && 5 * x + 3 * y + z / 3 == 100) {
				printf("%d %d %d\n", x, y, z);
			}
		}
	}
}

int main()
{
	get_chicks();
	get_chicks1();
	get_chicks2();
    return 0;
}
