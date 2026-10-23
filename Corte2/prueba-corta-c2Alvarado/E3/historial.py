# ============================================================
#  Prueba corta · Segundo corte · EJERCICIO 3  (25 puntos)
#  Tema: pilas
#  Sistema: PrestaLab — historial de acciones del operador
#
#  NO MODIFIQUE el archivo pruebas_e3.py
#  Ejecute:   python3 pruebas_e3.py
# ============================================================


def historial_final(acciones, pm = 0):
    """Recibe una lista de cadenas. Cada cadena distinta de "DESHACER"
       se agrega al historial. La cadena "DESHACER" retira la ultima
       accion registrada; si el historial esta vacio, se IGNORA sin error.

       Devuelve el historial resultante como lista, de la accion mas
       antigua a la mas reciente.

       DEFECTO REPORTADO: el programa se cae cuando llega un "DESHACER"
       y el historial esta vacio."""
    max_profundidad = 0
    pila = []
    for a in acciones:
        if a == "DESHACER":
            #error: si el historial esta vacio y llega un "DESHACER", se rompia, ya qur no se había implementado if pila
            if pila != []:
                pila.pop()              # <-- revise
        else:
            pila.append(a)
            if len(pila) > max_profundidad:
                max_profundidad = len(pila)
    if pm == 1:
        return max_profundidad
    return pila


def profundidad_maxima(acciones):
    """Devuelve el mayor numero de acciones que el historial llego a
       tener en algun momento del recorrido.

       Ejemplo: ["a", "b", "DESHACER", "c"] -> 2
                (el historial llego a tener 2 elementos: a y b)

       PENDIENTE: implementar."""
       #para no repetir el codigo, agregué un deafult a la función historial_final  (pm = 0)
       #y si se le indica que pm = 1 como argumento, devuelve la profundidad máxima en lugar del historial final.
    pm = historial_final(acciones, 1)
    return pm
