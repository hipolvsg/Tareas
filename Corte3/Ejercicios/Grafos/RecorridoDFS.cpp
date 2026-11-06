#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

const vector<string> NOMBRES = {
    "Centro", "Norte", "Occidente", "Sur", "Oriente",
    "Chapinero", "Bosa", "Usaquén", "Vereda"
};

const vector<pair<int,int>> ARISTAS = {
    {0, 1}, {1, 2}, {0, 3}, {0, 4}, {1, 5},
    {3, 6}, {4, 7}, {5, 7}, {2, 6}, {6, 8},
    {8, 1}, {6, 5}, {5, 8}, {3, 7}, {7, 8},
    {1, 8}, {5, 6}, {5, 3}
};

const int N = 9;

void dfsRec(int u, const vector<vector<int>>& lista, vector<bool>& vis, vector<int>& orden) {
    vis[u] = true;
    orden.push_back(u);          

    for (int v : lista[u]) {     
        if (!vis[v]) dfsRec(v, lista, vis, orden);
    }
}

void bfs(int inicio, const vector<vector<int>>& lista, vector<int>& orden, vector<int>& dist, vector<int>& padre) {
    vector<bool> vis(N, false);
    dist.assign(N, -1);
    padre.assign(N, -1);
    orden.clear();

    queue<int> cola;
    cola.push(inicio);
    vis[inicio] = true;
    dist[inicio] = 0;

    while (!cola.empty()) {
        int u = cola.front();
        cola.pop();
        orden.push_back(u);

        for (int v : lista[u]) {
            if (!vis[v]) {
                vis[v] = true;
                dist[v] = dist[u] + 1;
                padre[v] = u;
                cola.push(v);
            }
        }
    }
}

int main() {
    vector<vector<int>> lista(N);
    for (auto [u, v] : ARISTAS) {
        lista[u].push_back(v);
        lista[v].push_back(u);
    }

    for (auto& vec : lista) sort(vec.begin(), vec.end());

    vector<bool> vis(N, false);
    vector<int> ordenDFS;
    cout << "DFS recursivo desde Centro: ";
    dfsRec(0, lista, vis, ordenDFS);
    for (int x : ordenDFS) cout << NOMBRES[x] << " ";
    cout << endl;

    vector<int> ordenBFS, dist, padre;
    bfs(0, lista, ordenBFS, dist, padre);

    cout << "\nBFS desde Centro: ";
    for (int x : ordenBFS) cout << NOMBRES[x] << " ";
    cout << endl;

    cout << "\nNiveles BFS:\n";
    vector<bool> visitado(N, false);
    queue<int> cola;
    cola.push(0);
    visitado[0] = true;
    int nivel = 0;

    while (!cola.empty()) {
        int tam = cola.size();
        cout << "Nivel " << nivel << ": ";
        for (int i = 0; i < tam; i++) {
            int u = cola.front();
            cola.pop();
            cout << NOMBRES[u] << " ";
            for (int v : lista[u]) {
                if (!visitado[v]) {
                    visitado[v] = true;
                    cola.push(v);
                }
            }
        }
        cout << endl;
        nivel++;
    }

    cout << "\nCamino mas corto desde Centro hasta Vereda: ";
    int destino = 8; // Vereda
    vector<int> ruta;
    int actual = destino;
    while (actual != -1) {
        ruta.push_back(actual);
        actual = padre[actual];
    }
    reverse(ruta.begin(), ruta.end());

    for (int x : ruta) cout << NOMBRES[x] << " ";
    cout << endl;
    cout << "Distancia: " << dist[destino] << " tramos" << endl;

    return 0;
}


//tarea revisar complejidad de DFS y BFS
//





//desde centro a vereda -> azul -> rojo -> blanco(vereda)