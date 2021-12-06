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
            ganoColumna(juego, juego->N, mov);
            ganoRenglon(juego, juego->N, mov);
            ganoDiagonalDerecha(juego, juego->N, mov);
            ganoDiagonalIzquierda(juego, juego->N, mov);
        }
    } else{
        Movimiento **array = juego->jugador2;
        *(array + juego->turno) = mov;
        queue_offer(juego->cola,mov);
        if(((juego->turno)-1) > juego->N){
            ganoColumna(juego, juego->N, mov);
            ganoRenglon(juego, juego->N, mov);
            ganoDiagonalDerecha(juego, juego->N, mov);
            ganoDiagonalIzquierda(juego, juego->N, mov);
        }
        juego->turno++;
    }


}

int ganoColumna(Juego *juego, int N, Movimiento *mov){
    
    int renglon = mov->renglon;
    int columna = mov->columna;
    int minRenglon = 0;
    int maxRenglon = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxRenglon = renglon - 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minRenglon = renglon + 1;
        //int minRenglon = renglon + 1;
    }else{
        Movimiento **array2 = juego->jugador2;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxRenglon = renglon - 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minRenglon = renglon + 1;
        //int minRenglon = renglon + 1;
    }
    int diferencia = N - 1;
    if((maxRenglon - diferencia) == minRenglon)
        return 1;
    else
        return 0;
}

int ganoRenglon(Juego *juego, int N, Movimiento* mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minColumna = 0;
    int maxColumna = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 1;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna - 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
        //int minRenglon = renglon + 1;
    }else{
        Movimiento **array2 = juego->jugador2;
        while(b == 1) {
            b = 0;
            i = 1;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna - 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
        //int minRenglon = renglon + 1;
    }
    int diferencia = N - 1;
    if((maxColumna - diferencia) == minColumna)
        return 1;
    else
        return 0;
}

int ganoDiagonalDerecha(Juego *juego, int N, Movimiento* mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minColumna = 0;
    int maxColumna = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon++;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna - 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon--;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
        //int minRenglon = renglon + 1;
    }else{
        Movimiento **array2 = juego->jugador2;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon++;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna - 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon--;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna + 1;
        //int minRenglon = renglon + 1;
    }
    int diferencia = N - 1;
    if((maxColumna - diferencia) == minColumna)
        return 1;
    else
        return 0;
}

int ganoDiagonalIzquierda(Juego *juego, int N, Movimiento* mov){

    int renglon = mov->renglon;
    int columna = mov->columna;
    int minColumna = 0;
    int maxColumna = 0;

    int b = 1;
    int i;

    if(mov->jugador == 1) {
        Movimiento **array = juego->jugador1;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon++;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna + 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon--;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array + i))->columna == columna && (*(array + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna - 1;
        //int minRenglon = renglon + 1;
    }else{
        Movimiento **array2 = juego->jugador2;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon++;
            columna--;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        maxColumna = columna + 1;
        //int maxRenglon = renglon - 1;

        b = 1;
        renglon = mov->renglon;
        columna = mov->columna;
        while(b == 1) {
            b = 0;
            i = 1;
            renglon--;
            columna++;
            while (b == 0 && i <= juego->turno) {
                if ((*(array2 + i))->columna == columna && (*(array2 + i))->renglon == renglon)
                    b = 1;
                else
                    i++;
            }
        }
        minColumna = columna - 1;
        //int minRenglon = renglon + 1;
    }
    int diferencia = N - 1;
    if((maxColumna + diferencia) == minColumna)
        return 1;
    else
        return 0;
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


