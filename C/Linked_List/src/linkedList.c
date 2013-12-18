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

int LL_doesExist(List *L, void *data) {
    return list_doesExist(L->head, data, L->compare);
}

void LL_destroy(List *L) {
    list_destroy(L->head, L->destroy);
    free(L);
}

void LL_updateTail(List *L){
    L->tail = list_getTail(L->head);
}

void LL_addHead(List *L, void *data) {
    list_addHead(L->head, data);
    LL_updateTail(L);
}

void LL_addTail(List *L, void *data) {
    list_addTail(L->head, data);
    LL_updateTail(L);
}

void LL_rmHead(List *L) {
    list_removeHead(L->head, L->destroy);
    LL_updateTail(L);
}

void LL_rmTail(List *L) {
    list_removeTail(L->head, L->destroy);
    LL_updateTail(L);
}

int LL_length(List *L) {
    return list_length(L->head, 0);
}

void LL_itemExists(List *L, void *data) {}

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int LL_print(List *L) {
    return 0;
}

int LL_printTail(List *L) {
    if (L->tail->data)
        L->print(L->tail->data);
    return 0;
}

int LL_printHead(List *L) {
    if (L->head->next)
        L->print(L->head->next->data);
    return 0;
}

void LL_debug(List *L) {
    printf("head: ");
    LL_printHead(L);
    printf("tail: ");
    LL_printTail(L);
}