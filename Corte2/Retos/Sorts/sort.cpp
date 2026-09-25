#include <functional>
#include <iostream>
using namespace std;

//se usan como parametros, variables referenciadas para que se modifiquen dentro del main y se puedan llamar e imprimir después sin problema

/**  Ordenamientos Básicos
Uno: agréguenle a Bubble una bandera que detecte si en una pasada completa no hubo ningún intercambio, y en ese caso corte (break).
Después midan cuántas comparaciones hace sobre datos ordenados. Van a ver que baja de veintiocho a siete, igual que Insertion.*/

/* Bubble Sort */
// n = tamaño del arreglo a ordenar
void bubbleSort(int arr[], int n, int& comparaciones, int& switches);

/* Selection Sort */
void selectionSort(int arr[], int n, int& comparaciones, int& switches);

/* Insertion Sort */
void insertionSort(int arr[], int n, int& comparaciones, int& switches);
/* Merge y Quick
Uno: implementen Quicksort en el sitio, sin crear listas nuevas, usando dos índices que se cruzan. Es más difícil y es como se hace de verdad.*/
void quickSort(int arr[], int n, int& comparaciones, int& switches);
//implementen Heapsort de mínimos en vez de máximos, y díganme qué cambió.
void heapSort(int arr[], int n, int& comparaciones, int& switches);
/* Merge Sort */
void mergeSort(int arr[], int n, int& comparaciones, int& switches);


int main() {
    //se declaran de esta forma, para tener al original como referencia pero se modifique el orden del arreglo para cada uno y luego se puedan imprimir unos sin 
    //afectar a los otros
    int original[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int mergeData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int bubbleData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int selectionData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int insertionData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int quickData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int quickWorstCase[] = {11, 12, 22, 25, 33, 45, 64, 90};
    int heapData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    // n es el tamaño del arreglo a ordenar
    int n = sizeof(original) / sizeof(original[0]);

    int comparacionesBubble = 0;
    int comparacionesSelection = 0;
    int comparacionesInsertion = 0;
    int comparacionesQuick = 0;
    int comparacionesMerge = 0;
    int comparacionesHeap = 0;

    int switchesBubble = 0;
    int switchesSelection = 0;
    int switchesInsertion = 0;
    int switchesQuick = 0;
    int switchesMerge = 0;
    int switchesHeap = 0;

    // Se declara y llama a la función de Bubble Sort
    bubbleSort(
        bubbleData, n,
        comparacionesBubble,
        switchesBubble
    );
    // Se declara y llama a la función de Selection Sort
    selectionSort(
        selectionData, n,
        comparacionesSelection,
        switchesSelection
    );
    // Se declara y llama a la función de Insertion Sort
    insertionSort(
        insertionData, n,
        comparacionesInsertion,
        switchesInsertion
    );
    // Se declara y llama a la función de Quick Sort
    quickSort(
        quickData, n,
        comparacionesQuick,
        switchesQuick
    );
    // Se declara y llama a la función de Merge Sort
    mergeSort(
        mergeData, n,
        comparacionesMerge,
        switchesMerge
    );
    // Se declara y llama a la función de Heap Sort
    heapSort(
        heapData, n,
        comparacionesHeap,
        switchesHeap
    );
    // Se declara y llama a la función de Quick Sort en el peor caso
    quickSort(
        quickWorstCase, n,
        comparacionesQuick,
        switchesQuick
    );


    cout << "\033[1;34mComparaciones Bubble Sort:\033[0m "
         << comparacionesBubble
         << ", \033[1;34mSwitches:\033[0m "
         << switchesBubble << endl;

    cout << "\033[1;33mComparaciones Selection Sort:\033[0m "
         << comparacionesSelection
         << ", \033[1;33mSwitches:\033[0m "
         << switchesSelection << endl;

    cout << "\033[1;31mComparaciones Insertion Sort:\033[0m "
         << comparacionesInsertion
         << ", \033[1;31mSwitches:\033[0m "
         << switchesInsertion << endl;
    
    cout << "\033[1;35mComparaciones Quick Sort:\033[0m "
         << comparacionesQuick
         << ", \033[1;35mSwitches:\033[0m "
         << switchesQuick << endl;
    
    cout << "\033[1;32mComparaciones Heap Sort:\033[0m "
         << comparacionesHeap
         << ", \033[1;32mSwitches:\033[0m "
         << switchesHeap << endl;
    
    cout << "\033[1;36mComparaciones Merge Sort:\033[0m "
         << comparacionesMerge
         << ", \033[1;36mSwitches:\033[0m "
         << switchesMerge << endl;

    cout << "\nDatos originales: ";
    for (int i = 0; i < n; i++) {
        cout << original[i] << " ";
    }

    cout << "\n\033[1;94mDatos ordenados (Bubble Sort):\033[0m ";
    for (int i = 0; i < n; i++) {
        cout << bubbleData[i] << " ";
    }

    cout << "\n\033[1;93mDatos ordenados (Selection Sort):\033[0m ";
    for (int i = 0; i < n; i++) {
        cout << selectionData[i] << " ";
    }

    cout << "\n\033[1;91mDatos ordenados (Insertion Sort):\033[0m ";
    for (int i = 0; i < n; i++) {
        cout << insertionData[i] << " ";
    }

    cout << "\n\033[1;92mDatos ordenados (Heap Sort):\033[0m ";
    for (int i = 0; i < n; i++) {
        cout << heapData[i] << " ";
    }

    cout << "\n\033[1;95mDatos ordenados (Quick Sort):\033[0m ";
    for (int i = 0; i < n; i++) {
        cout << quickData[i] << " ";
    }
    
    cout << "\n\033[1;96mDatos ordenados (Merge Sort):\033[0m ";
    for (int i = 0; i < n; i++) {
        cout << mergeData[i] << " ";
    }
    //Dos: construyan un caso que haga que su Quicksort se comporte pésimo. 
    //Si escogen el primer elemento como pivote, una lista ya ordenada lo logra. Mídanlo.
    cout << "\nPEOR CASO PARA QUICK SORT";
    // Se asume que el peor caso es cuando el arreglo ya está ordenado
    quickSort(
        quickWorstCase, n,
        comparacionesQuick,
        switchesQuick
    );
    cout << "\nComparaciones Quick Sort en peor caso: " << comparacionesQuick
         << ", switches: " << switchesQuick << endl;

    cout << endl;
    return 0;
}


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