#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    int topIndex;
    int size;
    int* arr; // Use pointer for dynamic memory

    Stack(int size) {
        this->size = size;
        topIndex = -1; // Start with -1 to represent an empty stack
        arr = new int[size];
    }

    void push(int num) {
        if (topIndex < size - 1) {
            arr[++topIndex] = num;
        } else {
            cout << "Stack Overflow\n";
        }
    }

    int top() {
        if (topIndex >= 0)
            return arr[topIndex];
        else {
            cout << "Stack is empty\n";
            return -1; // Or throw an exception
        }
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack ob(5);
    ob.push(2);
    cout << ob.top() << "\n";
    return 0;
}
