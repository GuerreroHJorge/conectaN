//
// Created by Usuario on 06/12/2021.
//

#ifndef CONECTAN_QUEUE_H
#define CONECTAN_QUEUE_H

#include "conectaN.h"

typedef struct Node_struct* Node_ref;

typedef struct queue Queue;
typedef struct movimiento Movimiento;

Queue* queue_create();
void queue_offer(Queue* q, Movimiento *mov);
Movimiento *queue_poll(Queue* q);
void queue_destroy(Queue* q);

//Queue *regresaCola(Juego *juego);


#endif //CONECTAN_QUEUE_H
