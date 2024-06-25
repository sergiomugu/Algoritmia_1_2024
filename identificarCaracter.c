//Modificar el programa IdentificarCaracter.c dado en la teoría 5 de funciones
//(publicado en EVELIA en Teo_05/ejemplos  IdentificarCaracter.c ), de manera
// que informe si el caracter dado "es una vocal", o "es una consonante" o "no es una letra"
//Entregar código fuente (archivo .c) previamente compilar
//y probar (dejar en el código fuente los datos de la prueba comentados).

#include <stdio.h>

char letra;
int esMayuscula3(char c);
char aMinuscula(char c);
int esVocal(char c);
int esLetra(char c);
char respuesta;

int main(){

    do
    {
        printf("\n Ingrese caracter: ");
        scanf("%c",&letra);
        
        if (esLetra(letra)){
            if (esVocal(letra)){
                printf("\n El caracter ingresado (%c) es una vocal", letra);
            }
            else
            {
                printf("\n El caracter ingresado (%c) es una consonante", letra);
            }
          } 
        else{
            printf("\n El caracter ingresado (%c) NO es una letra", letra);
        }
        
      printf("\n\n Desea ingresar otro Carecter? (s/n): ");
              scanf(" %c", &respuesta); // Espacio antes de %c para ignorar el salto de línea
              getchar(); // Espera a que el usuario presione Enter para continuar
                      
    } while (respuesta == 's' || respuesta == 'S'); //se inserta este ciclo para repetir el programa hasta que el usuario decida salir

return 0;
}
// fin del main

// implementacion completa de cada una funcion mencionada en el lexico global.

int esMayuscula3(char c){
  return ((c >= 'A') && (c <= 'Z'));
}
char aMinuscula(char c){
  return (c + ('a'-'A'));
}

int esVocal(char c){
  char minus;
      if (esMayuscula3(c)){
      minus = aMinuscula(c);
      } 
      else{
          minus = c;
      }
      return ((minus == 'a') || (minus == 'e') || (minus == 'i') || (minus == 'o') || (minus == 'u')); 
}

int esLetra(char c){
  return (((c >= 'A') && (c <= 'Z'))||((c >= 'a') && (c <= 'z')));
}

/*
d:\ICyP-3410-2024\Trabajos>.\"identificarCaracter.exe"

Ingrese caracter: A

El caracter ingresado (A) es una vocal

Desea ingresar otro Carecter? (s/n): S

Ingrese caracter: u

El caracter ingresado (u) es una vocal

Desea ingresar otro Carecter? (s/n): s

Ingrese caracter: 8

El caracter ingresado (8) NO es una letra

Desea ingresar otro Carecter? (s/n): s

Ingrese caracter: w

El caracter ingresado (w) es una consonante

Desea ingresar otro Carecter? (s/n): s

Ingrese caracter: /

El caracter ingresado (/) NO es una letra

Desea ingresar otro Carecter? (s/n): s

Ingrese caracter: p

El caracter ingresado (p) es una consonante

Desea ingresar otro Carecter? (s/n): n

d:\ICyP-3410-2024\Trabajos> */
