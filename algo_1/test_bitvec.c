#include "common_local.h"
#include "bitvec.h"

int main()
{
	int *p;
	int i;

	p = (int *)bitvec_create(128, 0);
	assert(p);

	bitvec_set(p, 10);
	bitvec_set(p, 31);
	bitvec_set(p, 32);

	for(i = 0; i < 128; ++i) {
		printf("%d ", bitvec_get(p, i));
		if((i + 1) % 10 == 0)
			printf("\n");	
	}

	bitvec_free(p);

    return 0;
}
