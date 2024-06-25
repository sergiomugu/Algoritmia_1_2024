// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 4 -- Año 2024

// Implementacion en C del Ejercicio 14 del TP 3

#include <stdio.h>
#include <math.h>   // Incluye la biblioteca matemática

/* lexico */
float px,py;
float cx,cy,r;
float r1x,r1y,r2x,r2y;
float aux;
char mje[70];

int main()
{
    //entradas
    printf("\nPrograma para averiguar si, dadas las coordenadas de un punto, un circulo y un rectangulo, el punto es interno o externo a estas figuras\n\n");
    printf("***Ingresamos las coordenadas del Punto a resolver***\n");
    printf("\ningrese coordenada en x del punto:\n");
    scanf("%f",&px);
    printf("ingrese coordenada en y del punto:\n");
    scanf("%f",&py);

    printf("\n***Ingresamos las coordenadas del centro del Circulo y su radio***\n");
    printf("\ningrese coordenada en x del centro:\n");
    scanf("%f",&cx);
    printf("ingrese coordenada en y del centro:\n");
    scanf("%f",&cy);
    printf("ingrese el radio del circulo:\n");
    scanf("%f",&r);

    printf("\n***Ingresamos las coordenadas de los vertices opuestos del rectangulo***\n");
    printf("\ningrese coordenada en x de Vertice 1:\n");
    scanf("%f",&r1x);
    printf("ingrese coordenada en y de vertice 1:\n");
    scanf("%f",&r1y);
    printf("ingrese coordenada en x de Vertice 2:\n");
    scanf("%f",&r2x);
    printf("ingrese coordenada en y de vertice 2:\n");
    scanf("%f",&r2y);


    //calculos

    aux=sqrt(pow(px-cx,2)+pow(py-cy,2));

    if ((px<=r2x&&px>=r1x)&&(py<=r2y&&py>=r1y)&&(aux<=r))
    {
        strcpy(mje,"Respuesta: el punto esta dentro del circulo y dentro del rectangulo\n");
    }
    else
    {       if (aux<=r)
            {
                strcpy(mje,"Respuesta: el punto esta solo dentro del circulo\n");
            }
            else
            {
                if ((px<=r2x&&px>=r1x)&&(py<=r2y&&py>=r1y))
                {
                    strcpy(mje,"Respuesta: el punto esta solo dentro del rectangulo\n");
                }
                else
                {
                    strcpy(mje,"Respuesta: el punto esta fuera del circulo y fuera del rectangulo\n");
                }
            }
            


    }

    //salidas

    printf("\n%s\n",mje);

    printf("Presione Enter para continuar...");
    getchar(); // Espera a que el usuario presione Enter para continuar
    getchar(); // se pone doble para evitar que tome el buffer del teclado

    return 0;
}

/*
Se realizo pruebas para todas las respuestas posibles y fueron satisfactorias!

Prueba Ejemplo

d:\ICyP-3410-2024\Trabajos>.\"Ej14P3-PuntoCircRectang.exe"

Programa para averiguar si, dadas las coordenadas de un punto, un circulo y un rectangulo, el punto es interno o externo a estas figuras

***Ingresamos las coordenadas del Punto a resolver***

ingrese coordenada en x del punto:
5
ingrese coordenada en y del punto:
0

***Ingresamos las coordenadas del centro del Circulo y su radio***

ingrese coordenada en x del centro:
5
ingrese coordenada en y del centro:
3
ingrese el radio del circulo:
3

***Ingresamos las coordenadas de los vertices opuestos del rectangulo***

ingrese coordenada en x de Vertice 1:
1
ingrese coordenada en y de vertice 1:
1
ingrese coordenada en x de Vertice 2:
10
ingrese coordenada en y de vertice 2:
4

Respuesta: el punto esta solo dentro del circulo

Presione Enter para continuar...

*/