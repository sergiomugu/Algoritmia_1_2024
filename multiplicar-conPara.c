//Ejercicio 8 del TP  N° 4
//Ejemplo de para, en C For

/*Algoritmo tablaDeMultiplicar
    Léxico
    i, nro E Z
    msg1, msg2 E caracter
    Inicio
    Entrada: nro
    msg1 ← “x”
    msg2 ← “=”
    para (i←1, i=<10, i←i+1)
    salida: nro msg1  i  msg2  nro*i
    fpara
Fin
*/

//algoritmo en c

#include <stdio.h>//incluyo la biblioteca standar de entrada y salida

//lexico//

int num, i, mult;
char msg1[40],msg2 [40];

//inicio//

int main() {

    printf("\n Ingrese un numero: "); //ingreso numero de la tabla
    scanf("%d", &num); //guardo en num el numero ingresado %d es para entero o %i
    strcpy(msg1,"*"); //copio en msg1 la cadena "*" el simbolo *
    strcpy(msg2,"="); // copio en msg2 el signo igual =

        for (i = 1; i <= 10; i++){//entro al para con i inicializado en 1 y lo ciclo desde 1 hasta 10 inclusive, i++ incrementa de a uno
            mult = num * i; //guardo en mult el resultado de la multiplicacion de num x lo que vale i en el ciclo
            printf("%d  %s  %d  %s  %d \n", num, msg1, i, msg2, mult); //imprimo en el formato 5 * 1 = 5 , cada ciclo me da una entrada de la tabla
        }
    return 0; //retorno de la funcion main
}

//fin//


/* prueba del codigo con la tabla del 5

Ingrese un numero: 5
5  *  1  =  5
5  *  2  =  10
5  *  3  =  15
5  *  4  =  20
5  *  5  =  25
5  *  6  =  30
5  *  7  =  35
5  *  8  =  40
5  *  9  =  45
5  *  10  =  50

*/