#ifndef SET_H
#define SET_H

// this is a simple set, actually, not a really set
// It's implemented by linked list.

typedef struct _SetNode
{
	int v;
	struct _SetNode *next;
} SetNode;

typedef struct _Set 
{
	int			size;
	SetNode		*head;
	SetNode		*tail;
}Set;

typedef SetNode 	*PSetNode;
typedef Set 		*PSet ;

PSet 		set_create();

int			set_copy_from(PSet dest, PSet src);

PSet		set_create_by_nums(int n, ...);
// if ret < 0: means error; if ret == -10: means insert the existing data
int			set_insert(PSet s, int v);
int			set_remove(PSet s, int v);

int			set_union(PSet new_set, PSet s1, PSet s2);
int			set_intersection(PSet new_set, PSet s1, PSet s2);
int			set_difference(PSet new_set, PSet s1, PSet s2);

int			set_is_member(PSet s, int v);
int			set_is_subset(PSet s1, PSet s2);
int			set_is_equal(PSet s1, PSet s2);

void		set_show(PSet s);

void		set_clear(PSet s);
void		set_destroy(PSet s);

int			set_size(PSet s);

#endif
