matriz = [[0] * N for _ in range(N)]     # ojo: NO [[0]*N]*N aliasing
for u, v in ARISTAS:
    matriz[u][v] = 1
    matriz[v][u] = 1          # no dirigido: la matriz es simetrica
 
def hay_via(u, v):
    return matriz[u][v] == 1  # O(1)