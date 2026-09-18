import copy #permite hacer el comando deepcopy
import time 


# 0 = libre, 1 = muro
laberinto = [
    [0,0,0,0,0,1,0,0,2,0],
    [0,0,1,0,0,0,0,1,0,0],
    [0,2,0,0,1,0,0,0,1,0],
    [0,0,0,1,0,0,0,0,0,0],
    [0,0,0,1,0,0,0,0,2,0],
    [0,1,0,0,0,0,1,0,0,0],
    [0,1,0,0,1,0,0,0,0,0],
    [0,0,2,0,0,0,1,0,0,0],
    [0,0,1,0,1,0,0,1,0,0],
    [0,0,0,0,1,0,0,0,0,0]
]


FILAS, COLS = len(laberinto), len(laberinto[0])
camino = [[0] * COLS for _ in range(FILAS)]
caminosValidos=[]
puntosAcopio=0
contador=0
longitudCamino=0
longitudMenor=0
for filas in laberinto:
    for i in range (len (filas)):
        if filas[i]==2:
            puntosAcopio+=1
    

def resolver(f, c, puntosAcopio):
    # 1. ¿me sali del tablero?
    if f < 0 or f >= FILAS or c < 0 or c >= COLS:
        return False
    # 2. ¿es muro o ya pase por aqui?
    if laberinto[f][c] == 1 or camino[f][c] == 1 or camino[f][c]==2:
        return False
    # 3. marco esta casilla como parte del camino
    if laberinto[f][c]==2:
        camino[f][c]=2
    else:
        camino[f][c] = 1
    if laberinto[f][c]==2:
        global contador 
        contador+=1
    # 4. CASO BASE: llegue a la salida, pero esta ves en devolver un true va a guardar el camino en una lista de caminos validos
    if f == FILAS - 1 and c == COLS - 1 and puntosAcopio==contador:
        copiaCamino=copy.deepcopy(camino) #deep copy sirve para hacer la copia de una matriz completa para evitar que cuando camino sea modificado lo que haya dentro de caminos validos tambien cambie
        caminosValidos.append(copiaCamino)
        if laberinto[f][c]==2: #reduce el contador de veces que paso por un punto de acopio si hay un punto de acopio en la salida
            contador-=1
        camino[f][c]=0 #realiza el backtracking
        return False
      
    # 5. CASO RECURSIVO: pruebo las cuatro direcciones
    if resolver(f + 1, c, puntosAcopio): return True
    if resolver(f, c + 1, puntosAcopio): return True
    if resolver(f - 1, c, puntosAcopio): return True
    if resolver(f, c - 1, puntosAcopio): return True
    # 6. BACKTRACKING: ninguna sirvio, desmarco y me devuelvo
    if laberinto[f][c]==2: #si retrocede desde un punto de acopio, le resta 1 al contador para evita que lo sume 2 veces
        contador-=1
    camino[f][c] = 0
    return False
inicio=time.perf_counter()
resolver(0, 0, puntosAcopio)
final=time.perf_counter()
duracion=final - inicio 
if caminosValidos!=[]:
    print(f"Hay salida. Caminos validos encontrados: {len(caminosValidos)}")

    for caminos in caminosValidos: #compara todos los caminos para determinar cual es el mas rapido
        for f in range(len(caminos)):
            for i in range(len(caminos[0])):
                if caminos[f][i]==1 or caminos[f][i]==2: #aprovechamos el hecho de que marca los caminos con un 1 si paso por ahi o con un 2 si habia un punto de acopio
                    longitudCamino+=1
        if longitudMenor==0:
            longitudMenor=longitudCamino
            caminoFinal=caminos
        elif longitudMenor>longitudCamino:
            longitudMenor=longitudCamino
            caminoFinal=caminos
        longitudCamino=0
                    
    for f in range(FILAS):
        print("  " + " ".join("*" if caminoFinal[f][c]==1  else ("#" if laberinto[f][c]==1  else ("p" if caminoFinal[f][c]==2 else ".")) #escribe * si era un camino, # si era una calle bloqueada, p si es un punto de acopio y . si no paso por ahi
        for c in range(COLS)))
else:
    print("No hay salida.")

print(f"La funcion tardo: {duracion} segundos en completarse")