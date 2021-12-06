//
// Created by Usuario on 04/12/2021.
//

#ifndef CONECTAN_CONECTAN_H
#define CONECTAN_CONECTAN_H

typedef struct movimiento Movimiento;
typedef struct juego Juego;

Juego *nuevoJuego(int N);

void nuevoMovimiento(Juego *juego, int jugador, int renglon, int columna);

void printArreglos(Juego * juego);

int ganoColumna(Juego* juego, int N, Movimiento* mov);

int ganoRenglon(Juego* juego, int N, int jugador);

int ganoDiagonalDerecha(Juego* juego, int N, int jugador);

int ganoDiagonalIzquierda(Juego* juego, int N, int jugador);




#endif //CONECTAN_CONECTAN_H
