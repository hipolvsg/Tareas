/*Se tiene el registro de un mes donde 1 significa que llovió y 0 que no. 
Un ingeniero ambiental necesita saber cuál fue el periodo más largo de días seguidos con lluvia.
Se pide: Encontrar la longitud de la racha más larga de unos consecutivos en el arreglo {0,1,1,0,1,1,1,0,1}.
Pista: Se resuelve con un solo recorrido y dos variables: la racha actual y la mejor racha vista hasta ahora. 
Cuando aparece un 0, la racha actual vuelve a cero.*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    //declaración registro
    vector <int> registroLluvia = {0,1,1,0,1,1,1,0,1};
    int mejorRacha = 0;
    int tempMejorRacha = 0;
    //recorrido vecotr
    for (size_t i = 0; i < registroLluvia.size(); i++){
        //mejor racha aumenta hasta que haya en la posición un 0
        if (registroLluvia[i] == 1){
            tempMejorRacha++;
        }else{
            tempMejorRacha = 0;
        }
        //nuevo record
        if (tempMejorRacha > mejorRacha){
            mejorRacha = tempMejorRacha;
        }
    }
    //salida
    cout << "Mejor Racha = " << mejorRacha << endl;

    return 0;
}
