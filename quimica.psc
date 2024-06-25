Algoritmo quimica
	definir capE Como Real
	definir cBidon Como Real
	Definir numEnv Como Entero
	definir sobra Como Real
	Bidon=60
	
	escribir "ingrese capac de los envases disponib"
	leer capE
	cBidon= Bidon*1000
	numEnv= trunc(cBidon/capE)
	sobra= cBidon Mod capE
	ESCRIBIR "LOS ENVASES A USAR SON: " numEnv "Y SOBRAN ESTOS ML DE DETERGENTE: " sobra
	
FinAlgoritmo
