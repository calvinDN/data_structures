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

void LL_destroy(List *L) {}

void LL_updateTail(List *L){}

void LL_addHead(List *L, void *data) {
    list_addHead(L->head, data);
}

void LL_addTail(List *L, void *data) {}

/*update tail*/
void LL_rmHead(List *L) {
    list_removeHead(L->head);
}

/*update tail*/
void LL_rmTail(List *L) {
    list_removeTail(L->head);
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
    return 0;
}

int LL_printHead(List *L) {
    return 0;
}

