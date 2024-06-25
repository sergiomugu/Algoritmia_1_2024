// Alumno: SERGIO MUGURUZA DNI:24333376 -- Comision 4 -- Año 2024

// Implementacion en C del Ejercicio 7 del TP 3

#include <stdio.h>
#include <string.h>

/* lexico */

int tN1, tN2, tN3; //variables para los tiempos de cada nadador
int Pri, Seg, Ter; // variables para guardar las posiciones
char p[10],s[10],t[10]; //variable que guardara el numero del nadador segun la posicion
char mje[50]="No hubo empates";//variable para guardar mensaje si hubo o no Empates

int main() 
{
    //entradas
	
    printf("Ingrese el tiempo del Nadador Num 1:\n");
    scanf("%d",&tN1);
    printf("Ingrese el tiempo del Nadador Num 2:\n");
    scanf("%d",&tN2);
    printf("Ingrese el tiempo del Nadador Num 3:\n");
    scanf("%d",&tN3);
    
    //calculos

    if (tN1<=tN2 && tN2<=tN3)
    {
        Pri=tN1; Seg=tN2; Ter=tN3;
        strcpy(p, "nadador 1"); strcpy(s, "nadador 2"); strcpy(t, "nadador 3");
        
		// estos proximos If se agregan solo para inofomar si hubo empates entre algun nadador
        if  (tN1==tN2 && tN2==tN3)
        {
            strcpy(mje,"HUBO UN EMPATE entre los 3 nadadores\n");
        }
        if  (tN1==tN2 && tN2<tN3)
        {
            strcpy(mje,"HUBO UN EMPATE entre los nadadores 1 y 2\n");
        }
        if  (tN1<tN2 && tN2==tN3)
        {
            strcpy(mje,"HUBO UN EMPATE entre los nadadores 2 y 3\n");
        }
    }
    else
    {
            if (tN1<=tN3 && tN3<tN2)
            {
                Pri=tN1; Seg=tN3; Ter=tN2;
                strcpy(p, "nadador 1"); strcpy(s, "nadador 3"); strcpy(t, "nadador 2");
				
				// este proximo If se agrega solo para inofomar si hubo empate entre algun nadador
                if  (tN1==tN3 && tN3<tN2)
                {
                    strcpy(mje,"HUBO UN EMPATE entre los nadadores 1 y 3\n");
                }
            }
            else
            {
                    if (tN2<tN1 && tN1<=tN3)
                    {
                        Pri=tN2; Seg=tN1; Ter=tN3;
                        strcpy(p, "nadador 2"); strcpy(s, "nadador 1"); strcpy(t, "nadador 3");
						
						// este proximo If se agrega solo para inofomar si hubo empate entre algun nadador
                        if  (tN2<tN1 && tN1==tN3)
                        {
                            strcpy(mje,"HUBO UN EMPATE entre los nadadores 1 y 3\n");
                        }
                    }
                    else
                    {
                            if (tN2<tN3 && tN3<tN1)
                            {
                                Pri=tN2; Seg=tN3; Ter=tN1;
                                strcpy(p, "nadador 2"); strcpy(s, "nadador 3"); strcpy(t, "nadador 1");
                            }
                            else
                            {
                                    if (tN3<tN1 && tN1<=tN2)
                                    {
                                        Pri=tN3; Seg=tN1; Ter=tN2;
                                        strcpy(p, "nadador 3"); strcpy(s, "nadador 1"); strcpy(t, "nadador 2");
										
										// este proximo If se agrega solo para inofomar si hubo empate entre algun nadador
                                        if  (tN3<tN1 && tN1==tN2)
                                        {
                                            strcpy(mje,"HUBO UN EMPATE entre los nadadores 1 y 2\n");
                                        }
                                    }
                                    else // tN3<tN2 && tN2<tN1 . en este punto entra solo si se cumple esta condicion
                                    {
                                        Pri=tN3; Seg=tN2; Ter=tN1;
                                        strcpy(p, "nadador 3"); strcpy(s, "nadador 2"); strcpy(t, "nadador 1");
                                    }
                            }
                    }
            }
    }
    
    //salidas

    printf("\n****En caso de empates se informan los tiempos en orden de andarivel****\n\n");//mje informativo

    printf("PRIMERO %s con %d seg., SEGUNDO %s con %d seg. y TERCERO %s con %d seg.\n\n",p,Pri,s,Seg,t,Ter);//mje que da las posiciones

    printf("%s\n",mje); //mje que informa si hubo empates o no

    
    printf("Presione Enter para continuar...");
    getchar(); // Espera a que el usuario presione Enter para continuar
    getchar(); // se pone doble para evitar que tome el buffer del teclado

return 0;
}
	//Comentarios de Pruebas

	//se probo compilar en https://www.onlinegdb.com/online_c_compiler y funciono correctamente
	//se probo compilar en Visual Studio Code y funciono correctamente
	//se compilo por consola con gcc y tambien funciono 
	//en todos los casos se realizo varias pruebas con distintos valores y todas devolvieron respuestas correctas
/* 
	Ejemplo de prueba con los sig valores de entradas: 
   
		Ingrese el tiempo del Nadador Num 1:
		25
		Ingrese el tiempo del Nadador Num 2:
		23
		Ingrese el tiempo del Nadador Num 3:
		25
		
		****En caso de empates se informan los tiempos en orden de andarivel****

		PRIMERO nadador 2 con 23 seg., SEGUNDO nadador 1 con 25 seg. y TERCERO nadador 3 con 25 seg.

		HUBO UN EMPATE entre los nadadores 1 y 3

		Presione Enter para continuar...
		
	Otro Ejemplo:
		
		PS D:\ICyP-3410-2024\Trabajos> .\Ej7P3-Nadadores.exe
		Ingrese el tiempo del Nadador Num 1:
		20
		Ingrese el tiempo del Nadador Num 2:
		20
		Ingrese el tiempo del Nadador Num 3:
		25		
		
		****En caso de empates se informan los tiempos en orden de andarivel****

		PRIMERO nadador 1 con 20 seg., SEGUNDO nadador 2 con 20 seg. y TERCERO nadador 3 con 25 seg.

		HUBO UN EMPATE entre los nadadores 1 y 2

		Presione Enter para continuar...
		
	Otro Ejemplo:
	
		PS D:\ICyP-3410-2024\Trabajos> .\Ej7P3-Nadadores.exe
		Ingrese el tiempo del Nadador Num 1:
		33
		Ingrese el tiempo del Nadador Num 2:
		35
		Ingrese el tiempo del Nadador Num 3:
		34

		****En caso de empates se informan los tiempos en orden de andarivel****

		PRIMERO nadador 1 con 33 seg., SEGUNDO nadador 3 con 34 seg. y TERCERO nadador 2 con 35 seg.

		No hubo empates
		
		Presione Enter para continuar...

 */  