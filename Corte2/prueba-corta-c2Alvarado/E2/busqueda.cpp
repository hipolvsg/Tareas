// ============================================================
//  Prueba corta · Segundo corte · EJERCICIO 2  (25 puntos)
//  Tema: busqueda binaria
//  Sistema: RedAcopio — localizacion de codigos de material
//
//  Este archivo NO tiene main(): el main esta en pruebas_e2.cpp
//  NO MODIFIQUE el archivo pruebas_e2.cpp
//  Compile y ejecute:
//     g++ -std=c++17 -g -o pruebas_e2 busqueda.cpp pruebas_e2.cpp
//     ./pruebas_e2
//
//  Se reportan DOS fallas:
//   1. Devuelve -1 para codigos que si estan en el arreglo.
//   2. Con algunos valores el sanitizer aborta el programa.
// ============================================================

int buscarCodigo(int v[], int n, int x) {
    //se estaba usando con la cantidad de elementos y no con el último valor de indexación
    int izq = 0, der = n - 1;                        // <-- revise
    while (izq <= der) {                         // <-- revise
        int medio = (izq + der) / 2;
        if (v[medio] == x) return medio;
        //error: casos invertidos 
        if (v[medio] < x) izq = medio + 1;       // <-- revise
        //error: no se cubrían todos los caso (cuando no está fuera del rango estimado o no existe en el arreglo)
        else  if (v[medio] > x) der = medio - 1;       // <-- revise
        else return -1;
    }
    return -1;
}