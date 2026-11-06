# Version recursiva del recorrido DFS
def dfs_rec(u, visitado, orden):
    visitado[u] = True          # el hilo de Ariadna
    orden.append(u)
    for v in lista[u]:
        if not visitado[v]:
            dfs_rec(v, visitado, orden)

# Version iterativa del recorrido DFS
def dfs_iter(inicio):
    visitado = [False] * N
    pila = [inicio]
    orden = []
    while pila:
        u = pila.pop()                   # LIFO: sale el ultimo que entro
        if visitado[u]:
            continue                     # pudo entrar dos veces a la pila
        visitado[u] = True
        orden.append(u)
        for v in reversed(lista[u]):     # al reves, para igualar al recursivo
            if not visitado[v]:
                pila.append(v)
    return orden