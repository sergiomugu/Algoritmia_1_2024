// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 4 -- Año 2024

// Implementacion en C del Ejercicio 7 del TP 7


/* Ejercicio 7 - Practico 7 -  Para un software de una lotería nos solicitan que proveamos un conjunto de hasta 30 números
enteros comprendidos entre 0 y 999, generados aleatoriamente. Implementa una solución modular que
almacene los números en un arreglo. (Usar un TData adecuado al problema planteado). Los números no
pueden estar repetidos.
Nota: para resolver este ejercicio se asume la existencia de una cierta función llamada random(n). El parámetro
n debe ser un valor entero. Si se pasa un valor n como parámetro, la función devolverá un número entero
pseudoaleatorio en el rango de 0 a n-1. Así por ejemplo random (10) dará por resultado un número entero
comprendido entre 0 y 9. Para obtener números pseudoaleatorios en un intervalo determinado, por ejemplo en
el rango de 3 a 8 inclusive, llame a la función de la siguiente forma: random (6) + 3
*/

/* seudocodigo

Algoritmo Soft_Loteria
lexico
    Max=30
    Telem=(0..999)
    Tnum=arreglo[1..Max] de Telem
    Tdata=<a E Tnum, cant E (0..Max)>
    sorteo E Tdata

    Accion Loteria (resultado: num E Tdata)
        
        Lexico Local
            i,j,aux,bandera E Z
        
        inicio
            i<-- 1
            entrada:num.cant //ingreso la cantidad de numeros a cargar en el arreglo
        
            Mientras i<=num.cant hacer
                aux<--random(1000)
                j<-- 1
                bandera<-- 0

                    mientras j<i hacer //al hacer menor extricto no entra en la primera vez
                        si aux=num.a[j]
                            bandera<--1
                        fsi
                        j<--j+1
                    finMientras

                    si bandera=0 entonces
                        num.a[i]<--aux
                    sino
                        i<--i-1
                    fsi

                i<--i+1
            finMientras
    finAccion

inicio

loteria(sorteo)

salida: sorteo

fin

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 30 //cte

typedef int Telem;
int r;

typedef struct {
    Telem a[Max+1];  // El +1 es para usar índices de 1 a Max
    int cant;
} Tdata;

Tdata sorteo; // Variable global

void Loteria() { //accion loteria
    //lexico local
    int i, j, aux, bandera;

    i = 1;

    printf("Ingrese la cantidad de numeros a cargar en el arreglo: ");
    scanf("%d", &sorteo.cant);

    while (i <= sorteo.cant) {
        aux = rand() % 1000; //genero num aleatorio entre 0 y 1000-1 y lo guardo en aux
        //printf("\n%d ",aux); //agregue esta linea para chequeo del numero generado para controlar
        //la dejo desactivada
        
        j = 1; //inicializo j en 1 para chequear igualdad de elementos
        bandera = 0;  // Inicializa la bandera en 0
        while (j < i) {
            if (aux == sorteo.a[j]) {
                bandera = 1;  // pone en 1 si encuentra un numero repetido
                break; //termina el bucle cuando encuentra el primer elem igual
            }
            j++; //incrementa el j
        }
        //printf("\n%d ",bandera);//chequeo si hay algun repetido imprimiendo la bandera
        //agregue esta linea solo para ver si en el caso de algun repetido, funciona bien el codigo, generando de nuevo un numero
        //la dejo desactivada. se uso solo para chequear funcionamiento correcto
        if (bandera == 0) {
            sorteo.a[i] = aux; //inserta el numero aleatorio en la posicion del indice i
            
        } else {
            i--;  // Repite la iteración actual , esto pasa solo si encontro algun num igual a aux y puso bandera en 1
        }

        i++;//incremento i
    }
}

int main() { //cuerpo principal del algoritmo

    srand(time(0));  // Inicializa la semilla para la generación de números aleatorios

    Loteria(); //invoco a la accion loteria

    // hago una salida de la variable sorteo , imprimiendo los números generados uno por uno recorriendo el arreglo 

    printf("Numeros generados:\n");

    for (r = 1; r <= sorteo.cant; r++) {
        printf("%d ", sorteo.a[r]);
    }
    printf("\n");

    return 0;
}


/* pruebas

D:\ICyP-3410-2024\Trabajos>.\"Ej7P7-Loteria.exe"
Ingrese la cantidad de numeros a cargar en el arreglo: 10
Numeros generados:
457 893 419 784 670 354 180 880 50 171

D:\ICyP-3410-2024\Trabajos>.\"Ej7P7-Loteria.exe"
Ingrese la cantidad de numeros a cargar en el arreglo: 15
Numeros generados:
512 8 198 644 409 572 324 652 835 958 213 740 562 516 656

D:\ICyP-3410-2024\Trabajos>.\"Ej7P7-Loteria.exe"
Ingrese la cantidad de numeros a cargar en el arreglo: 12
Numeros generados:
535 711 175 247 75 291 343 161 112 690 177 49

*/