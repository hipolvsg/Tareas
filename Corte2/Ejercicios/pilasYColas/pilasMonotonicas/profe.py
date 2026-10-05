#Entrada: [2, 1, 2, 4, 3]
#salida: [4,2,4,-1,-1]
def siguiente_mayor(a):
    n=len(a)
    res=[-1]*n
    pila=[]
    for i in range (n):
        while pila and a[pila[-1]]<a[i]:
            res[pila.pop()]=a[i]
        pila.append(i)
    return res
print(siguiente_mayor([2, 1, 2, 4, 3]))
    