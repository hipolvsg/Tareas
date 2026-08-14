#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    int color;
    int range;
    int lenght;
    string numStr;
    //declaracion vector de vectores (matriz)
    //no se nombra el vector de dentro porque el computador no lo interpreta, solo tipo de datos (como un int, no se declara con nombre)
    vector<vector<double>> filas = {{0.14, 0.82, 0.05, 0.67, 0.39, 0.91, 0.23}, {0.48, 0.73, 0.19, 0.85, 0.02, 0.56, 0.94}, {0.31, 0.64, 0.88, 0.12, 0.45, 0.77, 0.50},{0.27, 0.93, 0.41, 0.08, 0.62, 0.15, 0.79}};
    //obtencion indice filas
    for (size_t i = 0; i < filas.size(); i++){
        /grafica
        cout << "________________________________________________________" << endl;
        //obtención indice filasxcolumnas
        for (size_t j = 0; j < filas[i].size(); j++){
            numStr = to_string(filas[i][j]);
            numStr = numStr.substr(0, 4);
            //determinación color según rango de valor
            switch (static_cast<int>((filas [i][j])*10)){
                case 0:
                cout << "|\033[28;5;231m\033[38;5;231m " << numStr << " \033[0m|";
                break;
                case 1:
                cout << "|\033[28;5;230m\033[38;5;230m " << numStr << " \033[0m|";
                break;
                case 2:
                cout << "|\033[28;5;229m\033[38;5;229m " << numStr << " \033[0m|";
                break;
                case 3:
                cout << "|\033[28;5;228m\033[38;5;228m " << numStr << " \033[0m|";
                break;
                case 4:
                cout << "|\033[28;5;227m\033[38;5;227m " << numStr << " \033[0m|";
                break;
                case 5:
                cout << "|\033[28;5;221m\033[38;5;221m " << numStr << " \033[0m|";
                break;
                case 6:
                cout << "|\033[28;5;215m\033[38;5;215m " << numStr << " \033[0m|";
                break;
                case 7:
                cout << "|\033[28;5;209m\033[38;5;209m " << numStr << " \033[0m|";
                break;
                case 8:
                cout << "|\033[28;5;203m\033[38;5;203m " << numStr << " \033[0m|";
                break;
                case 9:
                cout << "|\033[28;5;197m\033[38;5;197m " << numStr << " \033[0m|";
                break;
                case 10:
                cout << "|\033[28;5;196m\033[38;5;196m " << numStr << " \033[0m|";
                break;
                case 11:
                cout << "|\033[28;5;91m\033[38;5;91m " << numStr << " \033[0m|";
                break;
            }
            
            
        }
        //salto de línea
        cout << "\n";
    }
    //grafica
    cout << "________________________________________________________" << endl;
    return 0;
}
