class cola:
    def __init__(self):
        self.items = []

    def encolar(self, item):
        self.items.append(item)

    def desencolar(self):
        self.frente = self.frente.siguiente
        if self.frente() is None: self.final = None
        self.n -= 1
        return x
        


    def esta_vacia(self):
        return len(self.items) == 0

    def frente(self):
        if not self.esta_vacia():
            return self.items[0]
        return None

