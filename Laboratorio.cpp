#include <iostream>
#include <string>

using namespace std;

/*LABORATORIO
 Central de reciclaje comunitaria
 Un barrio puso en marcha una central de reciclaje. Cada punto de acopio recibe material durante la semana 
 y la junta comunal necesita un programa que registre los pesos y produzca un informe.
 El laboratorio se resuelve completo en C++ y completo en Python.*/


/* --- PARTE A — Arreglos y matrices ---
 Definir una matriz de 4 puntos de acopio × 6 días con los pesos recogidos en kilogramos.
 Calcular e imprimir: total por punto, total por día, el punto más productivo de la semana 
 y el día de menor recolección de toda la central. Informar cuántos registros tienen valor 0. */
void parteA() {
    double matriz[4][6] = {
        {120.5, 0.0, 150.0, 90.5, 200.0, 110.0},
        {85.0, 95.0, 0.0, 105.0, 115.0, 130.0},
        {200.0, 210.0, 190.0, 0.0, 220.0, 215.0},
        {50.0, 60.0, 70.0, 80.0, 90.0, 100.0}
    };

    double totalPunto[4] = {0};
    double totalDia[6] = {0};
    int ceros = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            totalPunto[i] += matriz[i][j];
            totalDia[j] += matriz[i][j];
            if (matriz[i][j] == 0.0) ceros++;
        }
    }

    int puntoMax = 0;
    for (int i = 1; i < 4; i++) {
        if (totalPunto[i] > totalPunto[puntoMax]) puntoMax = i;
    }

    int diaMin = 0;
    for (int j = 1; j < 6; j++) {
        if (totalDia[j] < totalDia[diaMin]) diaMin = j;
    }

    cout << "=== PARTE A ===" << endl;
    for (int i = 0; i < 4; i++) cout << "Total punto " << i + 1 << ": " << totalPunto[i] << " kg\n";
    for (int j = 0; j < 6; j++) cout << "Total dia " << j + 1 << ": " << totalDia[j] << " kg\n";
    cout << "Punto mas productivo: Punto " << puntoMax + 1 << "\n";
    cout << "Dia de menor recoleccion: Dia " << diaMin + 1 << "\n";
    cout << "Registros con valor 0: " << ceros << "\n\n";
}

/* --- PARTE B — Memoria dinámica y punteros ---
 Preguntar al usuario cuántos puntos de acopio nuevos se van a registrar y reservar dinámicamente un arreglo.
 Llenarlo con los pesos y calcular el promedio usando aritmética de punteros, no índices.
 Liberar correctamente la memoria y dejar el puntero en nullptr. */
void parteB() {
    int n;
    cout << "=== PARTE B ===" << endl;
    cout << "Ingrese cantidad de puntos nuevos: ";
    if (!(cin >> n) || n <= 0) return;

    double* pesos = new double[n];
    cout << "Ingrese los " << n << " pesos:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(pesos + i);
    }

    double suma = 0;
    double* ptr = pesos;
    for (int i = 0; i < n; i++) {
        suma += *ptr;
        ptr++;
    }

    double promedio = (n > 0) ? suma / n : 0;
    cout << "Promedio (aritmetica de punteros): " << promedio << " kg\n\n";

    delete[] pesos;
    pesos = nullptr;
}

/* --- PARTE C — Objetos ---
 Clase PuntoAcopio con atributos encapsulados (código, barrio, total recogido) y dos métodos.
 Clase MaterialEspecial que herede de la anterior, agregue un atributo y redefina la descripción.
 Arreglo con al menos cuatro objetos mezclando ambas clases, usando punteros a la clase base y virtual. */
class PuntoAcopio {
protected:
    string codigo;
    string barrio;
    double totalRecogido;
public:
    PuntoAcopio(string c, string b, double t) : codigo(c), barrio(b), totalRecogido(t) {}
    virtual ~PuntoAcopio() {}

    void registrarRecoleccion(double kilos) {
        if (kilos > 0) totalRecogido += kilos;
    }

    bool superaMeta(double meta) {
        return totalRecogido >= meta;
    }

    virtual string obtenerDescripcion() {
        return "Punto [Codigo: " + codigo + ", Barrio: " + barrio + ", Total: " + to_string(totalRecogido) + " kg]";
    }
};

class MaterialEspecial : public PuntoAcopio {
private:
    string tipoMaterial;
public:
    MaterialEspecial(string c, string b, double t, string tipo) : PuntoAcopio(c, b, t), tipoMaterial(tipo) {}

    string obtenerDescripcion() override {
        return "Material Especial [Codigo: " + codigo + ", Barrio: " + barrio + ", Total: " + to_string(totalRecogido) + " kg, Tipo: " + tipoMaterial + "]";
    }
};

void parteC() {
    cout << "=== PARTE C ===" << endl;
    PuntoAcopio* arr[4];
    arr[0] = new PuntoAcopio("P01", "Centro", 450.5);
    arr[1] = new MaterialEspecial("M01", "Norte", 120.0, "Electronicos");
    arr[2] = new PuntoAcopio("P02", "Sur", 300.0);
    arr[3] = new MaterialEspecial("M02", "Occidente", 215.5, "Pilas");

    for (int i = 0; i < 4; i++) {
        cout << arr[i]->obtenerDescripcion() << endl;
    }

    for (int i = 0; i < 4; i++) {
        delete arr[i];
        arr[i] = nullptr;
    }
}

int main() {
    parteA();
    parteB();
    parteC();
    return 0;
}