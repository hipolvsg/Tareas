#include <iostream>
#include <string>
#include <vector>
//Usaquén

//Usaquén -> Vereda

//Cuantos vertices, aristas, caminos y grados tiene el grafo?

//vertices: Son los nodos del grafo, que representan los puntos o lugares.
//aristas: Son las conexiones entre los nodos, que representan los caminos o relaciones.
//caminos: Son las rutas posibles entre los nodos.
//grados: Es el número de aristas que inciden en cada nodo. (inherente de cada nodo)
/*
Grafo: es un conjunto de nodos (vertices) y aristas(hilos) que conectan esos nodos
arbol de n nodos tiene n-1 aristas no ciclos
grafo puede tener desde 0 hasta n(n-1)/2 aristas ciclicas
grado: número de aristas incidentes en un nodo
no dirigido: aristas no tienen dirección
dirigido: aristas tienen dirección
ponderado: aristas tienen un peso asociado
caminos: secuencia de aristas que conectan nodos
ciclos: camino que empieza y termina en el mismo nodo
conexo: si existe un camino entre cada par de nodos

Matriz de adyacencia: matriz cuadrada de n x n donde n es el número de nodos, 
si hay una arista entre el nodo i y j, entonces la posición (i,j) es 1, sino es 0
lista de adyacencia: lista de listas donde cada lista contiene los nodos adyacentes a un nodo


vector<vector<int>> matriz(N, vector<int>(N, 0));
for (auto [u, v] : ARISTAS) {
    matriz[u][v] = 1;
    matriz[v][u] = 1;         // no dirigido: la matriz es simetrica
}
bool hayVia(int u, int v) { return matriz[u][v] == 1; }  // O(1)
*/

using namespace std;
/*
1. Centro -> Norte
2. Norte -> Occidente
3. Centro -> Sur
4. Centro -> Oriente
5. Norte -> Chapinero
6. Sur -> Bosa
7. Oriente -> Usaquén
8. Chapinero -> Usaquén
9. Occidente -> Bosa
10. Bosa -> Vereda
11. Vereda -> Norte
12. Bosa -> Chapinero
13. Chapinero -> Vereda
14. Sur -> Usaquén
15. Usaquén -> Vereda
16. Norte -> Vereda
17. Chapinero -> Bosa
18. Chapinero -> Sur
*/
//nodos
//0: Centro
//1: Norte
//2: Occidente
//3: Sur
//4: Oriente
//5: Chapinero
//6: Bosa
//7: Usaquén
//8: Vereda
/*
class grafo {
    int N;
    vector<vector<int>> matriz;
public:
    grafo(int n, const vector<pair<int, int>>& aristas) : N(n), matriz(N, vector<int>(N, 0)) {
        for (auto [u, v] : aristas) {
            matriz[u][v] = 1;
            matriz[v][u] = 1;  // no dirigido: la matriz es simetrica
        }
    }
    bool hayVia(int u, int v) { return matriz[u][v] == 1; }  // O(1)
};

int main() {
    int N = 9;
    //Nodos
    vector<string> NODOS = {
        "Centro", "Norte", "Occidente", "Sur", "Oriente",
        "Chapinero", "Bosa", "Usaquén", "Vereda"
    };
    //Aristas
    vector<pair<int, int>> ARISTAS = {
        {0, 1}, {1, 2}, {0, 3}, {0, 4}, {1, 5},
        {3, 6}, {4, 7}, {5, 7}, {2, 6}, {6, 8},
        {8, 1}, {6, 5}, {5, 8}, {3, 7}, {7, 8},
        {1, 8}, {5, 6}, {5, 3}
    };
    grafo g(N, ARISTAS);
    cout << g.hayVia(0, 1) << endl;  // ejemplo de uso
    return 0;
}
*/

//tarea: buscar definición y conecpto de aliaising
//aliasing: Es un fenómeno en programación donde dos o más referencias apuntan al mismo objeto en memoria, lo que puede causar efectos secundarios inesperados al modificar el objeto a través de cualquiera de las referencias.
