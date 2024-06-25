
// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 4 -- Año 2024

// Implementacion en C del Ejercicio 4 del TP 3

#include <stdio.h>

/* léxico */

float kmR; //kilometros recorridos
float montoPagar;

int main() {
    printf("Ingrese los Km recorridos:\n");
    scanf("%f",&kmR);
    if (kmR<=300) {
        montoPagar=kmR*200;
    }
    else
    {
        if (kmR>300 && kmR<=1000) {

            montoPagar=(300*200)+(kmR-300)*75;
        }
        else //si entra en este punto es porque kmR es mayor que 1000
        {
            montoPagar=(300*200)+(700*75)+(kmR-1000)*50;
        }
        
    }
    
    printf("el monto a pagar por recorrer %.2f km, es de: %.2f pesos\n", kmR, montoPagar);
    
    printf("Presione Enter para continuar...");
    getchar(); // Espera a que el usuario presione Enter para continuar
    getchar(); // se pone doble para evitar que tome el buffer del teclado

return 0;
}
