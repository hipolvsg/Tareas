class Stack:
    def __init__(self):
        self.items = []

    def apilar(self, x):
        self.items.append(x)

    def desapilar(self):
        if self.vacia():
            return None
        return self.items.pop()

    def cima(self):
        if self.vacia():
            return None
        return self.items[-1]

    def vacia(self):
        return len(self.items) == 0

    def balanceados(s):
        # Verifica si los paréntesis, corchetes y llaves están balanceados en la cadena s.
        p = Stack(); Pares = { ')': '(', '}': '{', ']': '[' }
        for c in s:
            # Si el carácter es un paréntesis de apertura, lo apilamos. Si es de cierre, verificamos el balance.
            if c in '({[':
                p.apilar(c)
            elif c in Pares:
                # Si el carácter es un paréntesis de cierre, verificamos si hay un paréntesis de apertura correspondiente en la pila.
                if p.vacia() or p.desapilar() != Pares[c]:
                    return False
        return p.vacia()
    #Cual está mal?: (a, {b}, {c}) y (a, [b), c]
#EJECUCION balanceados
print("\n(a, {b}, {c}):\n")
print(Stack.balanceados("(a, {b}, {c})"))  # True
print("\n(a, [b), c]:\n")
print(Stack.balanceados("(a, [b), c]"))  # False
print("\n():\n")
print(Stack.balanceados("()"))

print("\n([]{}):\n")
print(Stack.balanceados("([]{})"))

print("\n([)]):\n")
print(Stack.balanceados("([)]"))

print("\n((())\n")
print(Stack.balanceados("((())"))

print("\n([]{}):\n")
print(Stack.balanceados("([]{})"))

print("\n([)]):\n")
print(Stack.balanceados("([)]"))

print("\n((()):\n")
print(Stack.balanceados("((()"))

print("\n{}[]():\n")
print(Stack.balanceados("{}[]()"))
