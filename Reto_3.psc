Algoritmo Reto_3
	Definir Secret, guess, count Como Entero
	Definir Detectives Como Logico
	Detectives <- Falso
	count <- 0
	Escribir 'JUGADOR A ESCOGER EL NUMERO, PORFAVOR DIGITARLO (numero natural del 1-100)'
	leer Secret
	si secret > 100 o secret < 0 Entonces
		Escribir 'Cheat mode activated.'
	FinSi
	
	Mientras count < 21
		count <- count + 1
		Escribir '-'
	FinMientras
	count <- 0
	Escribir 'Dejale la consola al otro jugador.'
	Escribir '¡¡¡HORA DE ADIVINAR!!!'
	mientras count < 7
		count <- count + 1
		Escribir 'Porfavor digita tu intento (Intentos restantes: ' 8 - count ' )'
		Leer guess
		si guess < secret Entonces
			Escribir 'El numero que estas intentando adivinar es mayor a ' guess 
		SiNo Si guess > secret Entonces
				Escribir 'El numero que estas intentando adivinar es menor a ' guess 
			Sino 
				Escribir '¡¡FELICIDADES!!, HAZ ACERTADO.'
				Detectives <- Verdadero
				count <- 7
				
			FinSi
		FinSi
	FinMientras
	Si Detectives = Falso Entonces
		Escribir 'El equipo de los pensadores ha ganado ¡Felicidades!'
	SiNo 
		Escribir 'El equipo de los detectives ha ganado ¡Felicidades!'
	FinSi
FinAlgoritmo
