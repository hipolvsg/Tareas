# ============================================================
#  Cívica Software  ·  TCK-4423  ·  Severidad P0  ·  PRODUCCION CAIDA
#  Sistema: TurnoJusto  —  La fila de atencion pierde personas.
#
#  Reportes de soporte:
#   - "Atendi al primero de la fila y desaparecieron todos."
#   - "Retire a una persona del final y la fila sigue mostrandola."
#   - "La fila dice que tiene gente cuando esta vacia."
# ============================================================
""" El archivo fila.py implementa la fila de espera de un punto de atención mediante una lista enlazada simple. Cada nodo es una persona con su número de turno y su nombre. Los métodos llegar, cuantos y listar funcionan bien. 

El defecto está en el método retirar. Busque los comentarios que dicen «caso 1» y «caso 2». """

class Nodo:
    def __init__(self, turno, nombre):
        self.turno = turno
        self.nombre = nombre
        self.siguiente = None


class Fila:
    def __init__(self):
        self.cabeza = None

    def llegar(self, turno, nombre):
        """Agrega una persona al FINAL de la fila."""
        nuevo = Nodo(turno, nombre)
        if self.cabeza is None:
            self.cabeza = nuevo
            return
        actual = self.cabeza
        while actual.siguiente is not None:
            actual = actual.siguiente
        actual.siguiente = nuevo

    def retirar(self, turno):
        """Elimina de la fila a la persona con ese turno.
           Devuelve True si la elimino, False si no estaba.
           BUG P0: revise los tres casos."""
        if self.cabeza is None:
            return False
        if self.cabeza.turno == turno:
            self.cabeza = self.cabeza.siguiente  # <-- caso 1
            return True
        anterior = self.cabeza
        while anterior.siguiente is not None:
            if anterior.siguiente.turno == turno:
                anterior.siguiente = anterior.siguiente.siguiente   # <-- caso 2
                return True
            anterior = anterior.siguiente
        return False

    def cuantos(self):
        """Devuelve cuantas personas hay en la fila."""
        n = 0
        actual = self.cabeza
        while actual is not None:
            n += 1
            actual = actual.siguiente
        return n

    def listar(self):
        r = []
        actual = self.cabeza
        while actual is not None:
            r.append(actual.turno)
            actual = actual.siguiente
        return r
