#include "linkedList.h"

typedef struct Queue {
    List *list;
}Queue;

Queue *Q_create( int(*compare)(void *, void *), int(*print)(void *), void(*destroy)(void *) );

int Q_doesExist(Queue *, void *);

void Q_destroy(Queue *);

void Q_pop(Queue *, void *);

void Q_push(Queue *, void *);

void *Q_peek(Queue *);

int Q_length(Queue *);
