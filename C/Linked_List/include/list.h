#include "boolean.h"

struct listNode
{
    void *data;
    struct listNode *next;
};

struct listNode *list_create();

void list_destroy(struct listNode *);

int list_addHead(int val);

int list_addTail(int val);

void list_rmHead(struct listNode *L);

int list_rmTail(int val);

int list_length(int val);

int list_itemExists(int val);

/*variable length paramters
if a pointer is an arguement, print it, otherwise, print entire list*/
int list_print(int val);