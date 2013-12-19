#include "list.h"

typedef struct LinkedList
{
    int length;

    struct listNode *head;
    struct listNode *tail;

	int  (*compare)  (void *, void *);
	int  (*print)    (void *);
	void (*destroy)  (void *);

}List;

List * LL_create( int(*compare)(void *, void *), int(*print)(void *), void(*destroy)(void *) );

int LL_doesExist(List *, void *);

void LL_destroy(List *);

void LL_addHead(List *, void *);

void LL_addTail(List *, void *);

void LL_rmHead(List *);

void LL_rmTail(List *);

int LL_length(List *);

void *LL_getHead(List *L);

void *LL_getTail(List *L);