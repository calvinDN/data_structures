#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "pokemon.h"

struct listNode *initNode(void *data, struct listNode *node){
    struct listNode *newNode = calloc(1, sizeof(struct listNode));
    newNode->data = data;
    newNode->next = node;
    return newNode;
}

struct listNode *list_create() {
    struct listNode *newList;
    
    if (!(newList = initNode(NULL, NULL)))
        return NULL;
    
    return newList;
}

int list_doesExist(struct listNode *L, void *data, int(*compare)(void *, void *)) {
    if (!L->next) return -1;
    while ((L = L->next)) {
        if (compare(data, L->data) == 0) return 0;
    }
    return -1;
}

void list_addHead(struct listNode *L, void *data) {
    struct listNode* oldHead;
    if (!L->next)
        L->next = initNode(data, NULL);
    else {
        oldHead = L->next;
        L->next = initNode(data, oldHead);
    }
}

void list_addTail(struct listNode *L, void *data) {
    if (L->next)
        list_addTail(L->next, data);
    else
        L->next = initNode(data, NULL);
}

void list_removeTail(struct listNode *L, void(*destroy)(void *)) {
    struct listNode* newTail = L;

    if (!L->next) {
        return;
    }

    L = L->next;
    while (L->next) {
        newTail = L;
        L = L->next;
    }
    destroy(L->data);
    free(L);
    newTail->next = NULL;
}

void list_removeHead(struct listNode *L, void(*destroy)(void *)) {
    struct listNode* oldHead;
    if (!L->next)
        return;

    oldHead = L->next;
    if (oldHead->next)
        L->next = oldHead->next;
    else
        L->next = NULL;

    destroy(oldHead->data);
    free(oldHead);
}

void list_destroy(struct listNode *L, void(*destroy)(void *)) {
    while (L->next) {
        list_removeTail(L, destroy);
    }
    free(L);
}

struct listNode *list_getTail(struct listNode *L) {
    if (!L->next) return L;
    list_getTail(L->next);
}

struct listNode *list_getHead(struct listNode *L) {
    if (!L->next) return L;
    return L->next;
}

int list_length(struct listNode *L, int position) { 
    if (!L->next) return position;
    list_length(L->next, ++position);
}

void list_print(struct listNode *L, int(*print)(void *)) {
    if (!L->next) return;
    while ((L = L->next)) {
        print(L->data);
    }
}

