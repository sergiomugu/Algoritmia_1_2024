//Ejercicio:  Mostrar por salida los números comprendidos entre dos números dados (el primero debe ser menor que el segundo)
//Ejemplo de uso de un MIentras (While  en C)


#include <stdio.h>

int main () {
    int x, y;
    int i;
    printf("Ingrese un numero.\n");
    scanf("%i",&x);
    printf("Ingrese otro numero mayor que el anterior.\n");
    scanf("%i",&y);
    if (y>x){
        // Bucle While - Mientras
        i=x+1;
        printf("\nlos numeros comprendidos entre los dos ingresados son:\n");
        while (i < y){
            printf(" %i\n",i);
            i=i+1;
            }
    }
    
    else {
        printf("El segundo numero no es mayor que el primero\n");
    } 

    system("pause"); //si esta linea no anda en tu compilador borrala
    return 0;
}