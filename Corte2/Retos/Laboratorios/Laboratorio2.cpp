#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 * Laboratorio 2
 * Autor: Oscar David Alvarado Navarrete
 * Fecha: 28-sept-2026
 * Descripción: 
 Parte A Responda y justifique:
1. Tengo mil datos ya ordenados y quiero ordenarlos otra vez. ¿Cuál de los tres básicos hace menos trabajo y por qué?
2. Mi Quicksort escoge el primer elemento como pivote. Denme un conjunto de datos que lo haga comportarse pésimo.
3. Quiero buscar cien veces sobre una colección de diez mil elementos desordenados. ¿Ordeno primero y uso binaria, o busco secuencial cien veces? Justifiquen.

Parte B — Búsqueda comparada 
Implementen búsqueda secuencial y binaria sobre su colección de registros, contando comparaciones. Produzcan la tabla comparativa para cuatro casos: el primer elemento, uno del medio, el último, y uno que no existe.

Parte C — Los tres ordenamientos básicos (30%)
Implementen Bubble, Selection e Insertion sobre sus registros, con contadores de comparaciones e intercambios. Reporten los resultados con datos desordenados y con datos ya ordenados, y expliquen la diferencia.

Parte D — Un ordenamiento avanzado y la medición (40%)
Implementen Merge o Quicksort, midan el tiempo contra uno de los básicos para tres tamaños distintos de entrada, y produzcan la tabla. En el archivo de respuestas, expliquen en cinco líneas por qué los tiempos crecen distinto.

Como siempre, los dos lenguajes.

Parte E— Complejidad
 1. Midan el algoritmo desarrollado, en los dos lenguajes, y hagan la tabla con la columna de factor.
 2. Escriban el párrafo que interpreta esa tabla. No basta pegarla: hay que decir qué significa. Si el factor da dos, digan que es O de n y que coincide con lo esperado. Si no coincide, digan por qué creen que no.

Parte F — CD/CI

Un equipo de desarrollo tiene implementado el mismo algoritmo en Python y C++. Ambos proyectos utilizan GitHub y quieren automatizar un proceso de Integración Continua y Entrega Continua (CI/CD).

El equipo propone el siguiente flujo:

git push → ejecutar programa → pruebas → >compilar → desplegar

Uno de los integrantes afirma:

“En Python no necesitamos Integración Continua porque Python no requiere compilación; CI/CD es principalmente para lenguajes como C++.”

Pregunta:

¿Estás de acuerdo con esta afirmación? Explica por qué y propón cómo debería ser un pipeline de CI/CD para el proyecto en Python y otro para C++.

Como implementarioa CD/CI para este laboratorio

 */

/*Solución:

 A:
 1. Tengo mil datos ya ordenados y quiero ordenarlos otra vez. ¿Cuál de los tres básicos hace menos trabajo y por qué? 
 Respuesta: Insertion sort, porque si los datos ya están ordenados, no hace pasos extra, únicamente realiza las comparaciones sin realizar intercambios. 
 2. Mi Quicksort escoge el primer elemento como pivote. Denme un conjunto de datos que lo haga comportarse pésimo.
 Respuesta: Un conjunto de datos ya ordenados, ya que cada elemento que pasa entra como pivote nuevo, lo que provoca su peor caso de complejidad O(n^2).
 Conjunto de datos que provoca peor caso para Quicksort respecto a primer elemento como pivote: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 3. Quiero buscar cien veces sobre una colección de diez mil elementos desordenados. ¿Ordeno primero y uso binaria, o busco secuencial cien veces?
 Respuesta: Si lo ideal de la implementación es usar esa misma base de datos muchas veces, debido a la densidad, en términos de eficiencia es mejor ordenar primero y luego usar búsqueda binaria.
 En cambio, si se espera usar esa lista una única vez o el costo de ordenamiento es muy alto, es preferible realizar búsquedas secuenciales.

 B:
 Implementen búsqueda secuencial y binaria sobre su colección de registros, contando comparaciones. Produzcan la tabla comparativa para cuatro casos: el primer elemento, uno del medio, el último, y uno que no existe.
 */

void busquedas(vector<int> coleccion);
void bubbleSort(vector<int>& arr, int& comparaciones, int& intercambios);
void selectionSort(vector<int>& arr, int& comparaciones, int& intercambios);
void insertionSort(vector<int>& arr, int& comparaciones, int& intercambios);
void mergeSort(vector<int>& arr, int& comparaciones, int& intercambios);
void busquedaSecuencial(const vector<int>& arr, int objetivo, int& comparaciones);
void busquedaBinaria(const vector<int>& arr, int objetivo, int& comparaciones);
void mostrarResultadoBasico(const string& nombre, const vector<int>& arr, int comparaciones, int intercambios);
void ejecutarParteC();

int main() {
    vector<int> datos;
    int count = 0;

    while (count < 15) {
        int elemento = 0;
        cout << "Ingrese elemento (" << count + 1 << "): ";
        cin >> elemento;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(9999, '\n');
            cout << "Entrada invalida. Intente de nuevo." << endl;
            continue;
        }

        if (elemento < 0) {
            elemento *= -1;
        }

        datos.push_back(elemento);
        count++;
    }

    busquedas(datos);
    ejecutarParteC();
    return 0;
}

void busquedas(vector<int> coleccion) {
    if (coleccion.empty()) {
        cout << "La coleccion esta vacia." << endl;
        return;
    }

    vector<int> ordenada = coleccion;
    sort(ordenada.begin(), ordenada.end());

    vector<int> targets = {coleccion[0], coleccion[coleccion.size() / 2], coleccion[coleccion.size() - 1], -1};
    vector<string> labels = {"primer elemento", "elemento del medio", "ultimo elemento", "elemento no existente"};

    cout << "Busqueda secuencial:" << endl;
    for (int i = 0; i < 4; ++i) {
        int comparaciones = 0;
        bool encontrado = false;

        for (int j = 0; j < static_cast<int>(coleccion.size()); ++j) {
            comparaciones++;
            if (coleccion[j] == targets[i]) {
                encontrado = true;
                cout << "- " << labels[i] << ": encontrado en la posicion " << j
                     << " con " << comparaciones << " comparaciones." << endl;
                break;
            }
        }

        if (!encontrado) {
            cout << "- " << labels[i] << ": no encontrado con " << comparaciones
                 << " comparaciones." << endl;
        }
    }

    cout << "\nBusqueda binaria:" << endl;
    for (int i = 0; i < 4; ++i) {
        int comparaciones = 0;
        bool encontrado = false;
        int inicio = 0;
        int fin = static_cast<int>(ordenada.size()) - 1;

        while (inicio <= fin) {
            comparaciones++;
            int medio = inicio + (fin - inicio) / 2;

            if (ordenada[medio] == targets[i]) {
                encontrado = true;
                cout << "- " << labels[i] << ": encontrado en la posicion " << medio
                     << " con " << comparaciones << " comparaciones." << endl;
                break;
            } else if (ordenada[medio] < targets[i]) {
                inicio = medio + 1;
            } else {
                fin = medio - 1;
            }
        }

        if (!encontrado) {
            cout << "- " << labels[i] << ": no encontrado con " << comparaciones
                 << " comparaciones." << endl;
        }
    }
}

void busquedaSecuencial(const vector<int>& arr, int objetivo, int& comparaciones) {
    for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
        comparaciones++;
        if (arr[i] == objetivo) {
            return;
        }
    }
}

void busquedaBinaria(const vector<int>& arr, int objetivo, int& comparaciones) {
    int inicio = 0;
    int fin = static_cast<int>(arr.size()) - 1;

    while (inicio <= fin) {
        comparaciones++;
        int medio = inicio + (fin - inicio) / 2;

        if (arr[medio] == objetivo) {
            return;
        } else if (arr[medio] < objetivo) {
            inicio = medio + 1;
        } else {
            fin = medio - 1;
        }
    }
}

void bubbleSort(vector<int>& arr, int& comparaciones, int& intercambios) {
    int n = static_cast<int>(arr.size());
    bool huboCambio = false;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            comparaciones++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                intercambios++;
                huboCambio = true;
            }
        }
        if (!huboCambio) break;
        huboCambio = false;
    }
}

void selectionSort(vector<int>& arr, int& comparaciones, int& intercambios) {
    int n = static_cast<int>(arr.size());

    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            comparaciones++;
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        if (minIdx != i) {
            swap(arr[i], arr[minIdx]);
            intercambios++;
        }
    }
}

void insertionSort(vector<int>& arr, int& comparaciones, int& intercambios) {
    int n = static_cast<int>(arr.size());

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparaciones++;
            if (arr[j] <= key) {
                break;
            }
            arr[j + 1] = arr[j];
            intercambios++;
            j--;
        }
        arr[j + 1] = key;
    }
}

void mergeSort(vector<int>& arr, int& comparaciones, int& intercambios) {
    int n = static_cast<int>(arr.size());
    if (n <= 1) return;

    int mid = n / 2;
    vector<int> izquierda(arr.begin(), arr.begin() + mid);
    vector<int> derecha(arr.begin() + mid, arr.end());

    mergeSort(izquierda, comparaciones, intercambios);
    mergeSort(derecha, comparaciones, intercambios);

    int i = 0, j = 0, k = 0;
    while (i < static_cast<int>(izquierda.size()) && j < static_cast<int>(derecha.size())) {
        comparaciones++;
        if (izquierda[i] <= derecha[j]) {
            arr[k++] = izquierda[i++];
        } else {
            arr[k++] = derecha[j++];
        }
        intercambios++;
    }

    while (i < static_cast<int>(izquierda.size())) {
        arr[k++] = izquierda[i++];
        intercambios++;
    }

    while (j < static_cast<int>(derecha.size())) {
        arr[k++] = derecha[j++];
        intercambios++;
    }
}

void mostrarResultadoBasico(const string& nombre, const vector<int>& arr, int comparaciones, int intercambios) {
    cout << "\n" << nombre << endl;
    cout << "  Comparaciones: " << comparaciones << endl;
    cout << "  Intercambios: " << intercambios << endl;
    cout << "  Arreglo ordenado: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

void ejecutarParteC() {
    cout << "\nPARTE C\n" << endl;

    vector<int> ordenado = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> desordenado = {64, 25, 12, 22, 11, 90, 45, 33};

    int comp = 0, switches = 0;
    vector<int> arr = ordenado;
    bubbleSort(arr, comp, switches);
    mostrarResultadoBasico("Bubble Sort (ordenado)", arr, comp, switches);

    comp = 0; switches = 0; arr = ordenado;
    selectionSort(arr, comp, switches);
    mostrarResultadoBasico("Selection Sort (ordenado)", arr, comp, switches);

    comp = 0; switches = 0; arr = ordenado;
    insertionSort(arr, comp, switches);
    mostrarResultadoBasico("Insertion Sort (ordenado)", arr, comp, switches);

    comp = 0; switches = 0; arr = desordenado;
    bubbleSort(arr, comp, switches);
    mostrarResultadoBasico("Bubble Sort (desordenado)", arr, comp, switches);

    comp = 0; switches = 0; arr = desordenado;
    selectionSort(arr, comp, switches);
    mostrarResultadoBasico("Selection Sort (desordenado)", arr, comp, switches);

    comp = 0; switches = 0; arr = desordenado;
    insertionSort(arr, comp, switches);
    mostrarResultadoBasico("Insertion Sort (desordenado)", arr, comp, switches);

    cout << "\nExplicacion: bubble e insertion cambian bastante más cuando el arreglo esta desordenado \nrespecto a selection que se podría considerar constante (O(n^2)) ya que no importa que, siempre realiza la misma cantidad de comparaciones." << endl;
}


// Complejidad de los algoritmos de ordenamiento:


//bubble sort: complejidad (n^2)
//
//Se recorre la lista dos veces para tener i posicion actual y j los que compara
//
//por lo que cada vez que itera la cantidad n, lo hace sobre si misma, implicando una complejidad cuadrática.
//
//selection sort: complejidad (n^2)
//
//Se recorre la lista dos veces, una para seleccionar el elemento mínimo y otra para compararlo con este. 
//
//cada iteración (n veces) la realiza otras n veces, implicando una complejidad cuadrática.
//
//insertion sort: complejidad (n^2)
//
//Se recorre la lista una vez para tomar el elemento actual y otra vez para compararlo con los elementos en orden contario
//
//Cada que pone un elemento a comparación (n veces), lo compara con cada uno de los elementos anteriores, implicando una complejidad cuadrática.
//
//quick sort: complejidad (n log n)
//
//Se divide la lista en sublistas más pequeñas alrededor de un pivote y se ordenan recursivamente. 
//
//Cada vez se va dividiendo el problema, implicando una complejidad logarítmica gracias a la recursión.
//
//merge sort: complejidad (n log n)
//
//Se divide la lista en sublistas más pequeñas, hasta idealmente llegar a sublistas individuales, se ordenan recursivamente y luego se combinan.
//
//Cada vez se va dividiendo el problema, implicando una complejidad logarítmica gracias a la recursión, y a que se implementan sublistas de combinación (merge).
//
//bucket sort: complejidad (n + k)
//
//Se distribuyen los elementos en varios buckets por rangos para luego ordenarse individualmente.
//
//La complejidad depende de la distribución de los elementos y del número de cubos, siendo O(n + k) en el mejor de los casos, donde k es el número de cubos y n el número de elementos.
//
//En el peor de los casos, es si todos los elementos caen en un solo bucket ya que recorrería elemento por elemento y los ordenaria.
//sin hacerlo de la forma optima (buckets) la complejidad sería de O(n^2).
//
//heap sort: complejidad (n log n)
//
//Se construye un heap a partir de la lista y se extrae el elemento máximo repetidamente para ordenar la lista donde la raíz obtiene el número más grande y se ordenan jerarquicamente.
//
//La construcción del heap tiene complejidad O(n) ya que recorre cada elemento y cada extracción tiene complejidad O(log n), 
//ya que se emplean arboles binarios así sean iguales y escala desde las hojas hasta la raiz, 
//resultando en una complejidad total de O(n log n), ya que se realiza el proceso de extracción para cada elemento.

// peor caso algoritmo (main usando todas las funciones posibles para elevar el costo computacional): 
// Se puede crear un arreglo grande y desordenado, y luego aplicar todos los algoritmos de ordenamiento y busqueda para observar el comportamiento en el peor caso.
//comportamiento en el peor caso: O(n^2), ya que los algoritmos de ordenamiento más simples (bubble, selection, insertion) tienen complejidad cuadrática en el peor caso.
// únicamente se les sumaría la complejidad de las búsquedas, que en el peor caso sería O(n) para la búsqueda lineal y O(log n) para la búsqueda binaria.
// Por lo que como el exponente de mayor grado es 2 (de los algoritmos de ordenamiento más simples), el comportamiento en el peor caso del algoritmo completo sigue siendo O(n^2).
// La tabla muestra el crecimiento del tiempo cuando aumenta n y su factor de cambio.
// Si el factor se acerca a 2, entonces al duplicar el tamaño de entrada el tiempo casi se duplica



//PUNTO F:

//Parte F — CD/CI
//
//Un equipo de desarrollo tiene implementado el mismo algoritmo en Python y C++. Ambos proyectos utilizan GitHub y quieren automatizar un proceso de Integración Continua y Entrega Continua (CI/CD).
//
//El equipo propone el siguiente flujo:
//
//git push → ejecutar programa → pruebas → >compilar → desplegar
//
//El flujo es incorrecto:
//El error está en que antes de ejecutar cualquier programa en lenguajes de compilación, se requiere compilarlo primero. 
// 
//Por lo tanto, el flujo correcto debería ser:
//
//git push → compilar → ejecutar programa → pruebas → desplegar
//
//Uno de los integrantes afirma:
//
//“En Python no necesitamos Integración Continua porque Python no requiere compilación; CI/CD es principalmente para lenguajes como C++.”
//
//Pregunta:
//
//¿Estás de acuerdo con esta afirmación? Explica por qué y propón cómo debería ser un pipeline de CI/CD para el proyecto en Python y otro para C++.
//
// Para nada, desprecian el hecho de que no solo sirve para compilar sino para comprobar la funcionabilidad, seguridad y compatibilidad de las partes al unirlas
// python necesita validación.
//
// Para C++:
// git push(trigger) → compilar → ejecutar pruebas → revisar resultados (si salta error, corregir) → desplegar
//

//COn base en lo anterior, es correcto definir CI/CD como procesos automatizados que permiten integrar, entregar cambios de manera continua y eficiente y desplegarlo.
//Como implementaría CD/CI para este laboratorio
//  después del git push se ejecutaría automaticamente codacy para revisar la calidad del código, también se podría implmentar en los otros.
//  pero me basé en la estructuración ya proporcionada por el ejercicio.
// git push(trigger) → compilar el proyecto → ejecutar pruebas → validar dependencias y enlaces del proyecto → revisar resultados (si salta error, corregir), si todo pasa → desplegar