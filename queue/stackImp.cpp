//2 stack
 void Push(int data) {
    // Pop out all elements from the stack input
    while (!input.empty()) {
      output.push(input.top());
      input.pop();
    }
    // Insert the desired element in the stack input
    cout << "The element pushed is " << data << endl;
    input.push(data);
    // Pop out elements from the stack output and push them into the stack input
    while (!output.empty()) {
      input.push(output.top());
      output.pop();
    }
  }

  // 1 stack
  #include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s;

public:
    // Enqueue (push) element into the queue
    void enqueue(int x) {
        s.push(x);
    }

    // Dequeue (pop) the front element
    int dequeue() {
        if (s.empty()) {
            cout << "Queue is empty\n";
            return -1;
        }

        int x = s.top();
        s.pop();

        // Base case: last element is the front of the queue
        if (s.empty()) {
            return x;
        }

        // Recursive call to reach the bottom
        int item = dequeue();

        // Push the current top back after recursion
        s.push(x);

        return item;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return s.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << q.dequeue() << endl; // 10
    cout << q.dequeue() << endl; // 20
    cout << q.dequeue() << endl; // 30
    cout << q.dequeue() << endl; // Queue is empty

    return 0;
}
