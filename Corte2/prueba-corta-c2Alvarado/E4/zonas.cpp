// ============================================================
//  Prueba corta · Segundo corte · EJERCICIO 4  (25 puntos)
//  Tema: mapas y conjuntos
//  Sistema: RedAcopio — consolidado de recoleccion por zona
//
//  Este archivo NO tiene main(): el main esta en pruebas_e4.cpp
//  NO MODIFIQUE el archivo pruebas_e4.cpp
//  Compile y ejecute:
//     g++ -std=c++17 -g -o pruebas_e4 zonas.cpp pruebas_e4.cpp
//     ./pruebas_e4
// ============================================================
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

// Debe hacer TRES cosas:
//   1. llenar 'totales' con los kilos acumulados por zona
//   2. llenar 'repetidas' con las zonas que aparecen en MAS DE UN registro
//   3. devolver el nombre de la zona con mayor total acumulado
//
// Si 'reg' esta vacio, devuelva la cadena vacia "" y no agregue nada.
//
// PENDIENTE: implementar el cuerpo de la funcion.

string zonaMayor(const vector<pair<string,int>>& reg,
                 map<string,int>& totales,
                 set<string>& repetidas) {
    if (reg.empty()) return "";
    map<string,int> contador;
    string zona_max = "";
    int max_total = 0;
    for (const auto& r : reg) {
        //estructura (string zona, int kilos)
        const string& zona = r.first;
        int kilos = r.second;
        //estructura totales: map<string,int> con los kilos acumulados por zona
        // suma total de kilos por zona (1 condición)
        totales[zona] += kilos;
        // cuenta apariciones de cada zona (2 condición)
        contador[zona]++;
        //si se repite, agregar a 'repetidas' (2 condición)
        if (contador[zona] > 1) repetidas.insert(zona);
        // actualiza la zona con mayor total acumulado (3 condición)
        if (totales[zona] > max_total) {
            max_total = totales[zona];
            zona_max = zona;
        }
    }
    return zona_max;
}
