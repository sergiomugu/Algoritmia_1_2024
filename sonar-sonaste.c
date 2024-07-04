/*
Algoritmo sonaste
lÃ©xico
  TCancion = <duracion E R, nombre E cadena, autor, cantRepro E N >
  tema1, tema2, msj E Cadena
  cantidadTemas E N
  hayTemaLargo E Logico

  ACCION MasReproducciones (dato cant E N, resultado t1 E Cadena, t2 E Cadena, temaLargo E Logico)
	LEXICO LOCAL
		i E Z
		cancion1, cancion2, cancionActual E TCancion
		mensaje E Cadena
	INICIO
		temaLargo â† Falso
        cancion1.cantRepro  â† 0 //serÃ¡ la de mayor cantidad de reproducciones
        cancion2.cantRepro â† 0 // serÃ¡ la segunda mÃ¡s escuchada
        PARA (iâ†1, i<cant, iâ† i + 1) HACER
	        mensaje â†â€Ingrese los datos de una cancion (duracion en segundos, nombre del tema, autor y reproducciones)â€
	        Salida mensaje
            Entrada cancionActual.duracion cancionActual.nombre cancionActual.autor cancionActual.cantRepro 
	
	        SI (cancionActual.cantRepro > cancion1.cantRepro) ENTONCES 
		        //LA CANCION ACTUAL ES MÃS ESCUCHADA QUE LAS DOS MÃS ESCUCHADAS HASTA EL MOMENTO
		        cancion2 â† cancion1	
                cancion1 â† cancionActual
            SINO 	
	            SI (cancionActual.cantRepro > cancion2.cantRepro) ENTONCES
                    //LA CANCION ACTUAL ES LA SEGUNDA MÃS ESCUCHADA HASTA EL MOMENTO
			        cancion2 â† cancionActual
                FSI
	        FSI
	
	        mensaje â†â€El nombre del tema actual y su autor son:â€
	        Salida mensaje cancionActual.nombre cancionActual.autor

	        SI (cancionActual.duracion > (60 * 8)) ENTONCES
		        temaLargo â† Verdadero
  	        FSI
        FPARA

    t1 â† cancion1.nombre
    t2 â† cancion2.nombre
FACCION

INICIO
	msj â† â€œIngrese la cantidad de canciones a analizarâ€
    REPETIR 
	    Salida msj
        Entrada cantidadTemas
    HASTA QUE (cantidadTemas >= 2)

    MasReproducciones (cantidadTemas, tema1, tema2, hayTemaLargo)
    msj â† â€œLos temas mÃ¡s escuchados son: â€
    Salida msj tema1 tema2
FIN

*/

#include <stdio.h>
#include <string.h>

typedef struct {
    float duracion;
    char nombre[50];
    char autor[50];
    int cantRepro;
} TCancion;

void MasReproducciones(int cant, char t1[], char t2[], int temaLargo) {
    int i;
    TCancion cancion1, cancion2, cancionActual;
    char mensaje[100];

    temaLargo = 0;
    cancion1.cantRepro = 0;
    cancion2.cantRepro = 0;

    for (i = 1; i <= cant; i++) {
        printf("Ingrese los datos de una cancion (duracion en segundos, nombre del tema, autor y reproducciones): \n");        

        printf("Ingrese la duracion en segundos: ");
        scanf("%f", &cancionActual.duracion);

        printf("Ingrese el nombre del tema: ");
        scanf("%s", cancionActual.nombre);

        printf("Ingrese el autor: ");
        scanf("%s", cancionActual.autor);

        printf("Ingrese la cantidad de reproducciones: ");
        scanf("%d", &cancionActual.cantRepro);

        if (cancionActual.cantRepro > cancion1.cantRepro) {
            cancion2 = cancion1;
            cancion1 = cancionActual;
        } else {
            if (cancionActual.cantRepro > cancion2.cantRepro) {
                cancion2 = cancionActual;
            }
        }

        printf("El nombre del tema actual y su autor son: %s %s\n", cancionActual.nombre, cancionActual.autor);

        if (cancionActual.duracion > (60 * 8)) {
            temaLargo = 1;
            printf("El tema actual es LARGO!!!!!n %f", cancionActual.duracion);
        }
    }

    strcpy(t1, cancion1.nombre);
    strcpy(t2, cancion2.nombre);
}

int main() {
    int cantidadTemas;
    char tema1[50], tema2[50];
    int hayTemaLargo = 0;
    char msj[100];

    do {
        printf("Ingrese la cantidad de canciones a analizar: ");
        scanf("%d", &cantidadTemas);
    } while (cantidadTemas < 2);

    MasReproducciones(cantidadTemas, tema1, tema2, hayTemaLargo);

    printf("Los temas mÃ¡s escuchados son: %s %s\n", tema1, tema2);

    return 0;
}

/*
PRUEBAS
subir a github
se realizo push --force
*/