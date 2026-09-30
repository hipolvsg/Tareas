import time

#
# Laboratorio 2
# Autor: Oscar David Alvarado Navarrete
# Fecha: 28-sept-2026
# Descripción:
# Parte A Responda y justifique:
# 1. Tengo mil datos ya ordenados y quiero ordenarlos otra vez. ¿Cuál de los tres básicos hace menos trabajo y por qué?
# 2. Mi Quicksort escoge el primer elemento como pivote. Denme un conjunto de datos que lo haga comportarse pésimo.
# 3. Quiero buscar cien veces sobre una colección de diez mil elementos desordenados. ¿Ordeno primero y uso binaria, o busco secuencial cien veces? Justifiquen.
#
# Parte B — Búsqueda comparada
# Implementen búsqueda secuencial y binaria sobre su colección de registros, contando comparaciones. Produzcan la tabla comparativa para cuatro casos: el primer elemento, uno del medio, el último, y uno que no existe.
#
# Parte C — Los tres ordenamientos básicos (30%)
# Implementen Bubble, Selection e Insertion sobre sus registros, con contadores de comparaciones e intercambios. Reporten los resultados con datos desordenados y con datos ya ordenados, y expliquen la diferencia.
#
# Parte D — Un ordenamiento avanzado y la medición (40%)
# Implementen Merge o Quicksort, midan el tiempo contra uno de los básicos para tres tamaños distintos de entrada, y produzcan la tabla. En el archivo de respuestas, expliquen en cinco líneas por qué los tiempos crecen distinto.
#
# Como siempre, los dos lenguajes.
#
# Parte E— Complejidad
# 1. Midan el algoritmo desarrollado, en los dos lenguajes, y hagan la tabla con la columna de factor.
# 2. Escriban el párrafo que interpreta esa tabla. No basta pegarla: hay que decir qué significa. Si el factor da dos, digan que es O de n y que coincide con lo esperado. Si no coincide, digan por qué creen que no.
#
# Parte F — CD/CI
# Un equipo de desarrollo tiene implementado el mismo algoritmo en Python y C++. Ambos proyectos utilizan GitHub y quieren automatizar un proceso de Integración Continua y Entrega Continua (CI/CD).
#
# El equipo propone el siguiente flujo:
#
# git push → ejecutar programa → pruebas → >compilar → desplegar
#
# Uno de los integrantes afirma:
#
# “En Python no necesitamos Integración Continua porque Python no requiere compilación; CI/CD es principalmente para lenguajes como C++.”
#
# Pregunta:
#
# ¿Estás de acuerdo con esta afirmación? Explica por qué y propón cómo debería ser un pipeline de CI/CD para el proyecto en Python y otro para C++.
#
# Como implementarioa CD/CI para este laboratorio

#
# Solución:
#
# A:
# 1. Tengo mil datos ya ordenados y quiero ordenarlos otra vez. ¿Cuál de los tres básicos hace menos trabajo y por qué?
# Respuesta: Insertion sort, porque si los datos ya están ordenados, no hace pasos extra, únicamente realiza las comparaciones sin realizar intercambios.
# 2. Mi Quicksort escoge el primer elemento como pivote. Denme un conjunto de datos que lo haga comportarse pésimo.
# Respuesta: Un conjunto de datos ya ordenados, ya que cada elemento que pasa entra como pivote nuevo, lo que provoca su peor caso de complejidad O(n^2).
# Conjunto de datos que provoca peor caso para Quicksort respecto a primer elemento como pivote: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# 3. Quiero buscar cien veces sobre una colección de diez mil elementos desordenados. ¿Ordeno primero y uso binaria, o busco secuencial cien veces?
# Respuesta: Si lo ideal de la implementación es usar esa misma base de datos muchas veces, debido a la densidad, en términos de eficiencia es mejor ordenar primero y luego usar búsqueda binaria.
# En cambio, si se espera usar esa lista una única vez o el costo de ordenamiento es muy alto, es preferible realizar búsquedas secuenciales.
#
# B:
# Implementen búsqueda secuencial y binaria sobre su colección de registros, contando comparaciones. Produzcan la tabla comparativa para cuatro casos: el primer elemento, uno del medio, el último, y uno que no existe.
#

def busquedas(coleccion):
    if not coleccion:
        print("La coleccion esta vacia.")
        return

    ordenada = sorted(coleccion)
    targets = [coleccion[0], coleccion[len(coleccion) // 2], coleccion[len(coleccion) - 1], -1]
    labels = ["primer elemento", "elemento del medio", "ultimo elemento", "elemento no existente"]

    print("Busqueda secuencial:")
    for i in range(4):
        comparaciones = 0
        encontrado = False

        for j in range(len(coleccion)):
            comparaciones += 1
            if coleccion[j] == targets[i]:
                encontrado = True
                print(f"- {labels[i]}: encontrado en la posicion {j} con {comparaciones} comparaciones.")
                break

        if not encontrado:
            print(f"- {labels[i]}: no encontrado con {comparaciones} comparaciones.")

    print("\nBusqueda binaria:")
    for i in range(4):
        comparaciones = 0
        encontrado = False
        inicio = 0
        fin = len(ordenada) - 1

        while inicio <= fin:
            comparaciones += 1
            medio = inicio + (fin - inicio) // 2

            if ordenada[medio] == targets[i]:
                encontrado = True
                print(f"- {labels[i]}: encontrado en la posicion {medio} con {comparaciones} comparaciones.")
                break
            elif ordenada[medio] < targets[i]:
                inicio = medio + 1
            else:
                fin = medio - 1

        if not encontrado:
            print(f"- {labels[i]}: no encontrado con {comparaciones} comparaciones.")


def busqueda_secuencial(arr, objetivo, comparaciones=0):
    for i in range(len(arr)):
        comparaciones += 1
        if arr[i] == objetivo:
            return comparaciones
    return comparaciones


def busqueda_binaria(arr, objetivo, comparaciones=0):
    inicio = 0
    fin = len(arr) - 1

    while inicio <= fin:
        comparaciones += 1
        medio = inicio + (fin - inicio) // 2

        if arr[medio] == objetivo:
            return comparaciones
        elif arr[medio] < objetivo:
            inicio = medio + 1
        else:
            fin = medio - 1

    return comparaciones


def bubble_sort(arr):
    n = len(arr)
    comparaciones = 0
    intercambios = 0
    hubo_cambio = False

    for i in range(n - 1):
        for j in range(n - i - 1):
            comparaciones += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                intercambios += 1
                hubo_cambio = True
        if not hubo_cambio:
            break
        hubo_cambio = False

    return arr, comparaciones, intercambios


def selection_sort(arr):
    n = len(arr)
    comparaciones = 0
    intercambios = 0

    for i in range(n - 1):
        min_idx = i
        for j in range(i + 1, n):
            comparaciones += 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        if min_idx != i:
            arr[i], arr[min_idx] = arr[min_idx], arr[i]
            intercambios += 1

    return arr, comparaciones, intercambios


def insertion_sort(arr):
    n = len(arr)
    comparaciones = 0
    intercambios = 0

    for i in range(1, n):
        key = arr[i]
        j = i - 1

        while j >= 0:
            comparaciones += 1
            if arr[j] <= key:
                break
            arr[j + 1] = arr[j]
            intercambios += 1
            j -= 1

        arr[j + 1] = key

    return arr, comparaciones, intercambios


def merge_sort(arr):
    n = len(arr)
    if n <= 1:
        return arr, 0, 0

    mid = n // 2
    izquierda = arr[:mid]
    derecha = arr[mid:]

    izquierda, comp_izq, int_izq = merge_sort(izquierda)
    derecha, comp_der, int_der = merge_sort(derecha)

    comparaciones = comp_izq + comp_der
    intercambios = int_izq + int_der

    i = 0
    j = 0
    k = 0
    merged = [0] * n

    while i < len(izquierda) and j < len(derecha):
        comparaciones += 1
        if izquierda[i] <= derecha[j]:
            merged[k] = izquierda[i]
            i += 1
        else:
            merged[k] = derecha[j]
            j += 1
        intercambios += 1
        k += 1

    while i < len(izquierda):
        merged[k] = izquierda[i]
        i += 1
        k += 1
        intercambios += 1

    while j < len(derecha):
        merged[k] = derecha[j]
        j += 1
        k += 1
        intercambios += 1

    return merged, comparaciones, intercambios


def mostrar_resultado_basico(nombre, arr, comparaciones, intercambios):
    print(f"\n{nombre}")
    print(f"  Comparaciones: {comparaciones}")
    print(f"  Intercambios: {intercambios}")
    print("  Arreglo ordenado: ", end="")
    print(*arr)


def ejecutar_parte_c():
    print("\nPARTE C\n")

    ordenado = [1, 2, 3, 4, 5, 6, 7, 8]
    desordenado = [64, 25, 12, 22, 11, 90, 45, 33]

    arr = ordenado.copy()
    arr, comp, switches = bubble_sort(arr)
    mostrar_resultado_basico("Bubble Sort (ordenado)", arr, comp, switches)

    arr = ordenado.copy()
    arr, comp, switches = selection_sort(arr)
    mostrar_resultado_basico("Selection Sort (ordenado)", arr, comp, switches)

    arr = ordenado.copy()
    arr, comp, switches = insertion_sort(arr)
    mostrar_resultado_basico("Insertion Sort (ordenado)", arr, comp, switches)

    arr = desordenado.copy()
    arr, comp, switches = bubble_sort(arr)
    mostrar_resultado_basico("Bubble Sort (desordenado)", arr, comp, switches)

    arr = desordenado.copy()
    arr, comp, switches = selection_sort(arr)
    mostrar_resultado_basico("Selection Sort (desordenado)", arr, comp, switches)

    arr = desordenado.copy()
    arr, comp, switches = insertion_sort(arr)
    mostrar_resultado_basico("Insertion Sort (desordenado)", arr, comp, switches)

    print("\nExplicacion: bubble e insertion cambian bastante más cuando el arreglo esta desordenado \nrespecto a selection que se podría considerar constante (O(n^2)) ya que no importa que, siempre realiza la misma cantidad de comparaciones.")


def leer_lista():
    datos = []
    count = 0

    while count < 15:
        elemento = 0
        print(f"Ingrese elemento ({count + 1}): ", end="")
        try:
            elemento = int(input())
        except ValueError:
            print("Entrada invalida. Intente de nuevo.")
            continue

        if elemento < 0:
            elemento *= -1

        datos.append(elemento)
        count += 1

    return datos


def medir_complejidad():
    print("\nPARTE E\n")
    tamanos = [100, 200, 400, 800]
    anterior = 0

    print("n,tiempo_us,factor")
    for n in tamanos:
        datos = [(i * 37 + 11) % 1000 for i in range(n)]
        inicio = time.perf_counter_ns()
        _, _, _ = merge_sort(datos.copy())
        fin = time.perf_counter_ns()
        tiempo = (fin - inicio) / 1000.0

        factor = 0.0
        if anterior != 0:
            factor = tiempo / anterior

        print(f"{n},{tiempo},{factor}")
        anterior = tiempo

    print("\nInterpretacion: La tabla muestra como cambia el tiempo del algoritmo cuando aumenta el tamaño de entrada. Si el factor se acerca a 2, entonces al duplicar n el tiempo casi se duplica, lo que indica que el crecimiento es proporcional a la entrada. Eso coincide con la complejidad esperada del algoritmo desarrollado. Si el factor no coincide exactamente, puede deberse al ruido del sistema, la carga del computador o diferencias de ejecucion, pero la tendencia general sigue siendo la misma.\n")


def main():
    datos = leer_lista()
    busquedas(datos)
    ejecutar_parte_c()
    medir_complejidad()


if __name__ == "__main__":
    main()
