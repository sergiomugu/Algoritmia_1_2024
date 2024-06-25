#include <stdio.h>
#include <stdlib.h>
#include "informar.h"

void InformarNums(TData nums) {
    // Implementación de la función InformarNums
    int cantidad = nums.cant;
    printf("Los numeros generados son:\n");
    // Imprimir los numeros en el arreglo
    for (int i = 0; i < cantidad; i++) {
        int num = nums.arr[i];
        printf("\tEn la posición %d: %d\n", i,num);
    }
}
