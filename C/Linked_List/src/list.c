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
	if (L->next)
		list_destroy(L->next, destroy);

	destroy(L->data);
	free(L);
	/* need a base case here */
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

int list_addTail(int val) {
	return 0;
}

struct listNode * list_rmHead(struct listNode *L, void(*destroy)(void *)) {
	struct listNode *tmp;
	if (!L)
        return NULL;

	tmp = L->next;
	destroy(L->data);
	free(L);
	return tmp;
}

int list_rmTail(int val) {
	return 0;
}

int list_length(int val) {
	return 0;
}

int list_itemExists(int val) {
	return 0;
}

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int list_print(struct listNode *L, int(*print)(void *)) {
	while (L) {
		L = L->next;
	}
	return 0;
}

struct listNode * list_getTail(struct listNode *L) {
    struct listNode *tail = NULL;
	if (L->next) {
		tail = list_getTail(L->next);
        return tail;
	}

	return L;
}