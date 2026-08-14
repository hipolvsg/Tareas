#include <iostream>
#include <string>
#include <vector>

using namespace std;

//declaración funciones

void error();

int leerEnteroPositivo(const string& mensaje);

int main() {
    //declaración e inicialización mensaje para entrada de datos
    string msg = ""; 
    //decimal para encontrar porcentaje segun capacidad
    double porcentaje = 0.0;
    //declaración vector
    vector<vector<int>>/*declaración matriz estática a traves de vectores*/ /*(*/uso(3, vector<int>(5)); /*)*/
    //nomnbre para cout
    vector<string> nombresRecursos = {"Computador", "VideoBeam", "Sala"};

    //
    cout << "Por favor especifique la capacidad de uso para cada dispositivo\n";
    int capComputador = leerEnteroPositivo("Digite capacidad para computador: ");
    int capVideoBeam = leerEnteroPositivo("Digite capacidad para VideoBeam: ");
    int capSala = leerEnteroPositivo("Digite capacidad para Sala: ");

    vector<int> capacidades = {capComputador, capVideoBeam, capSala};

    cout << "\n\033[1m\t\tINGRESO DE DATOS DE USO \n";
    
    // Bucle anidado para cout de uso (Recurso x Dia)
    for (int recurso = 0; recurso < 3; recurso++) {
        cout << "\n--- Registro para: " << nombresRecursos[recurso] << " ---\n";
        for (int dias = 0; dias < 5; dias++) {
            //string para poder emplear el for dentro del mensaje
            msg = "Digite uso para el Dia " + to_string(dias + 1) + ": ";
            uso[recurso][dias] = leerEnteroPositivo(msg);
        }
    }   

    cout << "\n\033[1;33m\t\tREPORTE\033[0m\n";

    // For anidados para el reporte final
    for (int dias = 0; dias < 5; dias++) {
        cout << "\n DIA: (" << dias + 1 << ") \n";
        
        
        for (int recurso = 0; recurso < 3; recurso++) {

            //porcentaje calculado de la recursión por día / capacidad
            if (capacidades[recurso] > 0) {
                porcentaje = ((double)(uso[recurso][dias]) / capacidades[recurso]) * 100.0;
            }
            // salida que tan cargado está el recurso eze día
            cout << "- " << nombresRecursos[recurso] << ": "; 
            cout << uso[recurso][dias] << " / " << capacidades[recurso];
            cout << " asignados (" << porcentaje << "\% de carga)" << endl;
            //En caso de exceso ()
            if (porcentaje > 100.0) {
                cout << "  [ALERTA: Recurso SOBRECARGADO en este dia!]\n";
            }
        }
    }

    return 0;
}
// Limpia el estado de error de cin y vacia el buffer
void error() {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
    }
}
// Leer enteros de forma segura
int leerEnteroPositivo(const string& mensaje) {
    int valor;
    cout << mensaje;
    cin >> valor;

    while (cin.fail() || valor < 0) {
        error();
        cerr << "Entrada invalida. Digite un numero entero valido (>= 0): ";
        cin >> valor;
    }
    return valor;
}