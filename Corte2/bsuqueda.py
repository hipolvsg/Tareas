#Arreglo con busqueda binaria
def busqueda_binaria(arr, x):
    low = 0
    high = len(arr) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid
    return -1
#Arreglo con busqueda secuencial
def busqueda_secuencial(arr, x):
    for i in range(len(arr)):
        if arr[i] == x:
            return i
    return -1
#main
#incializacion de arreglo
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
