/*
Actividad 7 - Ej 5 del TP 7 (arreglos) - PromedioNotas
Descripción:
Pasar a C.

Un profesor necesita registrar hasta 200 notas (cuyos valores son entre 1 y 10) de un examen y luego calcular
el promedio. Complete la acción promedioNotas y el cuerpo principal del siguiente algoritmo:

Algoritmo Notas
    Léxico
        Max = 200
        TElem = (1..10)
        TNumeros = arreglo [1..Max] de TElem
        TData = <a ∈ TNumeros, cant ∈ (0..Max)>
        misNotas ∈ TData
        promedio ∈ R

        Acción cargarNotas(resultado: notas ∈ TData)
            Léxico local
            i ∈ Z
            Inicio
            //ingresar cantidad de notas a cargar
            Entrada: notas.cant
                para (i <-- 1, i<=notas.cant, i <-- i+1) hacer
                // obtener cada nota
                Entrada: notas.a[i]
                fpara
        Facción

        Acción promedioNotas(dato: notas E Tdata, resultado: prom E R)
        Léxico local
        i E Z
        suma E R
        Inicio
        suma <-- 0
            para (i <-- 1, i<=notas.cant, i <-- i+1) hacer
                //SUMAR cada nota
                suma <-- suma + notas.a[i]
                fpara
        prom<-- suma/notas.cant
        Facción

    Inicio

    cargarNotas(misNotas)
    promedioNotas(misNotas,promedio)
    salida: promedio

    Fin
*/

#include <stdio.h>

#define MAX 200

typedef struct {
    int a[MAX];
    int cant;
} TData;

TData misNotas;
float promedio;

void cargarNotas(TData *notas) {
    int i;

    // Ingreso la cantidad de notas a cargar
    printf("Ingrese la cantidad de notas a cargar:");
    scanf("%d", &notas->cant);

    // Obtener cada nota
    for (i = 1; i <= notas->cant; i++) {
        
            printf("Ingrese la nota %d (valor entre 1 y 10): ", i );
            scanf("%d", &notas->a[i]);

    }
}

void promedioNotas(TData notas, float *prom) {
    int i;
    float suma = 0;
    float aux;
    
    for (i = 1; i <= notas.cant; i++) {
        // Sumar cada nota
        suma = suma + notas.a[i];
    }

    aux = suma / notas.cant;
    *prom = aux;
}

int main() {
    

    cargarNotas(&misNotas);

    promedioNotas(misNotas, &promedio);

    printf("El promedio de las notas es: %.2f\n", promedio);
    

    return 0;
}

/*
pruebas
:\ICyP-3410-2024\Trabajos>.\"activ7ej5tp7promedionotas.exe"

Ingrese la cantidad de notas a cargar:3
Ingrese la nota 1 (valor entre 1 y 10): 10
Ingrese la nota 2 (valor entre 1 y 10): 5
Ingrese la nota 3 (valor entre 1 y 10): 7
El promedio de las notas es: 7.33

D:\ICyP-3410-2024\Trabajos>.\"activ7ej5tp7promedionotas.exe"

Ingrese la cantidad de notas a cargar:5
Ingrese la nota 1 (valor entre 1 y 10): 10
Ingrese la nota 2 (valor entre 1 y 10): 9
Ingrese la nota 3 (valor entre 1 y 10): 8
Ingrese la nota 4 (valor entre 1 y 10): 8
Ingrese la nota 5 (valor entre 1 y 10): 4
El promedio de las notas es: 7.80

D:\ICyP-3410-2024\Trabajos>
*/