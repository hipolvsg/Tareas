/*Los códigos de inventario de una biblioteca comunitaria son válidos solo si se leen igual al derecho y al revés.
Se pide: Determinar si un arreglo de números es palíndromo, 
sin crear un segundo arreglo y sin usar funciones de reversa del lenguaje.
Pista: Dos índices que caminan en sentidos opuestos: uno desde el inicio y otro desde el final. 
Se detienen cuando se cruzan.*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    vector<int> num;
    string tempNum;
    bool palindromo = true;
    //entrada
    cout << "Porfavor escriba el número a analizar: ";
    cin >> tempNum;
    //conversion a entero desde caracter (binario)
    for (size_t i = 0; i < tempNum.size(); i++){
        num.push_back((int)tempNum[i]-48);
    }
    //recorrido (evaluación)
    for (size_t j = 0; j < num.size(); j++){
        //verificación error
        if (num[j] != num[num.size()-1-j]){
            palindromo = false;
        }
        //detención al llegar a la mitad del recorrido
        if (j >= num.size() / 2){
            break;
        }

    }
    //salida
    if (palindromo){
        cout << "El número ingresado es palindromo.";
    }else{
        cout << "El número ingresado no es palindromo.";
    }
    return 0;
}
