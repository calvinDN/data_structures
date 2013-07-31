#include "boolean.h"

struct listNode
{
    void *data;
    struct listNode *next;
};

struct listNode *list_create();

void list_destroy(struct listNode *, void(*destroy)(void *));

struct listNode * list_addHead(struct listNode *, void *);

int list_addTail(int val);

struct listNode * list_rmHead(struct listNode *L, void(*destroy)(void *));

int list_rmTail(int val);

int list_length(int val);

int list_itemExists(int val);

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int list_print(struct listNode *L, int(*print)(void *));

struct listNode * list_getTail(struct listNode *L);