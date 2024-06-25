#include <stdio.h>
#include <string.h>

int edad; //var para almacenar la edad a analizar

char madurez[30]; // variable para informar el resultado

int main(){

  printf ("\n Ingrese la edad ");

  scanf ("%d", &edad);

  if (edad>0 && edad<=11){

    strcpy(madurez,"el ciudadano es niña/o");

  } 

  else if (edad>=12 && edad<=17){

          strcpy(madurez,"el ciudadano es adolescente");

       } 

       else if (edad>=18 && edad<=49){

                strcpy(madurez,"el ciudadano es adulto");

            } 

            else {

                    strcpy(madurez,"el ciudadano es adulto mayor");

             }

   printf("Entonces %s \n",madurez);

return 0;
}

