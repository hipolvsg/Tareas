# ============================================================
#  Prueba corta · Segundo corte · EJERCICIO 1  (25 puntos)
#  Tema: recursion y exploracion de caminos
#  Sistema: TurnoJusto — calculo de rutas de atencion
#
#  NO MODIFIQUE el archivo pruebas_e1.py
#  Ejecute:   python3 pruebas_e1.py
# ============================================================


def suma_impares(n):
    """Devuelve la suma de todos los numeros impares desde 1 hasta n (incluido).
       Ejemplos:  suma_impares(5) -> 9     (1 + 3 + 5)
                  suma_impares(0) -> 0     (no hay impares)

       DEFECTO REPORTADO: con ciertas entradas el programa se cae.
       Revise el caso base."""
    #Errror: En la ejecución no se espera n < 0 (pruebas) pero si = 0, no está implementado el caso base para n = 0
    if n == 0:
        return 0
    if n == 1:
        return 1
    if n % 2 == 0:
        return suma_impares(n - 1)
    return n + suma_impares(n - 1)


def contar_caminos(f, c, numcaminos = 0):
    """Devuelve cuantos caminos distintos hay desde la casilla superior
       izquierda hasta la inferior derecha de una cuadricula de f filas
       por c columnas, avanzando solo a la DERECHA o hacia ABAJO.

       Ejemplo: contar_caminos(3, 3) -> 6

       PENDIENTE: implementar. Debe ser recursiva: no use ciclos ni listas."""
    #caso base: si hay solo una fila o una columna, solo hay un camino posible o se llegó al final de ese camino
    if f == 1 or c == 1:
        return 1
    return contar_caminos(f - 1, c) + contar_caminos(f, c - 1)
    
