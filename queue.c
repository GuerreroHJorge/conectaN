//
// Created by Usuario on 06/12/2021.
//
#include "queue.h"
#include <stdlib.h>
#include "conectaN.h"

Node_ref newNode(Movimiento *mov)
{
    Node_ref n = malloc(sizeof(struct Node_struct));

    n->dato = mov;
    n->next = NULL;

    return n;
}

Queue* queue_create()
{
    Queue* foo = malloc(sizeof(Queue));

    foo->count = 0;
    foo->First = NULL;
    foo->Last = NULL;

    return foo;
}

void queue_offer(Queue* q, Movimiento *mov)
{
    Node_ref nodeToAdd = newNode(mov);

    if(q->count == 0)
    {
        q->First = nodeToAdd;
        q->Last = nodeToAdd;
    } else {
        q->Last->next = nodeToAdd;
        q->Last = nodeToAdd;
    }
    q->count++;
}

Movimiento *queue_poll(Queue* q)
{
    Node_ref toRemove = q->First;

    if(toRemove != NULL)
    {
        Movimiento *dataToReturn = toRemove->dato;
        q->First = toRemove->next;
        free(toRemove);
        q->count--;
        return dataToReturn;
    }

    return 0;
}

void queue_destroy(Queue* q)
{
    while(q->count > 0)
        queue_poll(q);

    free(q);
}

