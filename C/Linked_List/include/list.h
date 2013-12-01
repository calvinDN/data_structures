#include "boolean.h"

struct listNode
{
    void *data;
    int length;
    struct listNode *next;
};

struct listNode *list_create();

void list_destroy(struct listNode *, void(*destroy)(void *));
void list_destroy_rec(struct listNode *, void(*destroy)(void *));

struct listNode * list_addHead(struct listNode *, void *);

int list_addTail(struct listNode *, void *);

struct listNode * list_rmHead(struct listNode *, void(*destroy)(void *));

struct listNode * list_rmTail(struct listNode *,  void(*destroy)(void *));

int list_length(struct listNode *, int);

int list_itemExists(int val);

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int list_print(struct listNode *, int(*print)(void *));

struct listNode * list_getTail(struct listNode *);