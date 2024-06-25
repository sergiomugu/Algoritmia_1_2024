/*
algoritmo Super

lexico

msg, msg1 E cadena
monto_c E R
monto_d E R
compra E R
descuento E R
pagar E R
aux E caracter

inicio

msg <-- "apriete cualquier tecla para cargar un producto, o * para terminar"
salida: msg
entrada: aux
compra<--0

mientras aux <> * hacer
    msg1<--"cargue monto del producto"
    salida: msg1
    entrada: monto_c
    compra<--compra+monto_c
    salida: msg
    entrada: aux
fmientras

msg <-- "apriete cualquier tecla para cargar un cupon de descuento, o * para terminar"
salida: msg
entrada: aux
descuento<--0

mientras aux <> * hacer
    msg1<--"cargue monto del descuento"
    salida: msg1
    entrada: monto_d
    descuento<--descuento+monto_d
    salida: msg
    entrada: aux
fmientras

pagar<--compra-descuento

msg<--"el total a pagar por su compra es:"
salida: msg pagar

fin

*/
#include <stdio.h>

int main() {
    char msg[100], msg1[100], aux;
    double monto_c, monto_d, compra, descuento, pagar;

    // Mensaje inicial
    sprintf(msg, "Apriete una tecla para cargar un producto, o * para terminar");
    printf("%s\n", msg);
    scanf(" %c", &aux); // Leer el primer carácter
    compra = 0;

    // Proceso de carga de productos
    while (aux != '*') {
        sprintf(msg1, "Cargue monto del producto");
        printf("%s\n", msg1);
        scanf("%lf", &monto_c);
        compra += monto_c;
        printf("%s\n", msg);
        scanf(" %c", &aux); // Leer el siguiente carácter
    }

    // Mensaje para cupones de descuento
    sprintf(msg, "Apriete cualquier tecla para cargar un CUPON DE DESCUENTO, o * para terminar");
    printf("%s\n", msg);
    scanf(" %c", &aux); // Leer el primer carácter para descuentos
    descuento = 0;

    // Proceso de carga de cupones de descuento
    while (aux != '*') {
        sprintf(msg1, "Cargue monto del descuento");
        printf("%s\n", msg1);
        scanf("%lf", &monto_d);
        descuento += monto_d;
        printf("%s\n", msg);
        scanf(" %c", &aux); // Leer el siguiente carácter
    }

    // Calcular el total a pagar
    pagar = compra - descuento;

    // Mostrar el total a pagar
    sprintf(msg, "El total a pagar por su compra es:");
    printf("%s %.2lf\n", msg, pagar);

    return 0;
}
