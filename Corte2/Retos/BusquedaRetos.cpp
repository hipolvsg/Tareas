// Implementen la binaria de forma recursiva.

#include <iostream>

int BusquedaBinariaRecursiva(int arr[], int target){
    //saca mitad a partir de tamaño final - inicial del array.
    int mid = (sizeof(arr) - sizeof(arr[0])) / 2;
    //verifica que el array no esté vacio.
    if (sizeof(arr) == 0){
        //retorna index imposible.
        return -1;
    }
        /*Tres: si hay elementos repetidos, la binaria devuelve uno cualquiera de ellos. 
        Háganla devolver siempre el PRIMERO de los repetidos.*/
    // si encuentra target, retorna indice
    if (target == arr[mid]){
        while (mid > 0 && arr[mid - 1] == target){
            mid--;
        }
        return mid;
    }
    // si no, si el target es menor que el valor de la mitad del arreglo, crea otro arreglo con la mitad izquierdo y usa recursión sobre ese nuevo arreglo.
    else if (target < arr[mid]){
        int leftArr[mid];
        for (int i = 0; i < mid; i++){
            leftArr[i] = arr[i];
        }
        return BusquedaBinariaRecursiva(leftArr, target);
    }
    //lo mismo que el anterior pero con la mitad de la derecha.
    else if (target > arr[mid]){
        int rightArr[sizeof(arr)/sizeof(arr[0]) - mid - 1];
        for (int i = mid + 1; i < sizeof(arr)/sizeof(arr[0]); i++){
            rightArr[i - mid - 1] = arr[i];
        }
        return BusquedaBinariaRecursiva(rightArr, target);
        //        //si no lo encuentra, retorna index de valor imposible.
        //    }else {
        //        return -1;
        //    }
        /*modifíquenla para que, si el elemento no está, 
        devuelva la posición donde DEBERÍA ir. 
        Eso sirve para insertar manteniendo el orden, y lo van a necesitar en su proyecto. */
    //si no lo encuentra, devuelve la posición donde debería ir.
    }else {
        if (target < arr[mid]){
            return mid + 1;
            //se le suma 1 a mid porque si el target es mayor que el valor de la mitad, debería ir después de mid.
        } else {
            return mid - 1;
            //este se le resta 1 a mid porque si el target es menor que el valor de la mitad, debería ir antes de la posición de mid.
        }
        
    }
}