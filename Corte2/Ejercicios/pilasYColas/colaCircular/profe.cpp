#include <iostream>
#include <string>
using namespace std;

const int CAPACIDAD = 5;

class ColaCircular {
private:
    string datos[CAPACIDAD];
    int frente;
    int cantidad;

public:
    ColaCircular(int frenteInicial) {
        frente = frenteInicial;
        cantidad = 0;
        for (int i = 0; i < CAPACIDAD; i++) datos[i] = "-";
    }

    bool estaLlena() { return cantidad == CAPACIDAD; }
    bool estaVacia() { return cantidad == 0; }

    int siguientePosicion() {
        return (frente + cantidad) % CAPACIDAD;
    }

    void encolar(string valor) {
        if (estaLlena()) {
            cout << "Error: la cola esta llena, no se puede encolar " << valor << endl;
            return;
        }
        int pos = siguientePosicion();
        datos[pos] = valor;
        cantidad++;
        cout << "Encolado " << valor << " en la posicion " << pos << endl;
    }

    void mostrar() {
        cout << "Arreglo: ";
        for (int i = 0; i < CAPACIDAD; i++) {
            cout << "[" << i << ":" << datos[i] << "] ";
        }
        cout << endl;
        cout << "Frente = " << frente << ", cantidad = " << cantidad << endl;
    }
};

int main() {
    // Estado del ejercicio: capacidad 5, frente en 3, cuatro elementos
    ColaCircular cola(3);
    cola.encolar("A");
    cola.encolar("B");
    cola.encolar("C");
    cola.encolar("D");

    cout << "\nEstado actual de la cola:" << endl;
    cola.mostrar();

    cout << "\nCalculo: (frente + cantidad) % capacidad = (3 + 4) % 5 = "
         << cola.siguientePosicion() << endl;

    cout << "\nEncolando el siguiente elemento:" << endl;
    cola.encolar("E");
    cola.mostrar();

    cout << "\nRespuesta: el siguiente elemento se guarda en la posicion 2" << endl;
    return 0;
}