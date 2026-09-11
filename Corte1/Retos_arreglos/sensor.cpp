/*Estacion calidad aire valor -999*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int suma = 0;
    int datosValidos = 0;
    int promedio = 0;
    vector<int> repLecturas = {20, -999, 22, 24, -999, 26};
    
    for (size_t i = 0; i < repLecturas.size(); i++){
        if (repLecturas[i] == -999){
        }else{
            suma = suma + repLecturas[i];
            ++datosValidos;
        }
    }
    promedio = (double)suma/datosValidos;
    cout << "Promedio = " << promedio << "." << endl; 
    cout << "Se descartaron " << (repLecturas.size()- datosValidos) << " lecturas." << endl;
    return 0;
}