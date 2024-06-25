Algoritmo fibonacci
	Definir n Como Entero
	Definir f1, f2, res Como Entero //res es el fibonacci en la posicion n
	definir i Como Entero
	definir serie Como Cadena
	definir aux como cadena
	leer n //posicion de la serie
	Segun n Hacer
		caso 1:
			serie ="0"
			res = 0
		caso 2:
			serie = "0,1"
			res =1
		de otro modo:
			serie = "0,1"
			f1 = 0
			f2 = 1
			i = 2
			Repetir
				res = f1 + f2
				aux= ConvertirATexto(res)
				serie = serie + "," + aux

				f1 = f2
				f2 = res
				i = i + 1
			Hasta que i = n
	Fin Segun
		escribir "el fibonacci para n= " n " es = " aux " y la serie " serie
FinAlgoritmo
