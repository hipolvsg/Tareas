#include <iostream>
using namespace std;
//Primera Parte:
int potencia (int base, int exponente, int &iteracionesNormal){
    //caso base

    if (exponente == 0) {
        return 1;
        iteracionesNormal++;
        
    }
    if (exponente == 1){
        return base;
    }
    //caso recursivo
    iteracionesNormal++;
    int resultado = base * potencia(base, exponente - 1, iteracionesNormal);
    return resultado;
}
int potenciaEnhaced(int base, int exponente, int &iteracionesEnhaced){
    //casos base
    if (exponente == 0) {
        iteracionesEnhaced++;
        return 1;
    }
    if (exponente == 1){
        iteracionesEnhaced++;
        return base;
    }
    //caso recursivo
    if (exponente % 2 == 1){
        iteracionesEnhaced++;
        int resultado = base * potenciaEnhaced(base, exponente - 1, iteracionesEnhaced);
        return resultado;
    }
    // caso par
    iteracionesEnhaced++;
    int mitad = potenciaEnhaced(base, exponente / 2, iteracionesEnhaced);
    return mitad * mitad;
}

int main(){
    int base = 5, exponente = 14;
    int iteracionesNormal = 0;
    int resultado = potencia(base, exponente, iteracionesNormal);
    cout << "\033[1;32mFuncion Normal:\033[0m" << endl;
    cout << "El resultado es: " << resultado << " con " << iteracionesNormal << " iteraciones." << endl;
    int iteracionesEnhaced = 0;
    cout << "\033[1;34mFuncion Enhaced:\033[0m" << endl;
    int resultadoEnhaced = potenciaEnhaced(base, exponente, iteracionesEnhaced);
    cout << "El resultado es: " << resultadoEnhaced << " con " << iteracionesEnhaced << " iteraciones." << endl;
    return 0;
}