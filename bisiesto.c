/* Hacer una función que dado un año, determine si el mismo es bisiesto o no. 
Un año se dice bisiesto si es divisible por 4 pero no por 100. Los años que 
son divisibles por 100 y por 400, también son bisiestos. 
*/

/*

Analisis
dato: anio E Z+
resultado: mje E cadena
relaciones: es bisiesto cuando (anio MOD 4 = 0 y anio MOD 100 <> 0) o (anio MOD 100 = 0 y anio MOD 400 = 0 )


Algoritmo Bisiesto
lexico
    anio E Z+
    mje E cadena

    funcion Bisiesto (dato: a E Z+)--> logico
        inicio
        si (a MOD 4 = 0 y a MOD 100 <> 0) o (a MOD 100 = 0 y a MOD 400 = 0 ) entonces
        <-- verdadero
        sino
        <-- falso
        fsi
    ffuncion

inicio
    entrada: anio
    si (bisiesto(anio)) entonces
        mje<-- "el anio es bisiesto"
    sino
        mje<-- "el anio NO es bisiesto"
    fsi
    salida: mje

fin
*/

//implementacion en C

#include <stdio.h>

// lexico

int anio;
char mje[40];
int bisiesto(int a);

int main() {

    printf("Ingrese el anio a averiguar si es bisiesto\n");
    scanf("%d",&anio);
    
    if (bisiesto(anio))
    {
        strcpy(mje,"El anio es Bisiesto\n");
    }
    else
    {
        strcpy(mje,"El anio NO es Bisiesto\n");
    }
    printf(mje);
}
//funcion es bisiesto, devuelve verdadero o falso

int bisiesto(int a){
    
    if ((a%4 == 0 && a%100 != 0) || (a%100 == 0 && a%400 == 0 ))
    {
        return(1);
    }
    else{
        return (0);
    }
}

