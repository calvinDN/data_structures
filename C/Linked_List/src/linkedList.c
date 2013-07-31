#include <stdlib.h>
#include "linkedList.h"

List * LL_create(int(*compare)(void *, void *), int(*print)(void *), void(*destroy)(void *)) {
    List * newList   = malloc(sizeof(List));
    if (!newList)
    	return NULL;

    newList->head    = list_create(); /* dummy node */
    newList->tail    = newList->head;
    newList->compare = compare;
    newList->print   = print;
    newList->destroy = destroy;

    return newList;
}

void LL_destroy(List *L) {
	while (L->head)
		list_rmHead(L->head);
}

Boolean LL_addHead(List *L, void *data) {
	L->head->next = list_addHead(L->head->next, data);
    if (!LL_updateTail(L))
        return FALSE;

    return TRUE;
}

Boolean LL_updateTail(List *L){
    if (!L->head)
        return FALSE;
    if (!L->head->next)
        L->tail = L->head;

    while (L->head->next->next) {
        L->head = L->head->next;
    }
    L->tail = L->head;
    
    return TRUE;
}

Boolean LL_addTail(List *L, void *data) {
	return 0;
}

Boolean LL_rmHead(List *L) {
	return FALSE;
}

Boolean LL_rmTail(List *L) {
	return 0;
}

int LL_length(List *L) {
	return 0;
}

Boolean LL_itemExists(List *L, void *data) {
	return 0;
}

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int LL_print(int val) {
	return 0;
}

