// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 4 -- Año 2024

// Implementacion en C del Ejercicio 7 del TP 8

/*
Ejercicio 7) Sopa de letras: Dada una Matriz de [n x m] caracteres y un Arreglo de l caracteres, con l
<=n y l<=m, determinar si la palabra que forma el arreglo está presente en la matriz al menos una vez,
de forma vertical u horizontal (cabe destacar que a diferencia de la sopa de letra original, no debe
considerar que la palabra pueda estar en forma diagonal o al revés). Se debe informar entre qué
posiciones está la palabra, si es que está.
*/
/*
SEUDOCODIGO

Algoritmo sopaLetras

lexico
fil=n
col=m
l E Z
Tmatriz = arreglo (1..fil, 1..col) de caracter
Tdata = <k E Tmatriz, cantfil(0..fil), cantcol(0..col)>
sopa E Tdata
Tarreglo = arreglo(1..l) de caracter
a E Tarreglo
i,j,h,b,aux,aux1 E Z

inicio

mje<-- "ingrese el tamanio de la matriz, filas y columnas"
salida: mje
entrada: n
entrada: m

sopa.cantfil<--n
sopa.cantcol<--m
// en c hago el ingreso de cada elemento de la matriz nxm

mje<-- "ingrese el tamanio del vector - cantidad de letras de la palabra a buscar"
salida: mje
entrada: l
//en c puedo ingresar la palabra y usar una funcion que me devuelva el largo de la misma

para (i<--1, i<=sopa.canfil, i<--i+1) hacer
    para (j<--1, j<=sopa.cancol, j<--i+1) hacer
        
        si a[1]=sopa.k[i,j] entonces //busca la coincidencia de la primer letra
            si j<=(sopa.cantcol-l+1) entonces // chequeo si la palabra entra hacia la derecha en la fila
                
                aux<--j
                h<--1
                mientras (h<=l y a[h]=sopa.k[i,aux]) hacer
                h<--h+1
                aux<--aux+1
                fmientras
            fsi

            si i<=(sopa.cantfil-l+1) entonces // chequeo si la palabra entra hacia abajo en la columna

                aux1<--i
                b<--1
                mientras (b<=l y a[b]=sopa.k[aux1,j]) hacer
                b<--b+1
                aux1<--aux1+1
                fmientras
            fsi

            si h>l entonces
                salida: "la palabra esta desde la posicion" i "," j " hasta la posicion" i "," aux-1

                i<--sopa.cantfil+1 //fuerzo la salida de los dos PARA llevando i y j a un valor superior (EN C  USO RETURN 0)
                j<--sopa.cantcol+1
            fsi

            si b>l entonces
                salida: "la palabra esta desde la posicion" i "," j " hasta la posicion" j "," aux1-1

                i<--sopa.cantfil+1 //fuerzo la salida de los dos PARA llevando i y j a un valor superior (EN C  USO RETURN 0)
                j<--sopa.cantcol+1
            fsi
            
        fsi
    fpara
fpara

si h<l y b<l entonces
    salida: mje<--"palabra no encontrada"
fsi

fin
*/


#include <stdio.h>
#include <string.h>

#define MAX 20

typedef struct {
    char k[MAX][MAX];
    int cantfil;
    int cantcol;
} Tdata;

int n, m, l, i, j, h, b, aux, aux1;
Tdata sopa;
char a[MAX];


int main() {
    
    // Ingreso el tamanio (numero de filas y columnas) de la matriz de la sopa de letras
    printf("Ingrese el numero de filas de la matriz de la sopa de letras: ");
    scanf("%d", &n);
    printf("Ingrese el numero de columnas de la matriz de la sopa de letras: ");
    scanf("%d", &m);

    sopa.cantfil = n;
    sopa.cantcol = m;
    
    // Ingreso la palabra a buscar
    printf("Ingrese la palabra a buscar\n");
    scanf("%s", a);
    
    // chequeo la longitud de la palabra y se lo asigno a la variable l
    l = strlen(a);
        
        // Imprimo la palabra ingresada y su longitud solo para chequeo
            printf("Palabra ingresada: %s\n", a);
            printf("Longitud de la palabra: %d\n", l);
            


    //ingreso los elementos de la matriz bidimensional
    
    printf("Ingrese la sopa de letras\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf(" %c", &sopa.k[i][j]);
        }
    }

    // Imprimo la matriz para verificar que la carga sea correcta
            printf("Matriz ingresada:\n");
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    printf("%c ", sopa.k[i][j]);
                }
                printf("\n");
            }

    for (i = 0; i < sopa.cantfil; i++) { //recorro la matriz
        for (j = 0; j < sopa.cantcol; j++) {
            if (a[0] == sopa.k[i][j]) { // Busco la coincidencia de cada elemto con la primer letra de la palabra
                
                if (j <= (sopa.cantcol - l+1)) { // Chequeo si la palabra entra en la fila
                    
                    aux = j;
                    h=0; //indice que uso para recorrer la palabra
                    while (h < l && a[h] == sopa.k[i][aux]) { //chequeo una a una cada letra y su coincidencia
                        h++;
                        aux++; //aumento de a uno el valor de aux para moverme en las columnas hacia la derecha
                    }
                }

                if (i <= (sopa.cantfil - l+1)) { // Chequeo si la palabra entra en la columna
                    
                    aux1 = i;
                    b=0; //indice que uso para recorrer la palabra
                    while (b < l && a[b] == sopa.k[aux1][j]) { //chequeo una a una cada letra y su coincidencia
                        b++;
                        aux1++;//aumento de a uno el valor de aux1 para moverme en las filas hacia abajo
                    }
                }

                if (h == l) { //si se cumple esta igualdad es porque el chequeo en horizontal fue coincidente en cada letra de la palabra
                    printf("La palabra se encontro en horizontal desde la posicion [%d, %d] hasta la posicion [%d, %d]\n", i+1, j+1, i+1, aux);
                    return 0; // Fuerzo la salida porque ya encontro una palabra
                }    //En el contexto de este código, return 0,  se usa para
                     // salir del programa cuando se encuentra la palabra buscada
                     // en la sopa de letras, evitando así la ejecución innecesaria de más código.

                if (b == l) { //si se cumple esta igualdad es porque el chequeo en vertical fue coincidente en cada letra de la palabra
                    printf("La palabra se encontro en vertical desde la posicion [%d, %d] hasta la posicion [%d, %d]\n", i+1, j+1, aux1, j+1);
                    return 0; // Fuerzo la salida porque ya encontro una palabra
                }
            }
        }
    }

    if (h < l && b < l) {
        printf("Palabra no encontrada en la sopa de letras\n");
    }

    return 0;
}
/*
ALGUNAS PRUEBAS REALIZADAS

D:\ICyP-3410-2024\Trabajos>.\"Ej7Pr8-sopaLetras.exe"
Ingrese el numero de filas de la matriz de la sopa de letras: 5
Ingrese el numero de columnas de la matriz de la sopa de letras: 7
Ingrese la palabra a buscar
alas
Palabra ingresada: alas
Longitud de la palabra: 4
Ingrese la sopa de letras
j u a n c i t
a l e r a l r
a a a a l a s
j u a n c i t
r o b e r t o
Matriz ingresada:
j u a n c i t
a l e r a l r
a a a a l a s
j u a n c i t
r o b e r t o
La palabra se encontro en horizontal desde la posicion [3, 4] hasta la posicion [3, 7]

D:\ICyP-3410-2024\Trabajos>.\"Ej7Pr8-sopaLetras.exe"
Ingrese el numero de filas de la matriz de la sopa de letras: 7
Ingrese el numero de columnas de la matriz de la sopa de letras: 7
Ingrese la palabra a buscar
futbol
Palabra ingresada: futbol
Longitud de la palabra: 6
Ingrese la sopa de letras
a a a a a a a
a a a f u t b
a a a a f u t
a f u t b o l
f u t b o o o
a a a a a a a
a a a a a a a
Matriz ingresada:
a a a a a a a
a a a f u t b
a a a a f u t
a f u t b o l
f u t b o o o
a a a a a a a
a a a a a a a
La palabra se encontro en horizontal desde la posicion [4, 2] hasta la posicion [4, 7]

D:\ICyP-3410-2024\Trabajos>.\"Ej7Pr8-sopaLetras.exe"
Ingrese el numero de filas de la matriz de la sopa de letras: 5
Ingrese el numero de columnas de la matriz de la sopa de letras: 5
Ingrese la palabra a buscar
juan
Palabra ingresada: juan
Longitud de la palabra: 4
Ingrese la sopa de letras
a j u a l
a u a a a
a a a a a
j n j j j
a a a a a
Matriz ingresada:
a j u a l
a u a a a
a a a a a
j n j j j
a a a a a
La palabra se encontro en vertical desde la posicion [1, 2] hasta la posicion [4, 2]

*/