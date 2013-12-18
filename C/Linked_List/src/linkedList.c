#include <stdlib.h>
#include <stdio.h>
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

/* User responsible for freeing their functions */
/*void LL_destroy(List *L) {
	while (L->head)
		list_rmHead(L->head, L->destroy);

    free(L);
}*/

void LL_destroy(List *L) {
    list_destroy(L->head->next, L->destroy);

    free(L);
}

/*not working*/
Boolean LL_updateTail(List *L){
    if (!L->head->next) {
        L->tail = L->head;
        return TRUE;
    }
    L->tail = list_getTail(L->head->next);
    return TRUE;
}

Boolean LL_addHead(List *L, void *data) {
	L->head->next = list_addHead(L->head->next, data);
    if (!LL_updateTail(L))
        return FALSE;

    return TRUE;
}

Boolean LL_addTail(List *L, void *data) {
    list_addTail(L->tail, data);

    if (!LL_updateTail(L))
        return FALSE;

	return TRUE;
}

Boolean LL_rmHead(List *L) {
    /*if (!L->head->next)
        return TRUE;*/
    L->head->next = list_rmHead(L->head->next, L->destroy);
	return TRUE;
}

Boolean LL_rmTail(List *L) {
    if (!L->head->next) /* could also check head */
        return TRUE;

	L->tail = list_rmTail(L->head->next, L->destroy);
    if (!L->tail) L->head->next = L->tail;

    return TRUE;
}

int LL_length(List *L) {
    return list_length(L->head, 0);
}

Boolean LL_itemExists(List *L, void *data) {
	return 0;
}

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int LL_print(List *L) {
    if (L->head->next)
    	list_print(L->head->next, L->print);
    return 0;
}

int LL_printTail(List *L) {
    if (!L->head->next)
        return 0;
    L->print(L->tail->data);
    return 0;
}

int LL_printHead(List *L) {
    if (!L->head->next)
        return 0;
    L->print(L->head->next->data);
    return 0;
}

