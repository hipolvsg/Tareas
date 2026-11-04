# Sesion 40 — Grafos: matriz de adyacencia frente a lista de adyacencia

NOMBRES = [
    "Centro", "Norte", "Occidente", "Sur", "Oriente",
    "Chapinero", "Bosa", "Usaquén", "Vereda"
]

ARISTAS = [
    (0, 1), (1, 2), (0, 3), (0, 4), (1, 5),
    (3, 6), (4, 7), (5, 7), (2, 6), (6, 8),
    (8, 1), (6, 5), (5, 8), (3, 7), (7, 8),
    (1, 8), (5, 6), (5, 3)
]

N = 9


def caminos(aristas):
    resultado = []
    for u, v in aristas:
        resultado.append((u, v))
        resultado.append((v, u))
        for x, y in aristas:
            if x == v and y != u:
                resultado.append((u, y))
            if y == v and x != u:
                resultado.append((u, x))
    return resultado


# ---------- Representacion 1: matriz de adyacencia ----------
matriz = [[0] * N for _ in range(N)]
for u, v in ARISTAS:
    matriz[u][v] = 1
    matriz[v][u] = 1  # grafo NO dirigido: la matriz es simetrica

print("MATRIZ DE ADYACENCIA")
print("            " + " ".join(f"{n[:3]:>4}" for n in NOMBRES))
for i in range(N):
    print(f"{NOMBRES[i]:>11} " + " ".join(f"{matriz[i][j]:>4}" for j in range(N)))

# ---------- Representacion 2: lista de adyacencia ----------
lista = [[] for _ in range(N)]
for u, v in ARISTAS:
    lista[u].append(v)
    lista[v].append(u)
for v in lista:
    v.sort()

print("\nLISTA DE ADYACENCIA")
for i in range(N):
    print(f"  {NOMBRES[i]:>10} -> {', '.join(NOMBRES[j] for j in lista[i])}")

print("\nGRADO DE CADA VERTICE (cuantas vias salen de el)")
for i in range(N):
    g_mat = sum(matriz[i])
    g_lis = len(lista[i])
    print(f"  {NOMBRES[i]:>10}: {g_lis}" + ("" if g_mat == g_lis else "  <-- DISCREPANCIA"))

E = len(ARISTAS)
print(f"\nV = {N} vertices,  E = {E} aristas")
print(f"  Matriz : {N * N} casillas en memoria. Existe arista? O(1). Recorrer vecinos: O(V) = {N} casillas.")
print(f"  Lista  : {2 * E} referencias en memoria. Existe arista? O(grado). Recorrer vecinos: O(grado).")
densidad = 2.0 * E / (N * (N - 1))
print(f"  Densidad = 2E / (V(V-1)) = {densidad:.2f}  ->  grafo {'DENSO: conviene matriz' if densidad > 0.5 else 'DISPERSO: conviene lista'}")


def hay_via_matriz(u, v):
    return matriz[u][v] == 1


def hay_via_lista(u, v):
    return v in lista[u]


for u, v in [(0, 1), (0, 7), (5, 6)]:
    print(f"  Conecta {NOMBRES[u]} con {NOMBRES[v]}? matriz={hay_via_matriz(u, v)}  lista={hay_via_lista(u, v)}")

print("\nGRADOS DE CADA VERTICE (cuantas vias entran y salen)")
for i in range(N):
    grado = sum(matriz[i])
    print(f"  {NOMBRES[i]:>10}: {grado}")

print(f"\nNUMERO TOTAL DE ARISTAS: {E}")
cam = caminos(ARISTAS)
print(f"\nNUMERO TOTAL DE CAMINOS: {len(cam)}")
print(f"\nNUMERO TOTAL DE VERTICES: {N}")