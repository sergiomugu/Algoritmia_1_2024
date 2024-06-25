// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 4 -- Año 2024

// Implementacion en C del Ejercicio 10 del TP 4

#include <stdio.h>
#include <math.h>
#include <string.h>

/* lexico */

int n;
int i;
int aux;
char mje[40];
char respuesta;

int main() {

    
    do
    {

    /*entradas*/

    i=2; //inicializo variables auxiliares i y aux
    aux=1;

    printf("Ingrese un Numero para chequear si es primo:\n");
    scanf("%d",&n);

    /*calculos*/

    if (((n % 2 == 0)  && (n!=2)) || (n<=1))//chequeo si n es par y distinto de 2 entonces no es primo, lo mismo si es menor o igual a 1
    {
        strcpy(mje, "El numero NO ES PRIMO");
    }
    else
    {
        if (n==2)
        {
            strcpy(mje, "El numero ES PRIMO");
        }
        else
        {
            while (aux!=0 && i<=sqrt(n)) // mientras no encuentre un divisor i para n y mientras i sea menor o igual a la raiz de n, va a seguir entrando al ciclo
            {
                aux=(n % i);
                i=i+1;
            } // se paso el ciclo "repetir" del seudocodigo a un equivalente usando "mientras"

            if (aux==0) // chequea si encontro algun divisor en el ciclo
            {
                strcpy(mje, "El numero NO ES PRIMO");
            }
            else
            {
                strcpy(mje, "El numero ES PRIMO");
            }
        
        }
            
    }
    /*salidas*/

    printf("%s\n",mje); //mje que informa si es o no un numero primo

    printf("Desea ingresar otro numero? (s/n): ");
        scanf(" %c", &respuesta); // Espacio antes de %c para ignorar el salto de línea
        
    } while (respuesta == 's' || respuesta == 'S'); //se inserta este ciclo para repetir el programa hasta que el usuario decida salir

return 0;
}

/*
*** SEUDOCODIGO ***

Algoritmo Primo

    lexico
    n E N
    aux, i E Z+
    mje E cadena

    inicio
    
    aux<--1
    i<--2
    
    entrada: n
    
    si (n MOD 2 = 0 y n<>2) o (n<=1) entonces
        mje<-- "NO es primo"
    sino
        si n=2 entonces
            mje<--"es primo"
        sino
            repetir
                aux <-- n MOD i
                i <--i+1
            hasta que aux=0 o i>raiz(n)

            si aux=0 entonces
                mje<-- "NO es primo"
            sino
                mje<--"es primo"
            fsi
        fsi
    fsi

    salida: mje
fin

Notas sobre las pruebas:

Se realizo pruebas para valores negativos, cero, 1 , 2 , 3, 7, 12, 19 y otros
dando todos ellos resultados correctos

En las primeras pruebas algunos numeros negativos me daban que eran primos, se soluciono
agregando en la condicion del primer Si el menor o igual a 1 (**si (n MOD 2 = 0 y n<>2) o (n<=1) **)
de esta forma quedan excluidos de ser primo todos los pares (menos el 2), el 1, el cero y todos los num negativos.

*/
