#include <iostream>
using namespace std;

//se usan como parametros, variables referenciadas para que se modifiquen dentro del main y se puedan llamar e imprimir después sin problema

/* Bubble Sort */
void bubbleSort(int arr[], int n, int& comparaciones, int& switches) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparaciones++;

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                switches++;
            }
        }
    }
}

/* Selection Sort */
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

/* Insertion Sort */
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

int main() {
    int original[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int bubbleData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int selectionData[] = {64, 25, 12, 22, 11, 90, 45, 33};
    int insertionData[] = {64, 25, 12, 22, 11, 90, 45, 33};

    int n = sizeof(original) / sizeof(original[0]);

    int comparacionesBubble = 0;
    int comparacionesSelection = 0;
    int comparacionesInsertion = 0;

    int switchesBubble = 0;
    int switchesSelection = 0;
    int switchesInsertion = 0;

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

    cout << endl;
    return 0;
}