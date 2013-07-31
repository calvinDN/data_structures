#include <stdlib.h>
#include "list.h"


struct listNode *list_create() {
	struct listNode *new = calloc(1, sizeof(struct listNode));

	if (!new)
		return NULL;

	return new;
}

void list_destroy(struct listNode *node) {
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

void list_rmHead(struct listNode *L) {
	/*listNode *tmp;
	if (!L->head->next) {
		L->destroy(L->head);
		L->head = NULL;
	}

	tmp = L->head;
	L->head = L->head->next;
	L->destroy(tmp);*/
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
		print(L->data);
		L = L->next;
	}
	return 0;
}

