/*
un sistema de codificacion trabaja con la siguiente metodologia para obtener un codigo de seguridad:
- dada una frase que contiene entre 15 y 20 caracteres, se produce un filtrado en ella , generando una nueva
frase codificada, formada unicamente por las vocalesy en orden inversoal que se encontraban inicialmente en
la frase. Esa nueva frase sera informadamediante un mensaje como codigo de seguridad.
- modele adecuadamente la representacion de esta informacion utilizando arreglos unidimensionales.
- desarrolle una accion que reciba la fraseinicial (debe modelarse como un registro de dos campos, un campo 
con un arreglo y el otro campo con la cantidad de elementos), y construya una frase llamada frasecodigo
(del mismo tipo registro que la fraseinicial)
- asumiendo que la accion de carga de los datos en fraseinicial ya esta implementada (no es necesaria
desarrollarla) y la existencia de una funcion esvocal (que retorna verdadero al ser invocada con un caracter
vocal), escriba el cuerpo principal del algoritmo donde se invocan estas acciones y se informe el resultado.
- ejemplo : si la frase inicial es estudiocomputacion , el resultado en frase codificada seria oiauooiue

algoritmo Codificacion

lexico
    Max=50
    Tarreglo= arreglo [1..Max] de caracter
    Tfrase=<f E Tarreglo, cant E Z>
    fraseInicial E Tfrase
    fraseCodigo E Tfrase
    h E Z

    funcion esVocal (dato:l E caracter)--> logico //encabezado funcion

    accion Codificar (dato: fraseI E Tfrase, resultado: fraseC E Tfrase) //encabezado de accion

inicio

    entrada: fraseIinicial.cant //ingreso el tamaño de la frase
    para (h<--1, h<=fraseIinicial.cant, h<--h+1)
        entrada: fraseInicial.f[h]
    fpara

    codificar(fraseInicial, fraseCodigo)

    salida: mje<--"el codigo de la frase es el siguiente:"
    
    para (h<--1, h<=fraseCodigo.cant, h<--h+1)
        salida: fraseCodigo.f[h]
    fpara

fin

//desarrollo de las funciones y acciones

funcion esVocal // ya definida previamente

accion Codificar (dato: fraseI E Tfrase, resultado: fraseC E Tfrase)
lexico local
i, j E Z
inicio
    si (fraseI.cant<15 o fraseI.cant>20) entonces
        salida: mje<--"el largo de la frase deberia ser entre 15 y 20 caracteres"
    sino
        j<--0
        para (i<--fraseI.cant, fraseI.cant >=1, i<--i-1)
            si esVocal (fraseI.f[i]) entonces
                j<--j+1
                fraseC.f[j]<--fraseI.f[i]
            fsi
        fpara
        fraseC.cant<--j
    fsi
faccion

*/