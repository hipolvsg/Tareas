#include <iostream>
#include <string>
#include <tuple>
using namespace std;

class NodoDoble {
public:
    // Variable para almacenar la información del nodo
    string Elemento;
    /*Punteros para el siguiente y anterior nodo*/ 
    NodoDoble* next;
    NodoDoble* prev;
    NodoDoble(string act) {
        Elemento = act;
        next = nullptr;
        prev = nullptr;
    }
};
class PilaDoble {
public:
    NodoDoble* cima;
    PilaDoble() {
        // Inicializar la cima de la pila
        cima = nullptr;
    }
    void apilar(string act) {
        // Crear un nuevo nodo con el elemento a apilar
        NodoDoble* nuevo = new NodoDoble(act);
        if (cima != nullptr) {
            // Establecer el puntero previo del nuevo nodo a la cima actual de la pila
            nuevo->prev = cima;
            // Enlazar el nuevo nodo con la cima actual de la pila
            cima->next = nuevo;
        }
        // Actualizar la cima de la pila al nuevo nodo
        cima = nuevo;
    }
    void desapilar() {
        // Verificar si la pila no está vacía antes de desapilar
        if (cima != nullptr) {
            // Guardar el nodo a borrar 
            NodoDoble* aBorrar = cima;
            // Actualizar la cima de la pila al nodo anterior
            cima = cima->prev;
            if (cima != nullptr) {
                // Desenlazar el nodo a borrar
                cima->next = nullptr;
            }
            // Liberar la memoria del nodo a borrar
            delete aBorrar;
        }
    }
    string obtenerCima() {
        // Devolver el elemento en la cima de la pila, si existe
        if (cima != nullptr) {
            return cima->Elemento;
        }
        return "";
    }
    bool vacia() {
        return cima == nullptr;
    }
};
auto operacion (string problema) -> tuple<string, char, string> {
    string numeros = "0123456789";
    string x = "";
    string y = "";
    char operacion;
    for (char c : problema) {
        for (char d : numeros) {
            if (c == d){
                x += c;
            }
            if (c == ' '){
                continue;
            }
        }
    }
    for (char c : problema) {
        if (c == '+' || c == '-' || c == '*' || c == '/') {
            operacion = c;
            break;
        }
    }
    for (char c : problema) {
        for (char d : numeros) {
            if (c == d && x.find(c) == string::npos) {
                y += c;
            }
        }
    }

    return make_tuple(x, operacion, y); 
}
void notacionPolacaInversa(tuple<string, char, string> problema) {
    auto [x, oper, y] = problema;
    cout << "Notación polaca inversa: " << x << " " << y << " " << oper << endl;
}
int main(){
    string problema;
    cout << "Ingrese un problema aritmético: ";
    getline(cin, problema);
    auto [x, oper, y] = operacion(problema);
    cout << "Primer número: " << x << endl;
    cout << "Operación: " << oper << endl;
    cout << "Segundo número: " << y << endl;
    notacionPolacaInversa(operacion(problema));
}