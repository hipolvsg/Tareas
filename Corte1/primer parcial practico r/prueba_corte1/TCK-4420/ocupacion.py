# ============================================================
#  Cívica Software  ·  TCK-4420  ·  Severidad P3
#  Sistema: RedAcopio  —  Reporte de ocupación
#  NO MODIFIQUE la seccion de datos ni el archivo de pruebas.
# ============================================================

# filas = puntos de acopio, columnas = dias de la semana

# «El informe de totales por punto de acopio sale bien, pero el de totales por día está mal: 
# nos da los mismos números que el de puntos.» 
# «Además necesitamos dos datos que nunca se implementaron: 
# cuál fue el día de menor recolección y cuántos registros quedaron en cero porque el punto no operó.» 

ocupacion = [
    [4, 2, 6, 1, 3, 0],
    [0, 5, 5, 2, 7, 1],
    [8, 1, 0, 4, 2, 6],
    [3, 3, 3, 0, 0, 5],
]

def total_por_punto(m):
    """Devuelve una lista con el total recogido por cada punto (fila)."""
    totales = []
    for fila in m:
        s = 0
        for v in fila:
            s += v
        totales.append(s)
    return totales


def total_por_dia(m):
    """Devuelve una lista con el total recogido cada dia (columna).
       BUG REPORTADO: entrega totales incorrectos."""
    totales = []

    #ERROR: En el bucle for se recorre la cantidad de filas, pero se suman los elementos de cada fila, lo que da el total por punto, no por día.
    #Corrección: Intercambiar el index del recorrido para que se recorra la cantidad de columnas y se sumen los elementos de cada columna.
    for i in range(len(m[0])):           # <-- recorre la cantidad de columnas
        s = 0
        for j in range(len(m)):
            s += m[j][i]  # <-- suma los elementos de cada columna
        totales.append(s)
    return totales

#ERROR: La función únicamente no tenía función práctica, por lo que se reutilizo la función anterior
def dia_mas_flojo(m):
    """Devuelve el indice del dia con MENOR recoleccion total.
       PENDIENTE: implementar."""
    #ERROR: La función únicamente no tenía función práctica.
    #Por lo que se reutilizo la función anterior
    totalesPorDia = total_por_dia(m)
    #argumento.index(): devuelve el indice del elemento que coincide con la solicitud.
    #min(argumento): devuelve el valor mínimo de la lista.
    return totalesPorDia.index(min(totalesPorDia))


def puntos_inactivos(m):
    """Devuelve cuantos registros estan en 0 (el punto no opero ese dia).
       PENDIENTE: implementar."""
    #ERROR: La función únicamente no tenía función práctica. 
    #Por lo que se recorrió la lista buscando 0, y se sumo la cantidad de veces que aparecian.
    ceros = 0
    for fila in m:
        for v in fila:
            if v == 0:
                ceros += 1
    return ceros


