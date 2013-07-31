#include "list.h"

typedef struct LinkedList
{
    struct listNode *head;
    struct listNode *tail;

	int  (*compare)  (void *, void *);
	int  (*print)    (void *);
	void (*destroy)  (void *);

}List;

List * LL_create( int(*compare)(void *, void *), int(*print)(void *), void(*destroy)(void *) );

void LL_destroy(List *);

Boolean LL_addHead(List *, void *);

Boolean LL_addTail(List *, void *);

Boolean LL_rmHead(List *);

Boolean LL_rmTail(List *);

int LL_length(List *);

Boolean LL_itemExists(List *, void *);

int LL_print(List *);

int LL_printTail(List *L);

int LL_printHead(List *L);