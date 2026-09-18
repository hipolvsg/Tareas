# comparo dos vecinos si estan al reves los intercambio y repito el proceso 
# hast que nadie mas se mueva bubble sort

def bubble_sort(arr):
    global ComparacionesBubble, SwitchesBubble
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            ComparacionesBubble += 1
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                SwitchesBubble += 1
                swapped = True
        if not swapped:
            break
    return arr
#buscar el más pequeño y ponerlo al 
# principio selection sort

def selection_sort(arr):
    global ComparacionesSelection, SwitchesSelection
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i + 1, n):
            ComparacionesSelection += 1
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        SwitchesSelection += 1
    return arr
# tomo el segubndo y lo inserto donde va 
# respecto al primero insertion sort

def insertion_sort(arr):
    global ComparacionesInsertion, SwitchesInsertion
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            ComparacionesInsertion += 1
            arr[j + 1] = arr[j]
            j -= 1
            SwitchesInsertion += 1
        # Si j >= 0, es porque la comparación también se realizó
        if j >= 0:
            ComparacionesInsertion += 1
        arr[j + 1] = key
    return arr

# datos: [64, 25, 12, 22, 11, 90, 45, 33]
if __name__ == "__main__":
    ComparacionesBubble = 0
    ComparacionesSelection = 0
    ComparacionesInsertion = 0
    SwitchesBubble = 0
    SwitchesSelection = 0
    SwitchesInsertion = 0
    data = [64, 25, 12, 22, 11, 90, 45, 33]
    print("Original data:", data)
    print()
    print("\033[1;94mBubble Sort:\033[0m", bubble_sort(data.copy()))
    print("\033[1;34mComparaciones Bubble Sort:\033[0m", ComparacionesBubble, "Switches Bubble Sort:", SwitchesBubble)
    print()
    print("\033[1;93mSelection Sort:\033[0m", selection_sort(data.copy()))
    print("\033[1;33mComparaciones Selection Sort:\033[0m", ComparacionesSelection, "Switches Selection Sort:", SwitchesSelection)
    print()
    print("\033[1;91mInsertion Sort:\033[0m", insertion_sort(data.copy()))
    print("\033[1;31mComparaciones Insertion Sort:\033[0m", ComparacionesInsertion, "Switches Insertion Sort:", SwitchesInsertion)