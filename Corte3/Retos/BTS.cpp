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
/* Implemente listarOrdenado() e informe(codigo) 
que imprima el nombre o un mensaje de no encontrado, indicando cuántas comparaciones hizo.*/ 

//Reto 1

void listarOrdenado(Nodo* n) {
    vector<int> s;
    //organiza y asigna
    inorden(n, s);
    //imprime
    verLista("Listado ordenado:", s);
}

void informe(Nodo* n, int codigo) {
    //vector para guardar un "camino" de comparaciones durante la búsqueda
    vector<string> p;
    //asginsa
    Nodo* r = buscar(n, codigo, &p);
    //Imprime flag de entrada a informe
    cout << "informe( " << codigo << " ): ";
    //si encuentra, da nombre
    if (r) cout << "Nombre = " << r->nombre << endl;
    //si no, indica no encontrado 
    else cout << "\033[1;31mNO ENCONTRADO!!\033[0m" << endl;
    cout << "se hicieron: (" << p.size() << ". comparaciones)" << endl;
}

//Reto 2
//similar a bucket

vector<int> Rango(Nodo* nodo, int start, int target) {
    int visitados = 1; 
    vector<int> s;
    //caso base
    if (!nodo) return s;
    if (nodo->clave > start) {
        vector<int> izq = Rango(nodo->izq, start, target);
        visitados += izq.size(); //suma los nodos visitados en el sub izq, agregandolos recursivamente a s
        //inserta al final los elementos del subarbol izq
        s.insert(s.end(), izq.begin(), izq.end());
    }
    //si la clave del nodo está dentro del rango, la agrega a s
    if (nodo->clave >= start && nodo->clave <= target) s.push_back(nodo->clave);
    //si la clave del nodo es menor que target, revisa el subárbol derecho recursivamente
    if (nodo->clave < target) {
        vector<int> der = Rango(nodo->der, start, target);
        visitados += der.size();
        s.insert(s.end(), der.begin(), der.end());
    }
    return s;
}

//reto 3

bool esBST(Nodo* nodo, int min, int max) {
    if (!nodo) return true;
    //Si la clave es el mismo nodo o no está en el rango, es inválido como BST
    if (nodo->clave <= min || nodo->clave >= max) return false;
    return esBST(nodo->izq, min, nodo->clave) && esBST(nodo->der, nodo->clave, max);
}


int main() {
    Nodo* raiz = nullptr;
    for (int c : {50, 30, 70, 20, 40, 60, 80, 35, 45, 55}) raiz = insertar(raiz, c);
    cout << "proceso: listarOrdenado" << endl;
    listarOrdenado(raiz);

    cout << "proceso: informe" << endl;
    informe(raiz, 40);

    cout << "proceso: Rango" << endl;
    vector<int> rango = Rango(raiz, 20, 60);
    verLista("Rango [20,60]:", rango);

    cout << "proceso: esBST" << endl;
    cout << esBST(raiz, -2147483648, 2147483647) << endl;

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