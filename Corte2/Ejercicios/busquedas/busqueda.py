#Arreglo con busqueda binaria
def busqueda_binaria(arr, x, comparaciones = 0):
    low = 0
    high = len(arr) - 1
    mid = 0

    while low <= high:
        mid = (high + low) // 2
        comparaciones += 1
        if arr[mid] < x:
            low = mid + 1
        elif arr[mid] > x:
            high = mid - 1
        else:
            return mid, comparaciones
    return -1, comparaciones
#Arreglo con busqueda secuencial
def busqueda_secuencial(arr, x, comparaciones = 0):
    for i in range(len(arr)):
        comparaciones += 1
        if arr[i] == x:
            return i, comparaciones
    return -1, comparaciones
#main
#incializacion de arreglo
comparaciones_binaria = 0
comparaciones_secuencial = 0
arr = [2, 3, 4, 10, 40, 50, 60, 70, 80, 90]
x = 50
#llamada a la funcion de busqueda binaria
result, comparaciones_binaria = busqueda_binaria(arr, x, comparaciones_binaria)
if result != -1:
    print("Elemento encontrado en el indice:", str(result))
else:
    print("Elemento no encontrado en el arreglo")
#llamada a la funcion de busqueda secuencial
result, comparaciones_secuencial = busqueda_secuencial(arr, x, comparaciones_secuencial)
if result != -1:
    print("Elemento encontrado en el indice:", str(result))
else:
    print("Elemento no encontrado en el arreglo")

#como medimos las comparaciones
print("\t\tCOMPARACIONES")
print("Comparaciones busqueda binaria:", comparaciones_binaria)
print("Comparaciones busqueda secuencial:", comparaciones_secuencial)
