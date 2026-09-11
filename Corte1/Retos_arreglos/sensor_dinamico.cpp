/*Estacion calidad aire valor -999*/

#include <iostream>
#include <vector>

using namespace std;

int main(){

    int suma = 0;
    int datosValidos = 0;
    int promedio = 0;
    int tempRegistro;
    int confirmation = 1;
    vector<int> repLecturas;

    cout << "Gracias por usar nuestro software :D" << endl;

    while (confirmation == 1){
        cout << "Porfavor digite la lectura del sensor: ";
        cin >> tempRegistro;
        if (cin.fail()){
            cin.ignore(1000, '\n');
            cin.clear();
            cerr << "Tipo de dato inválido";
        }
        repLecturas.push_back(tempRegistro);
        cout << "registrar otro dato? digite: cualquier tecla + Enter (si) \"0\" + Enter (no)";
        cin >> confirmation;
        if (cin.fail()){
            cin.ignore(1000, '\n');
            cin.clear();
            cerr << "Tipo de dato inválido";
        }
    }

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