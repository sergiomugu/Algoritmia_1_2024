#include <stdio.h>
#include <stdlib.h>
#include "sortear.h"
#include <time.h>

time_t t;  // Variable usada por la función rand()

void Sortear(TData *nums) {
    // Implementación de la función Sortear
    // Solicitar la cantidad de numeros y asegurar que sea un entero entre 0 y 30
    do {
        printf("Ingrese la cantidad de numeros (máximo %d): ", MAX);
        scanf("%d", &nums->cant);
    } while (nums->cant < 0 || nums->cant > MAX);

    srand((unsigned) time(&t));  // Establece la semilla de la función rand()

    for (int i = 0; i < nums->cant; i++) {
        int numero;
        do {
            numero = rand() % ALEATORIO; // Genera números aleatorios del 0 al 999
        } while (numeroRepetido(numero, *nums, i));

        nums->arr[i] = numero;
    }
}


int numeroRepetido(int numero, TData nums, int posicion) {
    // Implementación de la función numeroRepetido
    for (int i = 0; i < posicion; i++) {
        if (nums.arr[i] == numero) {
            return 1;
        }
    }
    return 0;
}