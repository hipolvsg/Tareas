#include <iostream>
#include <vector>
#include <string>
using namespace std;
/**
 * Laboratorio 2
 * Autor: [Tu Nombre]
 * Fecha: [Fecha]
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

git push → ejecutar programa → pruebas → compilar → desplegar

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
 Respuesta: Si lo ideal de la implementación es usar esa misma base de deatos muchas veces, debido a la densidad, en términos de eficiencia es mejor, ordenar primero y luego usar búsqueda binaria.
 En cambio, si se espera usar esa lista una única vez o el costo de ordenamiento es muy alto, es preferible realizar búsquedas secuenciales.

 B:
 Implementen búsqueda secuencial y binaria sobre su colección de registros, contando comparaciones. Produzcan la tabla comparativa para cuatro casos: el primer elemento, uno del medio, el último, y uno que no existe.

 */
void busquedas(vector<int> coleccion) {
    int comparacionesSecuencial = 0;
    int comparacionesBinaria = 0;
    bool encontradoPrimero = false;
    bool encontradoMedio = false;
    bool encontradoUltimo = false;
    bool encontradoNoExiste = false;
    bool encontradoNoExiste2 = false;
    int elementoPrimero = coleccion[0];
    int elementoMedio = coleccion[coleccion.size() / 2];
    int elementoUltimo = coleccion[coleccion.size() - 1];
    int elementoNoExiste = -1;
    //busqueda secuencial
    cout << "Búsqueda secuencial:" << endl;
    cout << "Buscando el primer elemento:" << endl;
    int Target;
    int count = 0;
    while (count <= 4) {
        if (count == 1) {
            Target = elementoPrimero;
            encontrado = encontradoPrimero;
        }else if (count == 2) {
            Target = elementoMedio;
            encontrado = encontradoMedio;
        } else if (count == 3) {
            Target = elementoUltimo;
            encontrado = encontradoUltimo;
        } else if (count == 4) {
            Target = elementoNoExiste;
            encontrado = encontradoNoExiste;
        }
        count++;

            for (int i = 0; i < coleccion.size(); i++) {
                comparacionesSecuencial++;
                if (coleccion[i] == Target) {
                    encontrado = true;
                    cout << "Elemento en la posición " << i << ": " << coleccion[i] << endl;
                    cout << "Comparaciones hasta encontrar el elemento: " << comparacionesSecuencial << endl;
                    comparacionesSecuencial = 0; // Reiniciar el contador para la siguiente búsqueda
                }
            }
            if (!encontrado) {
                cout << "Elemento no encontrado." << endl;
                cout << "Comparaciones hasta no encontrar el elemento: " << comparacionesSecuencial << endl;
                comparacionesSecuencial = 0; // Reiniciar el contador para la siguiente búsqueda
            }
    }
    count = 0;
    //busqueda binaria
    cout << "Búsqueda binaria:" << endl;
    Target = elementoPrimero;
    encontrado = encontradoPrimero;
    while (count <= 4) {
        if (count == 1) {
            Target = elementoPrimero;
            encontrado = encontradoPrimero;
        } else if (count == 2) {
            Target = elementoMedio;
            encontrado = encontradoMedio;
        } else if (count == 3) {
            Target = elementoUltimo;
            encontrado = encontradoUltimo;
        } else if (count == 4) {
            Target = elementoNoExiste;
            encontrado = encontradoNoExiste;
        }
        sort(coleccion.begin(), coleccion.end());
        int inicio = 0;
        int fin = coleccion.size() - 1;
            encontrado = false;
            while (inicio <= fin) {
                comparacionesBinaria++;
                int medio = (inicio + fin) / 2;
                if (coleccion[medio] == Target) {
                    encontrado = true;
                    cout << "Elemento en la posición " << medio << ": " << coleccion[medio] << endl;
                    cout << "Comparaciones hasta encontrar el elemento: " << comparacionesBinaria << endl;
                    break;
                } else if (coleccion[medio] < Target) {
                    inicio = medio + 1;
                } else {
                    fin = medio - 1;
                }
            }
            if (!encontrado) {
                cout << "Elemento no encontrado." << endl;
                cout << "Comparaciones hasta no encontrar el elemento: " << comparacionesBinaria << endl;
                comparacionesBinaria = 0; // Reiniciar el contador para la siguiente búsqueda
            }
        }
        count++;
        comparacionesBinaria = 0; // Reiniciar el contador para la siguiente búsqueda
    return;
}




//PARTE C:


void bubbleSort(int arr[], int n, int& comparaciones, int& switches) {
    bool swapped = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                switches++;
                swapped = true;
            }
        }
        if (!swapped) break;
        swapped = false;
    }
}



void selectionSort(int arr[], int n, int& comparaciones, int& switches) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;

        for (int j = i + 1; j < n; j++) {
            comparaciones++;

            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        if (minIdx != i) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
            switches++;
        }
    }
}

void insertionSort(int arr[], int n, int& comparaciones, int& switches) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0) {
            comparaciones++;

            if (arr[j] <= key) {
                break;
            }

            arr[j + 1] = arr[j];
            j--;
            switches++;
        }

        arr[j + 1] = key;
    }
}

Parte D


void quickSortRecursive(int arr[], int bajo, int alto, int& comparaciones, int& switches) {
    if (bajo >= alto) return;

    // elemento medio como pivote
    int mid = bajo + (alto - bajo) / 2;
    int pivote = arr[mid];

    int i = bajo;
    int j = alto;

    // recorre de izquierda a derecha y de derecha a izquierda 
    // para colocar los elementos en su posición correcta respecto al pivote
    while (i <= j) {
        //si el elemento es menor, esta bine, si no, se interrumpe el bucle para colocar el pivote en su posición correcta
        while (true) {
            comparaciones++;
            if (arr[i] < pivote) {
                i++;
            } else {
                break;
            }
        }
        //lo mismo pero con el mayor
        while (true) {
            comparaciones++;
            if (arr[j] > pivote) {
                j--;
            } else {
                break;
            }
        }
        // intercambia los elementos que están en el lado incorrecto respecto al pivote
        if (i <= j) {
            // solo intercambia si los elementos son diferentes para evitar malgasto
            if (i != j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                switches++;
            }
            // mueve los "punteros" hacia el centro para continuar con la partición
            i++;
            j--;
        }
    }

    //Llamadas recursivas para las dos mitades
    if (bajo < j) {
        quickSortRecursive(arr, bajo, j, comparaciones, switches);
    }
    if (i < alto) {
        quickSortRecursive(arr, i, alto, comparaciones, switches);
    }
}

// Función principal que coincide exactamente con la firma que ya usas en tu main
void quickSort(int arr[], int n, int& comparaciones, int& switches) {
    if (n <= 1) return;
    quickSortRecursive(arr, 0, n - 1, comparaciones, switches);
}

void mergeSort(int arr[], int n, int& comparaciones, int& switches) {
    if (n <= 1) return;

    int mid = n / 2;
    mergeSort(arr, mid, comparaciones, switches);
    mergeSort(arr + mid, n - mid, comparaciones, switches);

    int* temp = new int[n];
    int i = 0, j = mid, k = 0;
    // Mezcla las dos mitades ordenadas en el arreglo temporal
    while (i < mid && j < n) {
        comparaciones++;
        // Compara contenidos de ambas mitades y coloca el siguiente elemento más pequeño en el arreglo temporal
        if (arr[i] <= arr[j]) {
            //primero se usa k/i en el arreglo y luego se suma, ya que la notación lo permite
            temp[k++] = arr[i++];
            switches++;
        } else {
            temp[k++] = arr[j++];
            switches++;
        }
    }

    // Copia los elementos restantes de la mitad izquierda, si los hay
    while (i < mid) {
        temp[k++] = arr[i++];
        switches++;
    }
    // Copia los elementos restantes de la mitad derecha, si los hay
    while (j < n) {
        temp[k++] = arr[j++];
        switches++;
    }
    // Copia los elementos del arreglo temporal de vuelta al arreglo original
    for (i = 0; i < n; i++) {
        arr[i] = temp[i];
        switches++;
    }
    //borra el temporal y el original se vuelve el ordenado
    delete[] temp;
    }

void bucketSort(int arr[], int n, int& comparaciones, int& switches) {
    if (n <= 1) return;
    // Encuentra el valor máximo en el arreglo, se pone arr[0] como referencia ya que puede ser el valor máximo
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        comparaciones++;
        //busca valor maximo
        if (arr[i] > maxVal) {
            // actualiza el valor máximo si se encuentra uno mayor
            maxVal = arr[i];
        }
    }
    //bucketcount es el número de cubos necesarios, se usa maxVal+1 para incluir el valor máximo
    int bucketCount = maxVal + 1;
    // Crea un arreglo de cubos (buckets) y los inicializa
    int* buckets = new int[bucketCount]();

    // Distribuye los elementos en los cubos correspondientes
    for (int i = 0; i < n; i++) {
        // se pone el elemento en el cubo correspondiente según su valor, 
        //incrementa el contador del cubo correspondiente al valor del elemento actual
        buckets[arr[i]]++;
        switches++;
    }
    // Reconstruye el arreglo original a partir de los cubos 
    int index = 0;
    for (int bucketValue = 0; bucketValue < bucketCount; bucketValue++) {
        while (buckets[bucketValue] > 0) {
            // Coloca el valor del cubo actual en el arreglo original
            arr[index] = bucketValue;
            // incrementa el índice del arreglo original para colocar el siguiente elemento
            index++;
            // disminuye la cantidad de elementos bucket Value en el bucket correspondiente
            buckets[bucketValue]--;

            switches++;
        }
    }
    // El arreglo original ahora está ordenado
    delete[] buckets;
}

void heapSort(int arr[], int n, int& comparaciones, int& switches) {
    // Función auxiliar para hacer el heapify
    //heapify es una función auxiliar que asegura que el subárbol con raíz en el índice i cumpla la propiedad de heap máximo.
    //subfunción dentro de Heapsort que no retorna nada pero si modifica el arreglo y actualiza los contadores de comparaciones y switches.
    //notación debido a error de compilación al no usar function directamente.
    //lambda es en está función una forma de definir funciones anónimas dentro de otra función.
    //heapify y su relación con lambda es que heapify se define como una función anónima dentro de HeapSort usando la sintaxis de lambda.
    std::function<void(int[], int, int)> heapify;
    heapify = [&](int arr[], int n, int i) {
        // Encuentra el índice del nodo más grande entre la raíz y sus hijos
        int largest = i; // Inicializa el nodo más grande como raíz
        // Inicializa en las hojas (los hijos izquierdo y derecho del nodo actual)
        int left = 2 * i + 1; // hijo izquierdo
        int right = 2 * i + 2; // hijo derecho

        // Si el hijo izquierdo es más grande que la raíz
        if (left < n) {
            // incrementa el contador de comparaciones antes de comparar con el hijo izquierdo
            comparaciones++;
            // Compara el hijo izquierdo con el nodo más grande actual
            if (arr[left] > arr[largest])
                // Si el hijo izquierdo es mayor, actualiza el nodo más grande
                largest = left;
        }

        // Si el hijo derecho es más grande que el más grande hasta ahora
        // incrementa el contador de comparaciones antes de comparar con el hijo derecho 
        if (right < n) {
            comparaciones++;
            // Compara el hijo derecho con el nodo más grande actual
            if (arr[right] > arr[largest])
                // Si el hijo derecho es mayor, actualiza el nodo más grande
                largest = right;
        }

        // Si el más grande no es la raíz
        if (largest != i) {
            // Si el nodo más grande no es la raíz, intercambia la raíz con el nodo más grande
            swap(arr[i], arr[largest]);
            switches++;
            // Aplica heapify recursivamente al subárbol afectado para seguir manteniendo la propiedad de heap máximo
            // O(log n) en el peor caso, donde n es el tamaño del subárbol afectado
            heapify(arr, n, largest);
        }
    };

    // Construye el heap (reorganiza el arreglo)
    // O(n) para construir el heap
    for (int i = (n / 2) - 1; i >= 0; i--) heapify(arr, n, i);
    // Extrae elementos del heap uno por uno
    // O(n log n) en el peor caso, donde n es el tamaño del arreglo
    for (int i = n - 1; i > 0; i--) {
        // Mueve la raíz actual al final
        swap(arr[0], arr[i]);
        switches++;
        // Llama a funcion auxiliar pero ahora sobre el heap reducido (excluyendo el último elemento que ya está en su posición correcta)
        heapify(arr, i, 0);
    }
}


/*Parte C — Los tres ordenamientos básicos (30%)
Implementen Bubble, Selection e Insertion sobre sus registros, con contadores de comparaciones e intercambios. Reporten los resultados con datos desordenados y con datos ya ordenados, y expliquen la diferencia.
*/  



/*Implementen Merge o Quicksort, midan el tiempo contra uno de los básicos para tres tamaños distintos de entrada, y produzcan la tabla. 
En el archivo de respuestas, expliquen en cinco líneas por qué los tiempos crecen distinto.
*/





int main (){

    int count = 0;
    int elemento;
    vector<int> coleccion;
    while (count < 15) {
        count++;
        cout << "Introduzca el elemento(" << count << ") a buscar: ";
        cin >> elemento;
        if (cin.fail()){
            cin.clear();
            cin.ignore(9999, '\n');
            count--;
        }
        if (elemento < 0) {
            elemento = elemento * -1;
        }
        coleccion.push_back(elemento);
    }
    //parte c y d
    int arr[15];
    //array ordenados
    for (int i = 0; i < 15; i++) {
        arr[i] = i;
    }
    int tempArr[15] = {42, 12, 89, 5, 33, 76, 1, 54, 98, 23, 67, 14, 88, 3, 45};
    //llamada funciones con array ordenado
    bubbleSort(arr, 15);
    selectionSort(arr, 15);
    insertionSort(arr, 15);

    //primera entrada
    //Parte D

    int comparaciones = 0;
    int switches = 0;
    //se utilizaran comparaciones y switches para medir el rendimiento de los algoritmos de ordenamiento ya que tiempo directamente es proporcional a la capacidad del equipo)
    HeapSort(arr, 15, comparaciones, switches);
    bubbleSort(arr, 15, comparaciones, switches);
    cout << "Comparaciones: " << comparaciones << ", Intercambios: " << switches << endl;
    //diferencia entre ordenado y desordenado: El analisis en el ordenado muestra menos intercambios y comparaciones que en el desordenado ya que los elementos ya están en su lugar correcto.
    //array desordenados
    for (int i = 0; i < 15; i++) {
        arr[i] = tempArr[i];
    }
    //llamada funciones con array desordenado
    bubbleSort(arr, 15);
    selectionSort(arr, 15);
    insertionSort(arr, 15);
    //segunda entrada
    comparaciones = 0;
    switches = 0;
    HeapSort(arr, 15, comparaciones, switches);
    bubbleSort(arr, 15, comparaciones, switches);
    cout << "Comparaciones: " << comparaciones << ", Intercambios: " << switches << endl;
    int arr[40] = {
    45, 12, 78, 3, 56, 89, 23, 67, 34, 90, 
    11, 55, 77, 2, 44, 88, 33, 66, 22, 99, 
    10, 49, 71, 18, 59, 82, 27, 63, 38, 94, 
    5, 42, 75, 14, 51, 84, 29, 69, 36, 97
};
    //tercera entrada
    comparaciones = 0;
    switches = 0;
    HeapSort(arr, 40, comparaciones, switches);
    bubbleSort(arr, 40, comparaciones, switches);
    cout << "Comparaciones: " << comparaciones << ", Intercambios: " << switches << endl;

    //explicacion porque crecen distinto, 
    // Los tiempos crecen distinto porque HeapSort tiene una complejidad de O(n log n) en el peor caso y de O(n log n) en el mejor caso,
    // mientras que BubbleSort tiene una complejidad de O(n^2) en el peor caso y de O(n) en el mejor caso. Por lo tanto, a medida que
    // aumenta el tamaño de la entrada, BubbleSort se vuelve significativamente más lento que HeapSort.
    

    return 0;
}