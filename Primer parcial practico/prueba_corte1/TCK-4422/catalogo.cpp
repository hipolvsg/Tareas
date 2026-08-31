// ============================================================
//  Cívica Software  ·  TCK-4422  ·  Severidad P1
//  Sistema: PrestaLab  —  Nueva funcionalidad: catalogo mixto
//  El reporte imprime siempre "Recurso generico". Debe imprimir
//  la descripcion propia de cada tipo.
// ============================================================
#include <iostream>
#include <string>
using namespace std;

/* «Necesitamos que el catálogo maneje libros y equipos, no solo recursos genéricos. De los libros interesa el autor; de los equipos, las horas de uso.» 

«Ahora mismo el listado imprime Recurso generico para todo.» */

class Recurso {
protected:
    string codigo;
    bool   prestado;
public:
    Recurso(string c) : codigo(c), prestado(false) {}
    virtual ~Recurso() {}

    void prestar()  { prestado = true; }
    bool estaPrestado() const { return prestado; }

    virtual string descripcion() const { return "Recurso generico " + codigo; }
};
//clase : LibroFisico (hereda de Recurso, agrega autor)
class LibroFisico : public Recurso {
private:
    string autor;
public:
    LibroFisico(string c, string a) : Recurso(c), autor(a) {}
    string descripcion() const { return "Libro " + codigo + " de " + autor; }
};
// clase : Equipo (hereda de Recurso, agrega horasUso)
class Equipo : public Recurso {
private:
    int horasUso;
public:
    Equipo(string c, int h) : Recurso(c), horasUso(h) {}
    string descripcion() const { return "Equipo " + codigo + " (" + to_string(horasUso) + "h)"; }
};

// PENDIENTE: clase LibroFisico (hereda de Recurso, agrega autor)
//            descripcion() debe devolver:  "Libro " + codigo + " de " + autor

// PENDIENTE: clase Equipo (hereda de Recurso, agrega horasUso)
//            descripcion() debe devolver:  "Equipo " + codigo + " (" + horas + "h)"

int main() {
    const int N = 3;
    Recurso* catalogo[N] = { nullptr, nullptr, nullptr };
    catalogo[0] = new Recurso("RG-001");
    catalogo[1] = new LibroFisico("LF-002", "Borges");
    catalogo[2] = new Equipo("EQ-003", 12);

    int prestados = 0;
    catalogo[1]->prestar();  // prestamo al segundo recurso.
    for (int i = 0; i < N; i++) {
        if (catalogo[i] == nullptr) continue;
        cout << catalogo[i]->descripcion();
        if (catalogo[i]->estaPrestado()) { cout << "  [PRESTADO]"; prestados++; }
        cout << endl;
    }

    for (int i = 0; i < N; i++) delete catalogo[i];   // delete sobre nullptr es seguro
    // ~Recurso();  // ERROR: Se agrego el destructor virtual para evitar fugas de memoria y liberar correctamente la memoria de los objetos derivados.
    return 0;
}
