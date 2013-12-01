#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "animal.h" /*TEMP*/

struct listNode *list_create() {
	struct listNode *new = calloc(1, sizeof(struct listNode));

	if (!new)
		return NULL;

	return new;
}

void list_destroy(struct listNode *L, void(*destroy)(void *)) {
    
}

void list_destroy_rec(struct listNode *L, void(*destroy)(void *)) {
    if (L->next) list_destroy_rec(L->next, destroy);

    destroy(L->data);
    free(L);
}


struct listNode * initNode(void *data){
    struct listNode *new = malloc(sizeof(struct listNode));
    new->data = data;
    new->next = NULL;
    return new;
}

struct listNode * list_addHead(struct listNode *list, void *data) {
    struct listNode *first;
    first = initNode(data);
    first->next = list;
    return first;
}

int list_addTail(struct listNode *tail, void *data) {
    tail->next = initNode(data);
	return 0;
}

struct listNode * list_rmHead(struct listNode *L, void(*destroy)(void *)) {
	struct listNode *head;
	if (!L)
        return NULL;

	head = L->next;
	destroy(L->data);
	free(L);
	return head;
}

struct listNode * list_rmTail(struct listNode *L,  void(*destroy)(void *)) {
    struct listNode *newTail = L;

    if (!L->next) {
        destroy(L->data);
        free(L);
        return NULL;
    }
	
    while (L->next) {
        newTail = L;
        L = L->next;
    }

    newTail->next = NULL;
    destroy(L->data);
    free(L);
    return newTail;
}

int list_length(struct listNode *L, int length) {
    if (L->next)
        return list_length(L->next, ++length);

	return length;
}

int list_itemExists(int val) {
	return 0;
}

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int list_print(struct listNode *L, int(*print)(void *)) {
	while (L) {
        print(L->data);
		L = L->next;
	}
	return 0;
}

struct listNode * list_getTail(struct listNode *L) {
	if (L->next)
        return list_getTail(L->next);

	return L;
}