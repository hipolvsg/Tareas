#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    
    int tempFranja = 0;
    int franjaMax = 0;
    int posFranjaMax = 0; // Se añade para guardar el índice de la franja
    int posDiaFranjaMax = 0; // Se añade para guardar el índice del día
    int tempDia = 0;
    int diaMax = 0;
    int posDiaMax = 0; // Se añade para guardar el índice del día con mayor ocupación
    //declaración de la matriz de registro y de los vectores de franjas y días
    vector<string> dias = {"Lunes", "Martes", "Miércoles", "Jueves", "Viernes"};
    vector<string> franjas = {"7:00-8:30", "8:30-10:00", "10:00-11:30", "11:30-13:00", "13:00-14:30", "14:30-16:00"};
    vector<int> franjasBajas;
    vector<vector<int>> sala(5, vector<int>(6));

    cout << "Gracias por preferirnos :D" << endl;

    //entrada datos de la matriz
    for (size_t i = 0; i < sala.size(); i++){
        for (size_t j = 0; j < sala[i].size(); j++){
            cout << "Ingrese la cantidad de personas en la franja " << franjas[j] << " del día " << dias[i] << ": ";
            cin >> sala[i][j];
        }
    }
    //procesamiento datos de la matriz
    for (size_t i = 0; i < sala.size(); i++){
        for (size_t j = 0; j < sala[i].size(); j++){
            tempFranja = sala[i][j];
            if (tempFranja > franjaMax){
                franjaMax = tempFranja;
                posDiaFranjaMax = i; // Guardar la fila (día)
                posFranjaMax = j;    // Guardar la columna (franja)
            }
            tempDia = tempDia + sala[i][j];
            
            // Evaluar franja baja individualmente dentro del ciclo de la columna
            if (tempFranja < 5){
                franjasBajas.push_back(j); // Se guarda j (la franja), no i
            }
        }
        
        if (tempDia > diaMax){
            diaMax = tempDia;
            posDiaMax = i; // Guardar la fila (día con mayor suma)
        }
        tempFranja = 0;
        tempDia = 0;
    }
    //salida franja con menos de 5 personas
    if (franjasBajas.size() == 0){
        cout << "No hubo franjas con menos de 5 personas." << endl;
    }
    else{
        cout << "\t\t\t\033[93;1m FRANJAS CON MENOS DE 5 PERSONAS\033[0m" << endl;
    }
    for (size_t i = 0; i < franjasBajas.size(); i++){
        cout << "La franja " << franjas[franjasBajas[i]] << " estuvo por debajo de 5 personas." << endl;
    }
    //salida franja más congestionada
    cout << "\t\t\t\033[93;1m FRANJA MÁS CONGESTIONADA\033[0m" << endl;
    cout << "La franja más congestionada fue la franja " << franjas[posFranjaMax] << " del día " << dias[posDiaFranjaMax] << " con " << franjaMax << " personas." << endl;
    //salida día con mayor ocupación
    cout << "\t\t\t\033[93;1m DÍA CON MAYOR OCUPACIÓN\033[0m" << endl;
    cout << "El día con mayor ocupación fue el día " << dias[posDiaMax] << " con " << diaMax << " personas." << endl;

    return 0;
}