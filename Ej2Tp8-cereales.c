// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 4 -- Año 2024

// Implementacion en C del Ejercicio 2 del TP 8

/*
Ejercicio 2) Una institución realiza un estudio sobre la producción agrícola en nuestro país, para ello
lleva el registro de los volúmenes anuales de las cosechas de cereales (única cantidad por cada año por
cada cereal) desde el año 1980 hasta la actualidad y tiene contrato para continuar con los estudios hasta
el año 2030. Cada cosecha corresponde a un año y se registra por cada año el número de toneladas
producidas de: soja, maíz, trigo, maní (todo por separado).
Desarrollar un algoritmo que atienda a las siguientes necesidades. Modelar adecuadamente los datos
para que se puedan procesar y responder a las siguientes consultas:
a) Informar promedio anual de toneladas cosechadas a lo largo de la década del 90 de cada tipo de semilla.
b) Informar ¿Cuántos años tuvieron una cosecha de trigo superior al promedio anual de la década del 90.
c) Informar ¿Cuántos años tuvieron una cosecha de maní inferior al promedio anual de la década del 90.
d) ¿Cuál fue el año en el que se produjo el mayor número de toneladas desde el 1980 hasta la actualidad,
considerando la totalidad de los cultivos?
*/
/*
algoritmo cosechas
    
lexico
    ANIO_INICIO=1980
    ANIO_FIN=2030
    anioactual E Z+ // entre 1980 y 2030
    max=51
    Tcereal=<soja E R, maiz E R, trigo E R, mani E R, anio E Z+>
    Tarreglo= arreglo[1...max] de Tcereal
    Tdata= <a E Tarreglo, cant E(0...max)>
    cosechas E Tdata
    contadorTrigo, contadorMani E Z
    i, aux E Z
    suma, mayor E R
    anioRecord E Z+
    sumSoja, sumMaiz, sumTrigo, sumMani E R
    promSojaDec90, promMaizDec90, promTrigoDec90, promManiDec90 E R

inicio
    entrada: anioactual

    //cargar datos de los registros
    i<--1
    aux<--anioinicio
    mientras  aux<anioactual hacer
        entrada: cosechas.a[i].soja  cosechas.a[i].maiz  cosechas.a[i].trigo  cosechas.a[i].mani
        cosechas.a[i].anio <-- aux
        i<--i+1
        aux<--aux+1
    fmientras
    cosechas.cant<--i

    i<--1
    mientras cosechas.a[i].anio <> 1990 hacer //recoorro hasta posicionar i en el anio 1990
        i<--i+1
    fmientras

    sumSoja<--0
    sumMaiz<--0
    sumTrigo<--0
    sumMani<--0
    mientras cosechas.a[i].anio<2000 hacer
        sumSoja<-- sumSoja + cosechas.a[i].soja
        sumMaiz<-- sumMaiz + cosechas.a[i].maiz
        sumTrigo<-- sumTrigo + cosechas.a[i].trigo
        sumMani<-- sumMani + cosechas.a[i].mani
        i<--i+1
    fmientras

    promSojaDec90<-- sumSoja/10
    promMaizDec90<-- sumMaiz/10
    promTrigoDec90<-- sumTrigo/10
    promManiDec90<-- sumMani/10
    mje<-- "promedio anual de Soja, Maiz, Trigo y Mani de la decada del 90 en toneladas:"
    salida: mje promSojaDec90 promMaizDec90 promTrigoDec90 promManiDec90

    i<--1
    contadorTrigo<--0
    contadorMani<--0
    mayor<--0
    mientras i<=cosechas.cant hacer

        si cosechas.a[i].trigo>promTrigoDec90
            contadorTrigo<--contadorTrigo + 1
        fsi
        si cosechas.a[i].mani<promManiDec90
            contadorMani<--contadorMani + 1
        fsi

        suma<--cosechas.a[i].soja+cosechas.a[i].maiz+cosechas.a[i].trigo+cosechas.a[i].mani
        si suma>mayor
            mayor<--suma
            anioRecord<--cosechas.a[i].anio
        fsi

        i<--i+1
        
    fmientras
    
    mje<--"cantidad de anios que la cosecha de trigo fue mayor al promedio anual de la decada del 90 "
    salida: mje contadorTrigo

    mje<--"cantidad de anios que la cosecha de mani fue menor al promedio anual de la decada del 90 "
    salida: mje contadorMani

    mje<--"anio record de cosechas "
    salida: mje anioRecord

fin
*/

#include <stdio.h>

#define ANIO_INICIO 1980
#define ANIO_FIN 2030
#define MAX 51

//defino registro del tipo cereal y agrego campo anio para asociarlo a los cereales cargados
typedef struct {
    double soja;
    double maiz;
    double trigo;
    double mani;
    int anio;
} Tcereal;

//defino un registro tdata, con un arreglo de registros
typedef struct {
    Tcereal a[MAX];
    int cant;
} Tdata;

int main() {
    int anioactual, i, aux, contadorTrigo, contadorMani, anioRecord;
    double suma, mayor;
    double sumSoja, sumMaiz, sumTrigo, sumMani;
    double promSojaDec90, promMaizDec90, promTrigoDec90, promManiDec90;
    Tdata cosechas;

    // Entrada del anio actual
    printf("Ingrese el anio actual entre 1980 y 2030\n");
    scanf("%d", &anioactual);

    // Cargar datos de los registros de cosechas de cereales por anio
    i = 0;
    aux = ANIO_INICIO;
    while (aux < anioactual) {
        printf("Ingrese las toneladas de soja, maiz, trigo y mani para el anio %d: ", aux);
        scanf("%lf %lf %lf %lf", &cosechas.a[i].soja, &cosechas.a[i].maiz, &cosechas.a[i].trigo, &cosechas.a[i].mani);
        cosechas.a[i].anio = aux;
        i++;
        aux++;
    }
    cosechas.cant = i;

    // Calcular promedios de la decada del 90

    i = 0;
    while (cosechas.a[i].anio != 1990) {//recoorro hasta posicionar i en el anio 1990
        i++;
    }

    sumSoja = sumMaiz = sumTrigo = sumMani = 0;
    while (cosechas.a[i].anio < 2000 && i < cosechas.cant) {
        sumSoja += cosechas.a[i].soja;
        sumMaiz += cosechas.a[i].maiz;
        sumTrigo += cosechas.a[i].trigo;
        sumMani += cosechas.a[i].mani;
        i++;
    }

    promSojaDec90 = sumSoja / 10;
    promMaizDec90 = sumMaiz / 10;
    promTrigoDec90 = sumTrigo / 10;
    promManiDec90 = sumMani / 10;

    printf("Promedio anual de soja en la decada del 90: %.2lf toneladas\n", promSojaDec90);
    printf("Promedio anual de maiz en la decada del 90: %.2lf toneladas\n", promMaizDec90);
    printf("Promedio anual de trigo en la decada del 90: %.2lf toneladas\n", promTrigoDec90);
    printf("Promedio anual de mani en la decada del 90: %.2lf toneladas\n", promManiDec90);

    // Calculo cantidad de anios con cosecha superior al promedio en trigo
    //e inferior al promedio en mani y anio record de cosechas
    i = 0;
    contadorTrigo = contadorMani = 0;
    mayor = 0;

    while (i < cosechas.cant) {
        if (cosechas.a[i].trigo > promTrigoDec90) {
            contadorTrigo++;
        }
        if (cosechas.a[i].mani < promManiDec90) {
            contadorMani++;
        }

        suma = cosechas.a[i].soja + cosechas.a[i].maiz + cosechas.a[i].trigo + cosechas.a[i].mani;
        if (suma > mayor) {
            mayor = suma;
            anioRecord = cosechas.a[i].anio;
        }

        i++;
    }

    printf("Cantidad de anios con cosecha de trigo mayor al promedio anual de la decada del 90: %d\n", contadorTrigo);
    printf("Cantidad de anios con cosecha de mani menor al promedio anual de la decada del 90: %d\n", contadorMani);
    printf("Anio record de cosechas: %d\n", anioRecord);

    return 0;
}
/*
.\"Ej2Tp8-cereales.exe"
Ingrese el anio actual entre 1980 y 2030
2000
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1980: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1981: 500 500 500 500
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1982: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1983: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1984: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1985: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1986: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1987: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1988: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1989: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1990: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1991: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1992: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1993: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1994: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1995: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1996: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1997: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1998: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1999: 100 100 100 100
Promedio anual de soja en la decada del 90: 100.00 toneladas
Promedio anual de maiz en la decada del 90: 100.00 toneladas
Promedio anual de trigo en la decada del 90: 100.00 toneladas
Promedio anual de mani en la decada del 90: 100.00 toneladas
Cantidad de anios con cosecha de trigo mayor al promedio anual de la decada del 90: 1
Cantidad de anios con cosecha de mani menor al promedio anual de la decada del 90: 0
Anio record de cosechas: 1981

.\'Ej2Tp8-cereales.exe'
Ingrese el anio actual entre 1980 y 2030
2002
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1980: 100 100 500 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1981: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1982: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1983: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1984: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1985: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1986: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1987: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1988: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1989: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1990: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1991: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1992: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1993: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1994: 100 100 100 100
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1995: 200 200 200 200
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1996: 200 200 200 200
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1997: 200 200 200 200
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1998: 200 200 200 200
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 1999: 200 200 200 200
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 2000: 100 100 100 500
Ingrese las toneladas de soja, maiz, trigo y mani para el anio 2001: 50 50 50 50 
Promedio anual de soja en la decada del 90: 150.00 toneladas
Promedio anual de maiz en la decada del 90: 150.00 toneladas
Promedio anual de trigo en la decada del 90: 150.00 toneladas
Promedio anual de mani en la decada del 90: 150.00 toneladas
Cantidad de anios con cosecha de trigo mayor al promedio anual de la decada del 90: 6
Cantidad de anios con cosecha de mani menor al promedio anual de la decada del 90: 16
Anio record de cosechas: 1980

*/