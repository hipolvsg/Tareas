/* diccionarios
    datos int,string que puedan usarse en python y cpp
    min max prom
*/
#include <iostream>
using namespace std;
int main(){
    int min;
    int max;
    int prom;
    int m = 0;
    //creación del arreglo
    int array[7] ={1, 23, 5, 6, 17, 9, 10};
    //inicialización máximo y mínimo
    min, max = array[0];
    //bucle definido tamaño arreglo
    for (int n = 0; n < 7; n++){
        //comparación < y > de maximo y minimo
        if (array[n]< min){
            min = array[n];
        }     
        if (array[n]> max){
            max = array[n];
        }
        //suma de todos sus elementos
        m = m + array[n];
    }
    //calculo media
    prom = m / 7;
    //salida
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Prom: " << prom << endl; 
    return 0;
            
}
