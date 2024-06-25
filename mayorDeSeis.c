/* Algoritmo mayorDeSeis

Léxico

     a, b, c, d, e, f   E Real

     mayorNum E Real

     Función Abs(dato xE R) -- > R   // en C deben usar fabs() que está incluida en math.h

    

     Función Mayor(dato x,y E R) -- > R

     inicio

← ((x+y)+abs(x-y))/2

     Ffuncion

Inicio

            Entrada: a b c d e f

            mayorNum ← Mayor(Mayor(Mayor(a,b), Mayor(c,d)), Mayor (e,f))

            Salida: mayorNum

Fin */

#include <stdio.h>
#include <math.h>
//lexico
float a,b,c,d,e,f;
float mayorNum;
float mayor (float x, float y);

//cuerpo principal
int main() {

    printf("Ingrese 6 numeros (enteros o reales)\n");
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    scanf("%f",&d);
    scanf("%f",&e);
    scanf("%f",&f);

    //scanf("%f %f %f %f %f %f", &a, &b, &c, &d, &e, &f); es lo mismo

    mayorNum = mayor (mayor(mayor(a,b), mayor(c,d)), mayor (e,f)); //uso anidado de la funcion mayor

    printf("El mayor numero es %f ",mayorNum);

    return 0;

}

//definicion completa de la funcion mayor 

float mayor (float x, float y){// define la funcion como float (podria ser int para entero)

    float aux;

    aux = ((x+y)+fabs(x-y))/2; //funcion fabs devuelve el valor absoluto de lo que esta entre ()

    return aux;

}

