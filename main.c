#include <stdio.h>
#include "conectaN.h"
#include "queue.h"

int main() {printf("Prueba de juego!\n");

    Juego *prueba = nuevoJuego(4);

    nuevoMovimiento(prueba,1, 1, 2);
    nuevoMovimiento(prueba,2, 0, 1);

    nuevoMovimiento(prueba,1, 2, 3);
    nuevoMovimiento(prueba,2, 1, 2);

    nuevoMovimiento(prueba,1, 3, 4);
    nuevoMovimiento(prueba,2, 2, 3);

    nuevoMovimiento(prueba,1, 4, 5);
    nuevoMovimiento(prueba,2, 3, 4);

    nuevoMovimiento(prueba,1, 5, 6);
    nuevoMovimiento(prueba,2, 4, 5);

    nuevoMovimiento(prueba,1, 6, 7);
    nuevoMovimiento(prueba,2, 5, 6);

    nuevoMovimiento(prueba,1, 1, 10);
    nuevoMovimiento(prueba,1, 2, 10);
    nuevoMovimiento(prueba,1, 3, 10);
    nuevoMovimiento(prueba,1, 4, 10);



    //printArreglos2(prueba);
    printArreglos(prueba);



    return 0;
}
