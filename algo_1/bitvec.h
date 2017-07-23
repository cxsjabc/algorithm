#ifndef BITVEC_H
#define	BITVEC_H

void *	bitvec_create(int size, int init_value);
int		bitvec_set(void *bv, int pos);
int		bitvec_clr(void *bv, int pos);
int		bitvec_get(void *bv, int pos);

void	bitvec_free(void *bv);

#endif
