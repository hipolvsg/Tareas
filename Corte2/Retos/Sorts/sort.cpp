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
/** Merge y Quick
Uno: implementen Quicksort en el sitio, sin crear listas nuevas, usando dos índices que se cruzan. Es más difícil y es como se hace de verdad.*/
void quickSort(int arr[], int n, int& comparaciones, int& switches);
//implementen Heapsort de mínimos en vez de máximos, y díganme qué cambió.
void heapSort(int arr[], int n, int& comparaciones, int& switches);


int main() {
    int original[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int bubbleData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int selectionData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int insertionData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int quickData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int quickWorstCase[] = {11, 12, 22, 25, 33, 45, 64, 90};
    // n es el tamaño del arreglo a ordenar
    int n = sizeof(original) / sizeof(original[0]);

    int comparacionesBubble = 0;
    int comparacionesSelection = 0;
    int comparacionesInsertion = 0;
    int comparacionesQuick = 0;

    int switchesBubble = 0;
    int switchesSelection = 0;
    int switchesInsertion = 0;
    int switchesQuick = 0;

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

    cout << "\n\033[1;95mDatos ordenados (Quick Sort):\033[0m ";
    for (int i = 0; i < n; i++) {
        cout << quickData[i] << " ";
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

