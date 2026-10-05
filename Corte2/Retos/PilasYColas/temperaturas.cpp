#include <bits/stdc++.h>
using namespace std;

vector<int> siguienteMayor(const vector<int>& a) {
    int n = a.size();
    vector<int> result(n, -1);
    stack<int> pila;

    for (int i = 0; i < n; ++i) {
        while (!pila.empty() && a[i] > a[pila.top()]) {
            result[pila.top()] = a[i];
            pila.pop();
        }
        pila.push(i);
    }

    return result;
}

vector<int> temperaturaDiaria(const vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> pila;

    for (int i = 0; i < n; ++i) {
        while (!pila.empty() && temperatures[i] > temperatures[pila.top()]) {
            int prevIndex = pila.top();
            pila.pop();
            result[prevIndex] = i - prevIndex;
        }
        pila.push(i);
    }

    return result;
}

int main() {
    vector<int> a = {2, 1, 2, 4, 3};
    vector<int> b = {73, 74, 75, 71, 69, 72, 76, 73};

    cout << "siguienteMayor: ";
    for (int x : siguienteMayor(a)) {
        cout << x << " ";
    }
    cout << endl;

    int dia = 0;
    
    cout << "temperaturaDiaria: ";
    for (int x : temperaturaDiaria(b)) {
        
        cout << "día " << dia << ": ";
        cout << " Se estima que en " << x << " días habrá una temperatura mayor.";
        dia++;
    }
    cout << endl;

    return 0;
}
