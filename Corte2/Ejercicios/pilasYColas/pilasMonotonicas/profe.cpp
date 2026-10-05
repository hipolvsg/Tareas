#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
using namespace std;



vector<int> siguienteMayor(const vector<int>& a);
vector<int> temperaturaDiaria(const vector<int>& b);
int main() {
    vector<int> a = {2,1,2,4,3};
    vector<int> b = {73, 74, 75, 71, 69, 72, 76, 73};
    for (int x: siguienteMayor(a)) cout<<x<<" " << endl;
    for (int x: temperaturaDiaria(b)) cout<<x<<" " << endl;
    return 0;
}

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
vector<int> temperaturaDiaria(const vector<int>& b) {
    int n = b.size();
    vector<int> result(n, -1);
    stack<int> pila;

    for (int i = 0; i < n; ++i) {
        while (!pila.empty() && b[i] > b[pila.top()]) {
            result[pila.top()] = i;
            pila.pop();
        }
        pila.push(i);
    }

    return result;
}