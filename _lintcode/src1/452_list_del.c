#include "common_local.h"

typedef struct _ListNode
{
	int val;
	struct _ListNode	*next;
}ListNode;

ListNode * removeElements(ListNode * head, int val) {
    // write your code here
    ListNode *pp, *p, *pn;
    
	if(!head)
		return NULL;

	pp = NULL;
	p = head;
 
    while(p) {
		pn = p->next;
        if(p->val == val) {
			if(p == head) {
				head = pn;
				p = pn;
			} else {
				pp->next = pn;	
				p = pn;
			}
		} else {
			pp = p;
        	p = p->next;
		}
    }
	return head;
}

int main()
{
    printf("%d\n", 0);
    return 0;
}
