#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class stack{
    int arr[100];
    int top = -1;

    void push(int x) {
        if (top < 99) {
            arr[++top] = x;
        }
    }

    int pop() {
        if (top >= 0) {
            return arr[top--];
        }
        return -1; // Stack is empty
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        }
        return -1; // Stack is empty
    }

    bool isEmpty() {
        return top == -1;
    }

    int size() {
        return top + 1;
    }
};

class hashTable {
public:
    int nameKey = 0;
    unordered_map<string, int> index;

    hashear(vector<string> arr = {"Mafe", "Daniel", "Edward", "Checho", "Chanty", "David", "Nico", "Esteban", "Santiago", "Asier", "Andres"}) {
        for (string e: arr){
            for (char c: e){
                c = tolower(c);
                char num = c - 97;
                nameKey += num;
            }
            nameKey = nameKey % 12;
            if (index.find(nameKey) != index.end()){
                index[e] = nameKey;
            }else {
                index[e] = nameKey

            }

            nameKey = 0;
        }
    }

};
