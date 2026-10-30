//Balanceo de árboles: introducción y rotaciones AVL
//8, 10, 12, 15, 17, 20, 25
//AVL adelson-velsky-landis

/*int  alt(Nodo* n)    { return n == nullptr ? -1 : n->alt; }
int  fe(Nodo* n)     { return n == nullptr ? 0 : alt(n->izq) - alt(n->der); }
void recalc(Nodo* n) { n->alt = 1 + max(alt(n->izq), alt(n->der)); }*/

// fe > 0   -> pesa la izquierda
// fe < 0   -> pesa la derecha
// abs(fe) > 1 -> hay que rotar


/*
fe +2  +1 nodo  LL izquierda-izquierda rotacion derecha
fe -2 -1nodo RR derecha-derecha  rotacion a la izquierda
fe +2 -1  nodo LR izquierda-derecha  rotacion izquierda sobre el hijo y luego derecha sobre el nodo
fe -2 +1  nodo RL derecha -izquierda rotacion derecha sobre el hijo y luego a la izquierda sobre el nodo 

*/

//10,20,30
/*
1. implementar alt fe recalc
2. implementar rotar a la derecha y rotar a la izquierda respetando el orden de recal
3. construir los 4 arboles desbalanceados y aplicamos la rotacion que corresponda
4. imprimir el preorden con fe de cada nodo antes y despues y el inorden de cada paso
5. comprobar que el inorden es 10,20,30 en todos los 4 casos
*/
    



//Ejercicio
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Nodo {
    int clave; Nodo *izq, *der; int alt;
    Nodo(int c) : clave(c), izq(nullptr), der(nullptr), alt(0) {}
};
int  alt(Nodo* n)   { return n == nullptr ? -1 : n->alt; }
int  fe(Nodo* n)    { return n == nullptr ? 0 : alt(n->izq) - alt(n->der); }
void recalc(Nodo* n){ n->alt = 1 + max(alt(n->izq), alt(n->der)); }

Nodo* rotarDerecha(Nodo* y) {
    //        y                x
    //       / \              / \
    //      x   C    ==>     A   y
    //     / \                  / \
    //    A   B                B   C
    Nodo* x = y->izq; Nodo* B = x->der;
    x->der = y; y->izq = B;
    recalc(y); recalc(x);        // primero el que baja, luego el que sube
    return x;
}
Nodo* rotarIzquierda(Nodo* x) {
    Nodo* y = x->der; Nodo* B = y->izq;
    y->izq = x; x->der = B;
    recalc(x); recalc(y);
    return y;
}
void inorden(Nodo* n, vector<int>& s) {
    if (!n) return; inorden(n->izq, s); s.push_back(n->clave); inorden(n->der, s);
}
void preorden(Nodo* n, vector<string>& s) {
    if (!n) return;
    s.push_back(to_string(n->clave) + "(fe=" + to_string(fe(n)) + ")");
    preorden(n->izq, s); preorden(n->der, s);
}
void liberar(Nodo* n) { if (!n) return; liberar(n->izq); liberar(n->der); delete n; }

void ver(const string& titulo, Nodo* r) {
    vector<string> s; preorden(r, s);
    vector<int> t; inorden(r, t);
    cout << "  " << titulo; for (size_t i = titulo.size(); i < 22; i++) cout << ' ';
    cout << " preorden: "; for (auto& x : s) cout << x << ' ';
    cout << "\n  "; for (int i = 0; i < 22; i++) cout << ' ';
    cout << " inorden : [";
    for (size_t i = 0; i < t.size(); i++) { cout << t[i]; if (i + 1 < t.size()) cout << ", "; }
    cout << "]   altura=" << alt(r) << endl;
}

int main() {
    cout << "CASO LL  (pesado a la izquierda-izquierda)  ->  una rotacion DERECHA" << endl;
    Nodo* r = new Nodo(30); r->izq = new Nodo(20); r->izq->izq = new Nodo(10);
    recalc(r->izq->izq); recalc(r->izq); recalc(r);
    ver("antes (fe raiz = 2)", r); r = rotarDerecha(r); ver("despues", r); liberar(r);

    cout << "\nCASO RR  (pesado a la derecha-derecha)      ->  una rotacion IZQUIERDA" << endl;
    r = new Nodo(10); r->der = new Nodo(20); r->der->der = new Nodo(30);
    recalc(r->der->der); recalc(r->der); recalc(r);
    ver("antes (fe raiz = -2)", r); r = rotarIzquierda(r); ver("despues", r); liberar(r);

    cout << "\nCASO LR  (izquierda-derecha)  ->  IZQUIERDA sobre el hijo, luego DERECHA sobre la raiz" << endl;
    r = new Nodo(30); r->izq = new Nodo(10); r->izq->der = new Nodo(20);
    recalc(r->izq->der); recalc(r->izq); recalc(r);
    ver("antes (fe raiz = 2)", r);
    r->izq = rotarIzquierda(r->izq); recalc(r); ver("tras rotar el hijo", r);
    r = rotarDerecha(r); ver("despues", r); liberar(r);

    cout << "\nCASO RL  (derecha-izquierda) ->  DERECHA sobre el hijo, luego IZQUIERDA sobre la raiz" << endl;
    r = new Nodo(10); r->der = new Nodo(30); r->der->izq = new Nodo(20);
    recalc(r->der->izq); recalc(r->der); recalc(r);
    ver("antes (fe raiz = -2)", r);
    r->der = rotarDerecha(r->der); recalc(r); ver("tras rotar el hijo", r);
    r = rotarIzquierda(r); ver("despues", r); liberar(r);
    //quiz 30/10 
    //reto desarrollo
    int a, b, c;
    cout << "\033[1;34mRETO\033[0m Rotación Manual: ";
    cout << "Ingrese la clave A, presione Enter, luego repita las instrucciones para las claves de B y C: ";
    cin >> a >> b >> c;
    //raiz
    Nodo* d = new Nodo(a);
    //hijo izquierdo
    d->izq = new Nodo(b);
    //nieto derecho
    d->izq->der = new Nodo(c);
    //recalcular alturas y fe
    recalc(d->izq->der); recalc(d->izq); recalc(d);
    ver("antes (fe raiz = 2)", d);
    d->izq = rotarIzquierda(d->izq); recalc(d); ver("tras rotar el hijo", d);
    d = rotarDerecha(d); ver("despues", d); liberar(d);
    return 0;
}
