/*
Ejercicio 8) Una tienda cuenta con la promoción de un descuento del 30% en la tercera unidad de
cortinas si todas son de la misma tela. Una cortina está definida por tela y precio. Definir el tipo
Tcortina. Desarrollar la acción Oferta que toma tres cortinas e indica si aplica o no el descuento y
calcula el precio final.

Actividad 6 - Acciones - Ej8TP6 - Descuento Cortinas

Pasar a C el ejercicio.

Algoritmo descuento
Lexico
    TCortina =< tela ϵ cadena, precio ϵ R>
    cortina1,cortina2,cortina3 ϵ TCortina
    precioFinal ϵ R
    
    Acción Oferta (dato a,b,c ϵ TCortina, resultado p ϵ R)
    Lexico local
    d ϵ R
    msg, msg1 ϵ Cadena
    Inicio
    Si (a.tela = b.tela Y b.tela = c.tela) entonces //las telas son iguales, aplica el descuento
    msg <-- “Se aplica descuento del 30 en el valor de la tercera unidad”
    d <-- c.precio * 0.30;
    p <-- a.precio + b.precio + (c.precio - d)
    msg1 <-- "el precio de la 3ra unidad es”
    Salida: msg msg1 c.precio -d
    sino
    msg <-- "Las telas no son iguales, no se aplica ningun descuento”
    p <-- a.precio + b.precio + c.precio;
    Salida: msg
    fsi
    FAccion

Inicio // Algoritmo

    Entrada: cortina1, cortina2, cortina3
    Oferta(cortina1, cortina2, cortina3, precioFinal)
    Salida: precioFinal

Fin */

#include <stdio.h>
#include <string.h>

typedef struct {
    char tela[40];
    float precio;
} TCortina; //defino el tipo cortina

TCortina cortina1, cortina2, cortina3;
float pFinal;

float Oferta(TCortina a, TCortina b, TCortina c) { //accion Oferta que devuelve un real (opcion sin usar punteros)
    //lexico local
    float d; //variable para llevar el descuento
    char msg[100], msg1[100];
    float precioFinal;
    //inicio de accion oferta
    if (strcmp(a.tela, b.tela) == 0 && strcmp(b.tela, c.tela) == 0) {//para comparar cadenas se uso la funcion strcmp  de la libreria string.h
        // Las telas son iguales, se aplica el descuento
        strcpy(msg, "Las telas son iguales, Se aplica descuento del 30% en el valor de la tercera unidad");
        d = c.precio * 0.30;
        precioFinal = a.precio + b.precio + (c.precio - d);
        strcpy(msg1, "El precio de la 3ra unidad es");
        printf("%s\n", msg);
        printf("%s %.2f\n", msg1, c.precio - d);
    } else {
        // Las telas no son iguales, no se aplica ningun descuento
        strcpy(msg, "Las telas no son iguales, no se aplica ningun descuento");
        precioFinal = a.precio + b.precio + c.precio;
        printf("%s\n", msg);
    }

    return precioFinal;
    //fin accion oferta
}

int main() {
    
    // Entrada de datos
    printf("Ingrese la tela y el precio de la cortina 1:\n");
    scanf("%s %f", cortina1.tela, &cortina1.precio);//en c las variables del tipo cadena no llevan el &

    printf("Ingrese la tela y el precio de la cortina 2:\n");
    scanf("%s %f", cortina2.tela, &cortina2.precio);

    printf("Ingrese la tela y el precio de la cortina 3:\n");
    scanf("%s %f", cortina3.tela, &cortina3.precio);

    // invocacion a la accion Oferta
    pFinal = Oferta(cortina1, cortina2, cortina3);

    // Salida del precio final
    printf("El precio final es: %.2f\n", pFinal);

    return 0;
}

/*
pruebas:

d:\ICyP-3410-2024\Trabajos>.\"actividad7ej8tp6cortinas.exe"
Ingrese la tela y el precio de la cortina 1:
seda
100
Ingrese la tela y el precio de la cortina 2:
seda
150
Ingrese la tela y el precio de la cortina 3:
seda 200
Se aplica descuento del 30% en el valor de la tercera unidad
El precio de la 3ra unidad es 140.00
El precio final es: 390.00

d:\ICyP-3410-2024\Trabajos>.\"actividad7ej8tp6cortinas.exe"
Ingrese la tela y el precio de la cortina 1:
seda
100
Ingrese la tela y el precio de la cortina 2:
seda 150
Ingrese la tela y el precio de la cortina 3:
poliester
120
Las telas no son iguales, no se aplica ningun descuento
El precio final es: 370.00

d:\ICyP-3410-2024\Trabajos>
*/