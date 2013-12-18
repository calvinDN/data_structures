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

void LL_destroy(List *);

void LL_addHead(List *, void *);

void LL_addTail(List *, void *);

void LL_rmHead(List *);

void LL_rmTail(List *);

int LL_length(List *);

void LL_itemExists(List *, void *);

int LL_print(List *);

int LL_printTail(List *L);

int LL_printHead(List *L);