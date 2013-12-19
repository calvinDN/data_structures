#include <stdlib.h>
#include "stack.h"

Stack *S_create( int(*compare)(void *, void *), int(*print)(void *), void(*destroy)(void *) ) {
    Stack *newStack = malloc(sizeof(Stack));
    if (!newStack) return NULL;

    newStack->list = LL_create(compare, print, destroy);
    return newStack;
}

int S_doesExist(Stack *S, void *data) {
    return 0;
}

void S_destroy(Stack *S) {

}

void S_pop(Stack *S, void *data) {
    LL_rmTail(S->list);
}

void S_push(Stack *S, void *data) {
    LL_addTail(S->list, data);
}

void *S_peek(Stack *S) {
}

int S_length(Stack *S) {
    return 0;
}
