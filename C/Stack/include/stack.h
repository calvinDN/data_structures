#include "linkedList.h"

typedef struct Stack {
    List *list;
}Stack;

Stack *S_create( int(*compare)(void *, void *), int(*print)(void *), void(*destroy)(void *) );

int S_doesExist(Stack *, void *);

void S_destroy(Stack *);

void S_pop(Stack *, void *);

void S_push(Stack *, void *);

void *S_peek(Stack *);

int S_length(Stack *);
