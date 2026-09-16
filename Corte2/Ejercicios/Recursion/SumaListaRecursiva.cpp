#include <iostream>
#include <vector>
using namespace std;
//suma recursiva con vector y resultado como parametros con valores predeterminados en caso de faltar argumentos
int sumaRecursiva(vector<int> vector = {}, int resultado = 0){
    //caso base
    if (vector.empty()) {
        return 0;
    }
    //caso recursivo
    int ref = vector.size();
    //dado que resultado se inicia en 0, se acumula en cada iteración recursiva
    resultado = vector[ref - 1] + resultado;
    vector.pop_back();
    if (ref == 1){
        return resultado;
    }
    return sumaRecursiva(vector, resultado);
}

int main(){
    int resultado = 0;
    vector<int> numeros = {};
    for (int i = 0; i < 100; i++) {
        numeros.push_back(i+1);
    }
    resultado = sumaRecursiva(numeros);
    cout << "La suma de la lista es: " << resultado << endl;

    return 0;
}