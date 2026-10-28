#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Nodo {
    int clave;
    string nombre;
    Nodo* izq = nullptr;
    Nodo* der = nullptr;
    Nodo(int c, string n = "") : clave(c), nombre(n) {}
};

Nodo* insertar(Nodo* n, int clave, string nombre = "") {
    if (!n) return new Nodo(clave, nombre);
    if (clave < n->clave) n->izq = insertar(n->izq, clave, nombre);
    else if (clave > n->clave) n->der = insertar(n->der, clave, nombre);
    return n;
}

Nodo* buscar(Nodo* n, int clave, vector<string>* pasos = nullptr) {
    if (pasos) pasos->push_back(n ? to_string(n->clave) : "vacio");
    if (!n || n->clave == clave) return n;
    if (clave < n->clave) return buscar(n->izq, clave, pasos);
    return buscar(n->der, clave, pasos);
}

Nodo* minimo(Nodo* n) { while (n->izq) n = n->izq; return n; }
Nodo* maximo(Nodo* n) { while (n->der) n = n->der; return n; }

Nodo* eliminar(Nodo* n, int clave) {
    if (!n) return nullptr;
    if (clave < n->clave) n->izq = eliminar(n->izq, clave);
    else if (clave > n->clave) n->der = eliminar(n->der, clave);
    else {
        if (!n->izq) { Nodo* t = n->der; delete n; return t; }
        if (!n->der) { Nodo* t = n->izq; delete n; return t; }
        Nodo* suc = minimo(n->der);
        n->clave = suc->clave;
        n->nombre = suc->nombre;
        n->der = eliminar(n->der, suc->clave);
    }
    return n;
}

void inorden(Nodo* n, vector<int>& s) {
    if (!n) return;
    inorden(n->izq, s);
    s.push_back(n->clave);
    inorden(n->der, s);
}

int altura(Nodo* n) {
    if (!n) return -1;
    return 1 + max(altura(n->izq), altura(n->der));
}

int hijos(Nodo* n, int clave) {
    Nodo* nodo = buscar(n, clave);
    if (!nodo) return -1;
    return (nodo->izq ? 1 : 0) + (nodo->der ? 1 : 0);
}

void verLista(const string& titulo, const vector<int>& s) {
    cout << titulo << " [";
    for (size_t i = 0; i < s.size(); i++)
        cout << s[i] << (i + 1 < s.size() ? ", " : "");
    cout << "]" << endl;
}

void liberar(Nodo* n) {
    if (!n) return;
    liberar(n->izq);
    liberar(n->der);
    delete n;
}

int main() {
    Nodo* raiz = nullptr;
    for (int c : {50, 30, 70, 20, 40, 60, 80, 35}) raiz = insertar(raiz, c);

    vector<int> s; inorden(raiz, s);
    verLista("Inorden (queda ordenado):", s);
    cout << "minimo = " << minimo(raiz)->clave << "  maximo = " << maximo(raiz)->clave
         << "  altura = " << altura(raiz) << endl;

    for (int objetivo : {40, 65}) {
        vector<string> p;
        Nodo* r = buscar(raiz, objetivo, &p);
        cout << "buscar(" << objetivo << "): camino ";
        for (size_t i = 0; i < p.size(); i++) cout << p[i] << (i + 1 < p.size() ? " -> " : "");
        cout << "  => " << (r ? "ENCONTRADO" : "NO ESTA") << " (" << p.size() << " comparaciones)" << endl;
    }

    const char* NOMBRE[] = {"caso 1: hoja, 0 hijos", "caso 2: un hijo", "caso 3: dos hijos"};
    for (int clave : {20, 30, 50}) {
        int k = hijos(raiz, clave);
        raiz = eliminar(raiz, clave);
        vector<int> t; inorden(raiz, t);
        cout << "eliminar(" << clave << ") [" << NOMBRE[k] << "] -> ";
        verLista("", t);
    }

    Nodo* deg = nullptr;
    for (int c : {10, 20, 30, 40, 50, 60, 70, 80}) deg = insertar(deg, c);
    cout << "\nBTS con datos ordenados: altura = " << altura(deg) << " con 8 nodos (una lista enlazada)" << endl;
    cout << "BTS con datos mezclados: altura = " << altura(raiz) << endl;

    liberar(raiz); liberar(deg);
    return 0;
}