#include <stdio.h>
#include "conectaN.h"
#include "queue.h"

int main() {
    printf("Prueba de juego!\n");

    Juego *prueba = nuevoJuego(3);

    nuevoMovimiento(prueba,1, 1, 5);
    nuevoMovimiento(prueba,2, 1, 10);

    nuevoMovimiento(prueba,1, 2, 5);
    nuevoMovimiento(prueba,2, 2, 10);

    nuevoMovimiento(prueba,1, 3, 5);
    nuevoMovimiento(prueba,2, 3, 10);


    printArreglos(prueba);


    return 0;
}
