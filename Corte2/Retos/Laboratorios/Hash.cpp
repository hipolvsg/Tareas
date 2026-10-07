//En parejas, cada estudiante adapta la TablaHash del Momento 1 a un caso nuevo y descubre por sí mismo dos lecciones: 
//una función hash que mira la parte repetida de la clave lo amontona todo, y redimensionar no arregla una mala función hash. 
//Una persona de la pareja trabaja en Python y la otra en C++; al final comparan salidas. 
// Enunciado La universidad quiere encontrar a un estudiante por su código en tiempo constante. 
// Los códigos tienen la forma EST-2026-0101 … EST-2026-0112. EST-2026-0101 Ana Torres EST-2026-0107 Pedro Ruiz 
// EST-2026-0102 Carlos Rojas EST-2026-0108 Camila Diaz EST-2026-0103 Diego Pardo EST-2026-0109 Luis Herrera 
// EST-2026-0104 Sofia Mejia EST-2026-0110 Valentina Cruz EST-2026-0105 Juan Gomez EST-2026-0111 Andres Vega 
// EST-2026-0106 Maria Lopez EST-2026-0112 Laura Castro
//
//Cargar. Partiendo de la TablaHash del Momento 1 con capacidad 8, inserten los 12 estudiantes (código → nombre) 
// y busquen EST-2026-0107.
//
//Redimensionar. Agreguen el método redimensionar: cuando el factor de carga pase de 0,75, duplican la capacidad 
// y vuelven a insertar todo. Usen esta plantilla: Python: def _redimensionar(self): viejas = self.cubetas 
// # TODO 1: duplicar self.cap # TODO 2: crear cubetas vacias nuevas y poner self.n en 0 
// # TODO 3: recorrer 'viejas' e insertar cada (clave, valor) otra vez
// 
// Implementación de la TablaHash en C++

#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <list>

using namespace std;

class TablaHash{
private:
    int cap;
    int n;
    std::vector<std::list<std::pair<std::string, std::string>>> cubetas;
public:
    TablaHash(int capacidad=8):cap(capacidad),n(0),cubetas(capacidad){}

int hashear(const string & clave) const {
        unsigned long long h = 0;
        for (unsigned char c : clave) h = (h * 31 + c) % cap;
        return (int)h;
    }
    void insertar(const string& clave, const string& valor) {
        int i = hashear(clave);
        for (auto& par : cubetas[i]) {
            if (par.first == clave) { par.second = valor; return; }   // ACTUALIZA
        }
        cubetas[i].push_back({clave, valor});
        n++;
    }
    bool buscar(const string& clave, string& salida) const {
        int i = hashear(clave);
        for (const auto& par : cubetas[i]) {
            if (par.first == clave) { salida = par.second; return true; }
        }
        return false;
    }
    bool eliminar(const string& clave) {
        int i = hashear(clave);
        for (auto it = cubetas[i].begin(); it != cubetas[i].end(); ++it) {
            if (it->first == clave) { cubetas[i].erase(it); n--; return true; }
        }
        return false;
    }
    //redimensionar, sugerencia de la IA porque no alcancé
    void redimensionar() {
        int nueva_cap = cap * 2;
        std::vector<std::list<std::pair<std::string, std::string>>> nuevas_cubetas(nueva_cap);
        for (const auto& cubeta : cubetas) {
            for (const auto& par : cubeta) {
                int i = 0;
                unsigned long long h = 0;
                for (unsigned char c : par.first) h = (h * 31 + c) % nueva_cap;
                i = (int)h;
                nuevas_cubetas[i].push_back(par);
            }
        }
        cubetas = std::move(nuevas_cubetas);
        cap = nueva_cap;
    }
    double factor_carga() const {
        //static_cast convierte de forma 
        return static_cast<double>(n) / cap;
    }
    void verificar_redimension() {
        if (factor_carga() > 0.75) {
            redimensionar();
        }
    }
};
// _hash("EQ100") cap=8

int main(){
    vector<string> nombres;
    vector<string> codigos;
    TablaHash tabla;
    string Key = "EST-2026-0107";
    tabla.verificar_redimension();
    for (size_t i = 0; i < codigos.size(); ++i) {
        tabla.insertar(codigos[i], nombres[i]);
        tabla.verificar_redimension();
    }
    string salida;
    if (tabla.buscar(Key, salida)) {
        cout << "Encontrado: " << salida << endl;
    } else {
        cout << "No encontrado" << endl;
    }
}







