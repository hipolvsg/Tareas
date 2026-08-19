/*RETO 2  ·  La diagonal secreta   
Contexto: Un sistema sencillo de verificación usa las diagonales de una matriz cuadrada como código de control.
Se pide: Dada una matriz cuadrada, calcular la suma de la diagonal principal y la de la diagonal secundaria, 
y determinar si son iguales. Probar con {{1,2,3},{4,5,6},{7,8,9}}.
Pista: La diagonal principal son las posiciones donde fila e índice coinciden. 
Para la secundaria, cuando la fila avanza la columna retrocede: piensen en n-1-i.*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int principal = 0;
    int secundaria = 0;
    int contraseña = 0;
    int numeroFilas = 0;
    int numeroColumnas = 0;
    vector<vector<int>> matriz;

    //entrada tamaño matriz
    cout << "Digite el número de filas de la matriz: ";
    cin >> numeroFilas;
    cout << "Digite el número de columnas de la matriz: ";
    cin >> numeroColumnas;
    //verificacion matriz cuadrada
    if (numeroFilas != numeroColumnas){
        cout << "La matriz no es cuadrada, no es posible el caclulo." << endl;
        return 0;
    }
    
    matriz.resize(numeroFilas, vector<int>(numeroColumnas));
    
    // entrada de datos de la matriz
    for (size_t i = 0; i < numeroFilas; i++){
        for (size_t j = 0; j < numeroColumnas; j++){
            int valor;
            cout << "Ingrese el valor de la posición fila [" << i << "], columna[" << j << "]: ";
            cin >> valor;
            matriz[i][j] = valor;
        }
    }
    // procesamiento de la matriz (suma diagonales)
    for (size_t i = 0; i < numeroFilas; i++){
        for (size_t j = 0; j < numeroColumnas; j++){
            if (i == j){
                principal = principal + matriz[i][j];
            }
            if (j == numeroColumnas - 1 - i){
                secundaria = secundaria + matriz[i][j];
            }
        }
    }
    //verificacion de la contraseña
    if (principal == secundaria){
        cout << "La contraseña es válida." << endl;
    } else {
        cout << "La contraseña es inválida." << endl;
    }
    return 0;

}  
