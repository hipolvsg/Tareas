/*RETO 3  ·  Rotar el plano 90 grados   
Contexto: Un mapa de zonas de reciclaje está guardado como matriz, 
pero se necesita imprimirlo girado para que coincida con la orientación real del barrio.
Se pide: Escribir una función que reciba una matriz de f filas por c columnas 
y devuelva una nueva matriz rotada 90 grados en sentido horario. Verificar que {{1,2,3},{4,5,6}} produce {{4,1},{5,2},{6,3}}.
Pista: La matriz resultante tiene c filas y f columnas: las dimensiones se intercambian. 
El elemento de la posición (i,j) termina en la posición (j, f-1-i).*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//declaración de funciones
vector<vector<int>> rotarMatriz(vector<vector<int>>/*& para almacenar matriz en memoria y que quede para siempre cuando se le llame*/& matriz, int f, int c);
void matrizToString(vector<vector<int>> matriz, vector<vector<int>> nuevaMatriz, int f, int c);

int main(){
    string space = " ";
    int maxspace = 0;
    int f = 0;
    int c = 0;
    //entrada de filas y columnas de la matriz
    cout << "Ingrese el número de filas de la matriz: ";
    cin >> f;
    cout << "Ingrese el número de columnas de la matriz: ";
    cin >> c;
    // declaración e inicialización de la matriz y de la nueva matriz rotada
    vector<vector<int>> matriz (f, (vector<int>(c)));
    //llamado a la función que rota la matriz
    vector<vector<int>> nuevaMatriz = rotarMatriz(matriz, f, c);
    //cálculo del espacio para impresion
    for (size_t i = 0; i < f; i++){
        for (size_t j = 0; j < c; j++){
            if (to_string(matriz[i][j]).length() > maxspace){
                maxspace = to_string(matriz[i][j]).length();
            }
        }
    }
    //impresion de las matrices
    matrizToString(matriz, nuevaMatriz, f, c);
    
    return 0;
}
//cout para las matrices
void matrizToString(vector<vector<int>> matriz, vector<vector<int>> nuevaMatriz, int f, int c){
    string space = " ";
    int maxspace = 0;
    for (size_t i = 0; i < f; i++){
        for (size_t j = 0; j < c; j++){
            if (to_string(matriz[i][j]).length() > maxspace){
                maxspace = to_string(matriz[i][j]).length();
            }
        }
    }
    //titulo
    cout << "\t\t\033[92;1mMatriz\033[0m" << endl;
    for (size_t i = 0; i < f; i++){
        for (size_t j = 0; j < c; j++){
            space = " ";
            //cálculo del espacio para impresion
            while (space.length() <= maxspace - to_string(matriz[i][j]).length()){
                space = space + " ";
            }
            //impresion matriz
            cout << matriz[i][j] << space;
        }
        cout << endl;
    }
    //titulo
    cout << "\t\t\033[92;1mNueva Matriz\033[0m" << endl;
    for (size_t i = 0; i < c; i++){
        for (size_t j = 0; j < f; j++){
            space = " ";
            //cálculo del espacio para impresion
            while (space.length() <= maxspace - to_string(nuevaMatriz[i][j]).length()){
                space = space + " ";
            }
            //impresion nuevaMatriz
            cout << nuevaMatriz[i][j] << space;
        }
        cout << endl;
    }
}

vector<vector<int>> rotarMatriz(vector<vector<int>>& matriz, int f, int c){
    vector<vector<int>> nuevaMatriz (c, (vector<int>(f)));
    //entrada de datos de la matriz
    for (size_t i = 0; i < f; i++){
        for (size_t j = 0; j < c; j++){
            int valor;
            cout << "Ingrese el valor de la posición fila [" << i << "], columna[" << j << "]: ";
            cin >> valor;
            matriz[i][j] = valor;
        }
    }
    //rotación de la matriz en nuevo vecotr<vector<int>>
    for (size_t i = 0; i < c; i++){
        for (size_t j = 0; j < f; j++){
            nuevaMatriz[i][j] = matriz[f - 1 - j][i];
        }
    }

    return nuevaMatriz;
}
