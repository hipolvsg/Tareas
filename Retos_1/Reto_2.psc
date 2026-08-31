Algoritmo Reto_2
	Definir edad1, edad2, edad3, count Como Entero
	Definir cUrgencia1, cUrgencia2, cUrgencia3 Como Lógico
	cUrgencia1 <- Falso
	cUrgencia2 <- Falso
	cUrgencia3 <- Falso
	Definir entradacond1, entradacond2, entradacond3 Como Caracter
	Definir tiempoEs1, tiempoEs2, tiempoEs3, puntospri1, puntospri2, puntospri3 Como Entero
	puntospri1 <- 0
	puntospri2 <- 0
	puntospri3 <- 0
	count <- 1
	mientras count < 4 Hacer
		Escribir 'user(' count ')Porfavor escriba (y) si tiene una condicion de urgencia(operaciones de accion inmediata con riesgo medico), (n) si no la tiene: '
		Segun count Hacer
			1:
				leer entradacond1
				si entradacond1 = "y" Entonces
					cUrgencia1 <- Verdadero
				FinSi
			2:
				leer entradacond2
				si entradacond2 = "y" Entonces
					cUrgencia2 <- Verdadero
				FinSi
			3:
				leer entradacond3
				si entradacond3 = "y" Entonces
					cUrgencia3 <- Verdadero
				FinSi
			De Otro Modo:
				Escribir "Error :(, cuando se repitan las preguntas y el usuario 1 se empezaran a registrar de nuevo las respuestas"
				count <- 1
				
		Fin Segun
		Escribir 'user(' count ')Porfavor digite su edad en años:' 
		Segun count Hacer
			1:
				leer edad1
			2:
				leer edad2
			3:
				leer edad3
			De Otro Modo:
				Escribir "Error :(, cuando se repitan las preguntas y el usuario 1 se empezaran a registrar de nuevo las respuestas"
				count <- 1
		FinSegun
		Escribir 'user(' count ')Porfavor digite cuanto tiempo lleva esperando en minutos: '
		Segun count Hacer
			1:
				leer tiempoEs1
			2:
				leer tiempoEs2
			3:
				leer tiempoEs3
			De Otro Modo:
				Escribir "Error :(, cuando se repitan las preguntas y el usuario 1 se empezaran a registrar de nuevo las respuestas"
				count <- 1
		FinSegun
		
		count <- count + 1
	FinMientras
	
	Si cUrgencia1 = Verdadero Entonces
		puntospri1 <- puntospri1 + 1000
	FinSi
	
	Si cUrgencia2 = Verdadero Entonces
		puntospri2 <- puntospri2 + 1000
	FinSi
	
	Si cUrgencia3 = Verdadero Entonces
		puntospri3 <- puntospri3 + 1000
	FinSi
	
	Si edad1 > 60 o edad1 < 18 Entonces
		puntospri1 <- puntospri1 + 500
	FinSi
	Si edad2 > 60 o edad2 < 18 Entonces
		puntospri2 <- puntospri2 + 500
	FinSi
	Si edad3 > 60 o edad3 < 18 Entonces
		puntospri3 <- puntospri3 + 500
	FinSi
	
	Si tiempoEs1 >= tiempoEs2 Y tiempoEs1 >= tiempoEs3 Entonces
		puntospri1 <- puntospri1 + 200
	FinSi
	Si tiempoEs2 >= tiempoEs1 Y tiempoEs2 >= tiempoEs3 Entonces
		puntospri2 <- puntospri2 + 200
	FinSi
	Si tiempoEs3 >= tiempoEs1 Y tiempoEs3 >= tiempoEs2 Entonces
		puntospri3 <- puntospri3 + 200
	FinSi
	
	si puntospri1 >= puntospri2 y puntospri2 >= puntospri3 Entonces
		Escribir "Orden prioritario: paciente 1, paciente 2, paciente 3."
	SiNo si puntospri1 >= puntospri3 y puntospri3 >= puntospri2 Entonces
			Escribir "Orden prioritario: paciente 1, paciente 3, paciente 2."
		SiNo si puntospri2 >= puntospri1 y puntospri1 >= puntospri3 Entonces
				Escribir "Orden prioritario: paciente 2, paciente 1, paciente 3."
			SiNo si puntospri2 >= puntospri3 y puntospri3 >= puntospri1 entonces
					Escribir "Orden prioritario: paciente 2, paciente 3, paciente 1."
				SiNo si puntospri3 >= puntospri1 y puntospri1 >= puntospri2 Entonces
						Escribir "Orden prioritario: paciente 3, paciente 1, paciente 2."
					SiNo si puntospri3 >= puntospri2 y puntospri2 >= puntospri1 Entonces
							Escribir "Orden prioritario: paciente 3, paciente 2, paciente 1."
						FinSi
					FinSi
				FinSi
			FinSi
		FinSi
	FinSi
	
FinAlgoritmo
