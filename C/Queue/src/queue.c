#include <stdlib.h>
#include "queue.h"

Queue *Q_create( int(*compare)(void *, void *), int(*print)(void *), void(*destroy)(void *) ) {
    Queue *newQueue = malloc(sizeof(Queue));
    if (!newQueue) return NULL;

    newQueue->list = LL_create(compare, print, destroy);
    return newQueue;
}

int Q_doesExist(Queue *Q, void *data) {
    return 0;
}

void Q_destroy(Queue *Q) {

}

void Q_dequeue(Queue *Q, void *data) {
    LL_rmHead(Q->list);
}

void Q_queue(Queue *Q, void *data) {
    LL_addTail(Q->list, data);
}

void *Q_peek(Queue *Q) {
}

int Q_length(Queue *Q) {
    return 0;
}
