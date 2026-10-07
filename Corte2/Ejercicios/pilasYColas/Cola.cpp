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