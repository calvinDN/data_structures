struct listNode {
    void *data;
    struct listNode *next;
};

struct listNode *list_create();

void list_addTail(struct listNode *L, void *data);

void list_addHead(struct listNode *L, void *data);

void list_removeTail(struct listNode *L, void(*destroy)(void *));

void list_removeHead(struct listNode *L, void(*destroy)(void *));

void list_destroy(struct listNode *L, void(*destroy)(void *));

void list_print(struct listNode *L, int(*print)(void *));


