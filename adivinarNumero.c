/*
probando desde github
Algoritmo juego

lexico
a,b,x,n E N
a<--0
b<--101
res E Z
intentos E N{1..12}
mje E cadena

funcion random (dato: a,b E N)--> N

accion adivinar (dato: ngen, npas, E N, dato-resultado: cantInt E N, resultado: y E Z)

inicio

    cantInt<--cantInt+1
    si ngen <> npas entonces
        y<---1
    sino
        y<--cantInt
    fsi
faccion

inicio

x<--random(a,b)
intentos<--0

repetir
    salida: mje<-- "le quedan la sig cantidad de intentos", (12-intentos)
    entrada: n
    adivinar(x,n,intentos,res) // llamo a la accion adivinar
    si res<>-1 entonces
        si n<x entonces
        salida: mje<--"el numero ingresado es mayor..."
        sino
        salida: mje<--"el numero ingresado es menor..."
        fsi
    fsi
hasta que intentos>12 o res <> -1
si res <>-1 entonces
    salida:mje<--"perfecto, ha adivinado"
sino 
    salida:mje<--"ha llegado  a los 12 intentos sin adivinar"
fsi


fin


*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Necesario para generar números aleatorios

// Definición de funciones y variables globales
int random(int a, int b);
void adivinar(int ngen, int npas, int *cantInt, int *resultado);
const int MAX_INTENTOS = 12;

int main() {
    // Declaración de variables según el algoritmo
    int a = 0, b = 100; // b debe ser 100 para números entre 0 y 100 inclusive
    int x, n, res;
    int intentos = 0;
    char mje[100]; // Cadena de caracteres para mensajes

    // Inicialización del generador de números aleatorios
    srand(time(NULL));

    // Función para generar número aleatorio entre a y b
    x = random(a, b);
    printf("%d",x);
    // Bucle principal del juego
    do {
        printf("Le quedan la siguiente cantidad de intentos: %d\n", MAX_INTENTOS - intentos);
        printf("Ingrese un numero para adivinar: ");
        scanf("%d", &n);

        adivinar(x, n, &intentos, &res);

        if (res == -1) {
            if (n < x) {
                printf("El numero ingresado es menor...\n");
            } else if (n > x) {
                printf("El numero ingresado es mayor...\n");
            }
        }
    } while (intentos < MAX_INTENTOS && res == -1);

    // Mensaje final según el resultado
    if (res != -1) {
        printf("Perfecto, ha adivinado!\n en esta cant de intentos:%d",intentos);
    } else {
        printf("Ha llegado a los 12 intentos sin adivinar.\n");
    }

    return 0;
}

// Función para generar número aleatorio entre a y b (incluyendo a y excluyendo b)
int random(int a, int b) {
    return rand() % (b - a) + a;
}

// Acción para verificar si se adivinó el número
void adivinar(int ngen, int npas, int *cantInt, int *resultado) {
    (*cantInt)++; // Incrementa la cantidad de intentos
    if (ngen == npas) {
        *resultado = cantInt; // Adivinó el número
    } else {
        *resultado = -1; // No adivinó, continuar intentando
    }
}
