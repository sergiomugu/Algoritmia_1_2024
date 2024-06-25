//Ejercicio 5 del TP N° 5
//Ejemplo de un Repetir, en C Do While 

/* #include <stdio.h>

//Lexico
int lMes;
int lMesMax;
int lMax;
int lMesMin;
int lMin;
int i;
//inicio
int main(){
    lMin=1000000;
    lMax=0;
    i=1;
    do{
        printf("Ingrese la luvia que corresponde al mes: %d  ", i);
       scanf("%d", &lMes);
       if(lMes>lMax){
           lMax=lMes;
           lMesMax=i;
       }
       if(lMes<lMin){
           lMin=lMes;
           lMesMin=i;
       }
    i=i+1;
    } while(!(i>12));
    printf("El mes que mas llovio es: %d y llovio %d mm", lMesMax, lMax);
    printf("\nEl mes que menos llovio es: %d y llovio %d mm", lMesMin, lMin);    
}*/

//codigo modificado para empates en los registros

#include <stdio.h>

#define NUM_MESES 12

int main() {
    int lMes;
    int lMesMax[NUM_MESES]; // Array para almacenar los meses con mayor lluvia
    int lMax;
    int lMesMin[NUM_MESES]; // Array para almacenar los meses con menor lluvia
    int lMin;
    int i, maxCount, minCount;

    // Inicialización de variables
    lMin = 1000000;
    lMax = 0;
    maxCount = 0;
    minCount = 0;
    i = 1;

    do {
        printf("Ingrese la lluvia que corresponde al mes %d: ", i);
        scanf("%d", &lMes);

        // Actualización para máximos
        if (lMes > lMax) {
            lMax = lMes;
            maxCount = 0; // Reiniciar el contador de meses con mayor lluvia
            lMesMax[maxCount++] = i; // Guardar el mes actual como el primero con mayor lluvia
        } else if (lMes == lMax) {
            lMesMax[maxCount++] = i; // Guardar el mes actual como otro con mayor lluvia
        }

        // Actualización para mínimos
        if (lMes < lMin) {
            lMin = lMes;
            minCount = 0; // Reiniciar el contador de meses con menor lluvia
            lMesMin[minCount++] = i; // Guardar el mes actual como el primero con menor lluvia
        } else if (lMes == lMin) {
            lMesMin[minCount++] = i; // Guardar el mes actual como otro con menor lluvia
        }

        i++;
    } while (i <= NUM_MESES);

    // Imprimir los meses que más llovieron
    printf("El MAYOR registro de lluvia fue en el/los mes/meses: ");
    for (i = 0; i < maxCount; i++) {
        printf("%d ", lMesMax[i]);
    }
    printf("y llovio %d mm\n", lMax);

    // Imprimir los meses que menos llovieron
    printf("El MENOR registro de lluvia fue en el/los mes/meses:  ");
    for (i = 0; i < minCount; i++) {
        printf("%d ", lMesMin[i]);
    }
        if (lMin == 0)
        {
            printf("y NO LLOVIO\n");
        }
        else
        {
            printf("y llovio %d mm\n", lMin);
        }
    
    

    return 0;
}
