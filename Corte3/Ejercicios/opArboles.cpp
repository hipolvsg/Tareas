#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    private:
        string valor;
        Nodo* padre;
        Nodo** hijos;
        int numHijos;
    public:
};
void InsertarHijo(Nodo* padre, Nodo* hijo) {
    
    if (padre == nullptr || hijo == nullptr) return;
    hijo->padre = padre;
    Nodo** nuevosHijos = new Nodo*[padre->numHijos + 1];
    for (int i = 0; i < padre->numHijos; i++) {
        nuevosHijos[i] = padre->hijos[i];
    }
    nuevosHijos[padre->numHijos] = hijo;
    delete[] padre->hijos;
    padre->hijos = nuevosHijos;
    padre->numHijos++;
}

