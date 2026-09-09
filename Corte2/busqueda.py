#Arreglo con busqueda binaria
def busqueda_binaria(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0
    global comparaciones_binaria

    while low <= high:
        mid = (high + low) // 2
        comparaciones_binaria += 1
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1
#Arreglo con busqueda secuencial
def busqueda_secuencial(arr, x):
    global comparaciones_secuencial
    for i in range(len(arr)):
        comparaciones_secuencial += 1
        if arr[i] == x:
            return i
    return -1
#main
#incializacion de arreglo
comparaciones_binaria = 0
comparaciones_secuencial = 0
arr = [2, 3, 4, 10, 40]
x = 10
#llamada a la funcion de busqueda binaria
result = busqueda_binaria(arr, x)
if result != -1:
    print("Elemento encontrado en el indice:", str(result))
else:
    print("Elemento no encontrado en el arreglo")
#llamada a la funcion de busqueda secuencial
result = busqueda_secuencial(arr, x)
if result != -1:
    print("Elemento encontrado en el indice:", str(result))
else:
    print("Elemento no encontrado en el arreglo")

#como medimos las comparaciones
print("\t\tCOMPARACIONES")
print("Comparaciones busqueda binaria:", comparaciones_binaria)
print("Comparaciones busqueda secuencial:", comparaciones_secuencial)
