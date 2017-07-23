#include "common_local.h"
#include "bitvec.h"

void *	bitvec_create(int size, int init_value)
{
	int true_size;
	void *p;

	true_size = size / 4 + 1;
	p = (void *)malloc(sizeof(int) * true_size);
	if(!p)
		return NULL;

	if(init_value != 0 && init_value != 1)
		return NULL;

	if(init_value == 1)
		memset(p, 0xFF, true_size * sizeof(int));
	else
		memset(p, 0, true_size * sizeof(int));

	return p;
}

int		bitvec_set(void *bv, int pos)
{
	int r = 0;
	int i, j;
	int *pbv;

	pbv = (int *)bv;
	i = pos / sizeof(int);
	j = pos % sizeof(int);
	pbv[i] |= (1 << j);
	
	return r;
}

int		bitvec_clr(void *bv, int pos)
{
	int r = 0;
	int i, j;
	int *pbv;

	pbv = (int *)bv;
	i = pos / sizeof(int);
	j = pos % sizeof(int);
	pbv[i] &= ~(1 << j);

	return r;
}

int		bitvec_get(void *bv, int pos)
{
	int i, j;
	int *pbv;
	int temp;

	pbv = (int *)bv;
	i = pos / sizeof(int);
	j = pos % sizeof(int);
	temp = pbv[i];
	temp &= (1 << j);

	return temp != 0;
}

void	bitvec_free(void *bv)
{
	free(bv);
}
