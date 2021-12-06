//
// Created by Usuario on 04/12/2021.
//
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include "conectaN.h"
#include "queue.h"

struct movimiento{
    int jugador;
    int renglon;
    int columna;
};

typedef struct movimiento Movimiento;

struct juego{
    Movimiento **jugador1;
    Movimiento **jugador2;
    int turno;
    int N;
    Queue *cola;
};

Movimiento *crearMovimiento(){
    Movimiento *nuevoMov = malloc(sizeof(Movimiento));
    nuevoMov->jugador = 0;
    nuevoMov->renglon = 0;
    nuevoMov->columna = 0;

    return nuevoMov;
};

typedef struct juego Juego;

Juego *nuevoJuego(int N){
    Juego *nuevoJuego = malloc(sizeof(Juego));

    Movimiento **arreglo1;
    nuevoJuego->jugador1 = arreglo1;

    Movimiento **arreglo2;
    nuevoJuego->jugador2 = arreglo2;

    nuevoJuego-> turno = 0;
    nuevoJuego->N = N;
    nuevoJuego->cola = queue_create();

    return nuevoJuego;
};

void nuevoMovimiento(Juego *juego,int jugador, int renglon, int columna){

    Movimiento *mov = crearMovimiento();
    mov->columna = columna;
    mov->renglon = renglon;
    mov->jugador = jugador;

    if(jugador == 1){
        Movimiento **array = juego->jugador1;
        *(array + juego->turno) = mov;
        queue_offer(juego->cola,mov);
        if(juego->turno > juego->N){
            ganoColumna(juego, juego->N, mov);
            //ganoRenglon();
            //ganoDiagonalDerecha();
            //ganoDiagonalIzquierda();
        }
    } else{
        Movimiento **array = juego->jugador2;
        *(array + juego->turno) = mov;
        queue_offer(juego->cola,mov);
        if(((juego->turno)-1) > juego->N){
            ganoColumna(juego, juego->N, mov);
            //ganoRenglon();
            //ganoDiagonalDerecha();
            //ganoDiagonalIzquierda();
        }
        juego->turno++;
    }


}

int ganoColumna(Juego *juego, int N, Movimiento *mov){
    int i = 1;
    int j = 0;
    int juntas = 1;
    if(mov->jugador == 1){
        int renglon = mov->renglon - 1;
        Movimiento **array = juego->jugador1;
        while (j <= N) {
            int b = 0;
            renglon--;
            i = 1;
            while (b==0 && i <= juego->turno) {
                if ((*(array + i))->columna == mov->columna && (*(array + i))->renglon == renglon) {
                    juntas++;
                    b=1;
                }
                i++;
            }
            j++;
        }
    }else{
        int renglon = mov->renglon - 1;
        Movimiento **array2 = juego->jugador2;
        while (j <= N) {
            int b = 0;
            renglon--;
            i = 1;
            while (b==0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == mov->columna && (*(array2 + i))->renglon == renglon) {
                    juntas++;
                    b=1;
                }
                i++;
            }
            j++;
        }
    }

    if(juntas == N)
        return 1;
    else
        return 0;
}

int ganoRenglon(Juego *juego, int N, int jugador){

    return 1;
}

int ganoDiagonalDerecha(Juego *juego, int N, int jugador){

    return 1;
}

int ganoDiagonalIzquierda(Juego *juego, int N, int jugador){

    return 1;
}

void printArreglos(Juego * juego){
    int i = 0;
    while (i<juego->turno){
        Movimiento **array = juego->jugador1;
        Movimiento *mov = *(array+i);
        Movimiento **array2 = juego->jugador2;
        Movimiento *mov2 = *(array2+i);
        printf("Movimiento %d Jugador1: R:%d C:%d \n",i,mov->renglon, mov->columna);
        printf("Movimiento %d Jugador2: R:%d C:%d \n",i,mov2->renglon, mov2->columna);
        printf("\n");
        i++;
    }
}




