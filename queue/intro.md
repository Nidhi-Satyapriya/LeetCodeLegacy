| Queue Type     | Insertion | Deletion | Access Front/Back |
| -------------- | --------- | -------- | ----------------- |
| Standard Queue | O(1)      | O(1)     | O(1)              |
| Circular Queue | O(1)      | O(1)     | O(1)              |
| Deque          | O(1)      | O(1)     | O(1)              |
| Priority Queue | O(log n)  | O(log n) | O(1)              |

---

##  **What is a Priority Queue?**

A **Priority Queue** is a special type of **queue** where element are dequeued based on **priority**, not the order of arrival (as in a normal queue).

* In a **Max Priority Queue**, the **highest priority (largest value)** is dequeued first.
* In a **Min Priority Queue**, the **lowest priority (smallest value)** is dequeued first.

---

##  **How is it Implemented Using Heap?**

A **heap** is the most efficient data structure for implementing a priority queue.

### ✅ Implementation:

* Use a **Max Heap** for a Max Priority Queue.
* Use a **Min Heap** for a Min Priority Queue.

###  Operations:

| Operation                       | Time Complexity | Description                                 |
| ------------------------------- | --------------- | ------------------------------------------- |
| `insert()`                      | O(log n)        | Insert a new element while maintaining heap |
| `getMax()` / `getMin()`         | O(1)            | Access highest/lowest priority element      |
| `extractMax()` / `extractMin()` | O(log n)        | Remove highest/lowest priority              |

---

## 🧠 **Example in C++ (Using STL)**

```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    // Max Priority Queue (default)
    priority_queue<int> maxPQ;
    maxPQ.push(30);
    maxPQ.push(10);
    maxPQ.push(20);

    cout << "Max Priority Queue (Top): " << maxPQ.top() << endl; // 30

    // Min Priority Queue using greater<int>
    priority_queue<int, vector<int>, greater<int>> minPQ;
    minPQ.push(30);
    minPQ.push(10);
    minPQ.push(20);

    cout << "Min Priority Queue (Top): " << minPQ.top() << endl; // 10

    return 0;
}
```

---

## 📦 **Use Cases of Priority Queue:**

1. **CPU Scheduling**: Prioritize jobs based on importance or deadlines.
2. **Dijkstra's & A\* Algorithms**: For finding shortest/optimal paths in graphs.
3. **Huffman Coding**: Used in data compression.
4. **Operating System Task Management**
5. **Event-Driven Simulations**: Process events in the order of their scheduled times.
6. **Real-Time Systems**: Prioritize urgent tasks over normal ones.

---

##  Summary:

| Feature       | Priority Queue                       |
| ------------- | ------------------------------------ |
| Based On      | Priority (not arrival)               |
| Backed By     | Binary Heap (usually)                |
| Efficient For | Scheduling, Pathfinding, Compression |
| STL Support   | `priority_queue` in C++              |

---

Sure! Here's a complete explanation of **Deque** (Double-Ended Queue), including its **features, operations, types**, and **use cases**:

---

##  **What is a Deque?**

A **Deque (Double-Ended Queue)** is a linear data structure that allows **insertion and deletion from both ends**:

* **Front**
* **Rear**

> It combines the features of both **stacks** and **queues**.

---

## 🚀 **Key Features of Deque:**

| Feature                   | Description                                                      |
| ------------------------- | ---------------------------------------------------------------- |
| Double-ended access       | Insert and delete from both **front** and **rear**               |
| Flexible                  | Can function as **stack** or **queue**                           |
| Supports dynamic resizing | In many languages/libraries (e.g., `deque` in C++ STL or Python) |
| Constant time operations  | All operations (insert/delete/peek) are **O(1)**                 |

---

## ⚙️ **Types of Deque:**

### 1. **Input-Restricted Deque**

* **Insertion** only at **rear**
* **Deletion** from **front** and **rear**

### 2. **Output-Restricted Deque**

* **Insertion** at **front** and **rear**
* **Deletion** only from **front**

---

## 🔧 **Deque Operations and Time Complexities:**

| Operation       | Description                 | Time Complexity |
| --------------- | --------------------------- | --------------- |
| `push_front(x)` | Insert element at front     | O(1)            |
| `push_back(x)`  | Insert element at rear      | O(1)            |
| `pop_front()`   | Remove element from front   | O(1)            |
| `pop_back()`    | Remove element from rear    | O(1)            |
| `front()`       | Get front element           | O(1)            |
| `back()`        | Get rear element            | O(1)            |
| `isEmpty()`     | Check if deque is empty     | O(1)            |
| `size()`        | Number of elements in deque | O(1)            |

---

## 💡 **Use Cases of Deque:**

1. **Sliding Window Problems** (e.g., max/min in subarrays)
2. **Palindrome Checking**
3. **Undo/Redo Functionality**
4. **Job Scheduling Systems**
5. **Implementing Both Stack & Queue**
6. **Browser History Navigation** (back/forward actions)

---

## 🧪 **C++ STL Example:**

```cpp
#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<int> dq;

    dq.push_back(10);  // [10]
    dq.push_front(5);  // [5, 10]
    dq.push_back(15);  // [5, 10, 15]

    cout << "Front: " << dq.front() << endl;  // 5
    cout << "Back: " << dq.back() << endl;    // 15

    dq.pop_front();  // [10, 15]
    dq.pop_back();   // [10]

    cout << "Size: " << dq.size() << endl;    // 1
    return 0;
}
```

---
