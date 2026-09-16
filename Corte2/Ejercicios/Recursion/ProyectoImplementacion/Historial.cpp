#include "Historial.h"

//los dos puntos es como cuando usamos std, y no usamos using namespace std; para no tener que escribir std::cout, std::string, etc.

/*  IMPORTANTE:
    COMPORTAMIENTO NODO:
    root -> next -> next -> next -> ... -> nullptr
    root <- prev <- prev <- prev <- ... <- nullptr
    root es el primer nodo, next apunta al siguiente nodo, prev apunta al nodo anterior,
    y nullptr indica el final de la lista (no hay más nodos).
*/

// Constructor
NodoDoble::NodoDoble(string act) {
    //this->accion(atributo) = act(parametro)
    this->accion = act;
    // Inicializar los punteros next y prev a nullptr
    this->next = nullptr;
    this->prev = nullptr;
}

ListaDobleHistorial::ListaDobleHistorial() {
    // Inicializar los punteros head y tail a nullptr
    head = nullptr;
    tail = nullptr;
}

ListaDobleHistorial::~ListaDobleHistorial() {
    // Liberar memoria de todos los nodos de la lista
    NodoDoble* actual = head;
    // Recorrer la lista y eliminar cada nodo
    while (actual != nullptr) {
        // Guardar el siguiente nodo antes de eliminar el actual
        NodoDoble* siguiente = actual->next;
        // Eliminar el nodo actual
        delete actual;
        // Avanzar al siguiente nodo
        actual = siguiente;
    }
}
// Método para agregar una acción al historial
void ListaDobleHistorial::agregarAccion(string accion) {
    // Crear un nuevo nodo con la acción proporcionada
    NodoDoble* nuevo = new NodoDoble(accion);
    // Verificar si la lista está vacía (head es nullptr)
    if (head == nullptr) {
        // Si la lista está vacía, el nuevo nodo será tanto el head como el tail
        head = tail = nuevo;
    } else {
        // Si la lista no está vacía, agrega el nuevo nodo al final de la lista ()
        tail->next = nuevo;
        // Establecer el puntero previo del nuevo nodo al nodo actual tail
        nuevo->prev = tail;
        // Actualizar el puntero tail para que apunte al nuevo nodo
        tail = nuevo;
    }
}

// Método para navegar hacia adelante en el historial (desde el nodo más antiguo hasta el más reciente)

void ListaDobleHistorial::navegarAdelante() {
    //si está vacio, mostrar mensaje y salir
    if (head == nullptr) {
        cout << "El historial esta vacio." << endl;
        return;
    }
    //si no, llama a la función que imprime la acción almacenada en el nodo actual y llama recursivamente a la función con el nodo siguiente
    cout << "\n[Historial: Mas antiguo -> Mas reciente]" << endl;
    navegarAdelante(head);
}

void ListaDobleHistorial::navegarAdelante(NodoDoble* temp) {
    if (temp == nullptr) {
        return;
    }
    cout << " -> " << temp->accion << endl;
    navegarAdelante(temp->next);
}
// Método para navegar hacia atrás en el historial (desde el nodo más reciente hasta el más antiguo)
//para cumplir con poder deshacer accion (último movimiento hecho))
//emplear recursión para navegar hacia atrás en el historial
void ListaDobleHistorial::navegarAtras() {
    //si está vacio, mostrar mensaje y salir
    if (tail == nullptr) {
        cout << "El historial esta vacio." << endl;
        return;
    }
    //si no, llama a la función que imprime a la acción almacenada en el nodo actual y llama recursivamente a la función con el nodo previo
    cout << "\n[Historial: Mas reciente -> Mas antiguo]" << endl;
    navegarAtras(tail);
}


void ListaDobleHistorial::navegarAtras(NodoDoble* temp) {
    if (temp == nullptr) {
        return;
    }
    cout << " -> " << temp->accion << endl;
    navegarAtras(temp->prev);
}