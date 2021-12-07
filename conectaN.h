//
// Created by Usuario on 04/12/2021.
//


#ifndef CONECTAN_CONECTAN_H
#define CONECTAN_CONECTAN_H

#include "queue.h"

typedef struct movimiento Movimiento;
typedef struct juego Juego;

Juego *nuevoJuego(int N);

void nuevoMovimiento(Juego *juego, int jugador, int renglon, int columna);

int ganoColumna(Juego* juego, int N, Movimiento* mov);

int ganoRenglon(Juego* juego, int N, Movimiento* mov);

int ganoDiagonalDerecha(Juego* juego, int N, Movimiento* mov);

int ganoDiagonalIzquierda(Juego* juego, int N, Movimiento* mov);

void printArreglos(Juego * juego);

void printArreglos2(Juego * juego);




#endif //CONECTAN_CONECTAN_H
