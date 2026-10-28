#include<iostream>
#include<string>

using namespace std;


struct Nodo {
    string valor;
    Nodo* padre;
    Nodo** hijos;
    int numHijos;
};
//RETO 1
void imprimirJerarquia(Nodo* nodo, int nivel = 0) {
    //caso base: si el nodo es nulo, no hacer nada
    if (nodo == nullptr) return;
    //Sangria
    for (int i = 0; i < nivel; i++) {
        cout << "  ";
    }
    // imprimir el valor del nodo actual
    cout << nodo->valor << "\n";
    
    // imprimir hijos recursivamente
    for (int i = 0; i < nodo->numHijos; i++) {
        imprimirJerarquia(nodo->hijos[i], nivel + 1);
    }
}
//RETO 2
// Función auxiliar para imprimir en Inorden
void imprimirInorden(Nodo* nodo) {
    if (nodo == nullptr) return;

    // encontrar extremo izquierdo
    if (nodo->numHijos > 0 && nodo->hijos[0] != nullptr) {
        imprimirInorden(nodo->hijos[0]);
    }
    //imprime el valor del nodo actual
    cout << nodo->valor << " ";
    // recorre los restantes
    for (int i = 1; i < nodo->numHijos; i++) {
        if (nodo->hijos[i] != nullptr) {
            imprimirInorden(nodo->hijos[i]);
        }
    }
}
void Espejo(Nodo* nodo) {
    //caso base
    if (nodo == nullptr) return;
    //impresión inorden antes de intercambio
    cout << "Antes de intercambio: ";
    imprimirInorden(nodo);
    cout << "\n";
    for (int i = 0; i < nodo->numHijos; i++) {
        Espejo(nodo->hijos[i]);
        if (nodo->hijos[i] != nullptr)
        if (nodo->hijos[i] ==None)
        cout << nodo->valor << "\n" << endl;
    }
    //intercambia los hijos del nodo actual
    for (int i = 0; i < nodo->numHijos / 2; i++) {
        Nodo* temp = nodo->hijos[i];
        nodo->hijos[i] = nodo->hijos[nodo->numHijos - i - 1];
        nodo->hijos[nodo->numHijos - i - 1] = temp;
    }
    //recorre sus hijos recursivamente
    for (int i = 0; i < nodo->numHijos; i++) {
        Espejo(nodo->hijos[i]);
    }
    cout << "Después de intercambio: ";
    imprimirInorden(nodo);
    cout << "\n";
}
//Reto 3
bool sonIguales(Nodo* nodo1, Nodo* nodo2) {
    // Caso base 1, ambos son vacios
    if (nodo1 == nullptr && nodo2 == nullptr) return true;
    // Caso base 2, uno es vacio y el otro no
    if (nodo1 == nullptr || nodo2 == nullptr) return false;
    // Caso base 3, los valores primeros de los nodos no coinciden
    if (nodo1->valor != nodo2->valor) return false;
    // Caso base 4, el número de hijos no coincide
    if (nodo1->numHijos != nodo2->numHijos) return false;
    //caso recurisvo, recorre cada uno empleando los casos base para verificar igualdad
    for (int i = 0; i < nodo1->numHijos; i++) {
        if (!sonIguales(nodo1->hijos[i], nodo2->hijos[i])) return false;
    }
    return true;
}





/**
 * Implementación de un árbol genérico
 * con funciones para recorrido en preorden, inorden y postorden,
 * así como recorrido por niveles (BFS).
                                           Catalogo(1)

            #Herramienta(2)                                                  #Libros(1)

    #Taladro(2)                   #Sierra(2)                       #Artes(1)                    #Tecnico(2)

#None   #None                  #None     #None                  None      None             None               Redes(2)

                                                                                                             #None   #None

                                                                                

Her (2)
Libro (2)
Tecnico (1)  
 */


//nivel, altura y profundidad en arboles 
//orden: pre/in/post
//niveles: recorrido por nieveles o BFS
//se encola la raiz de los siguientes hijos
//historial arboles con preordenes
//serializarlo
//impresiones de jerarquias indentadas
//escribir pre orden/ in y pos
//

//SESION 35
