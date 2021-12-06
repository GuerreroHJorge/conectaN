//
// Created by Usuario on 06/12/2021.
//

#ifndef CONECTAN_QUEUE_H
#define CONECTAN_QUEUE_H

#include "conectaN.h"

struct Node_struct {
    Movimiento *dato;
    struct Node_struct* next;
};
typedef struct Node_struct* Node_ref;

typedef struct {
    Node_ref First;
    Node_ref Last;
    int count;
} Queue;

Queue* queue_create();
void queue_offer(Queue* q, Movimiento *mov);
Movimiento *queue_poll(Queue* q);
void queue_destroy(Queue* q);

#endif //CONECTAN_QUEUE_H
