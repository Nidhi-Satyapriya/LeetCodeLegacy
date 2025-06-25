### **Definition of Heap:**

A **heap** is a special type of **binary tree** that satisfies two main properties:

1. **Complete Binary Tree**: All levels are fully filled except possibly the last, which is filled from left to right.
2. **Heap Property**:

   * In a **Max Heap**, for every node `i`, the value of `i` is **greater than or equal to** the values of its children.
   * In a **Min Heap**, for every node `i`, the value of `i` is **less than or equal to** the values of its children.

---

### **Key Features of Heap:**

####  1. **Heap Structure**:

* It is a **complete binary tree**.
* Often implemented as an **array** (not using pointers like other binary trees).

####  2. **Heap Types**:

* **Max Heap**: Root node has the **maximum** value.
* **Min Heap**: Root node has the **minimum** value.

####  3. **Efficient Operations**:

* **Insertion**: `O(log n)`
* **Deletion (usually of root)**: `O(log n)`
* **Peek (get min/max)**: `O(1)`

####  4. **Index Relationships (Array Representation)**:

* Parent of node at index `i`: `(i - 1) // 2`
* Left child: `2i + 1`
* Right child: `2i + 2`

####  5. **Applications**:

* **Priority Queues**: Most common use-case.
* **Heap Sort**: An efficient sorting algorithm.
* **Graph Algorithms**: Like Dijkstra’s and Prim’s algorithms.

####  6. **No Guarantee of BST Ordering**:

* Unlike binary search trees, heaps do **not** guarantee in-order traversal or sorted order of elements.

---

Sure! Let's break down **Heapify** and **Heap Sort** clearly:

---

##  **1. Heapify:**

### **Definition:**

**Heapify** is the process of converting a **binary tree** (or part of it) into a **valid heap** (min-heap or max-heap).
--

### 🔧 **How Heapify Works (Max Heap Example):**

Given a node `i` in an array, **heapify** compares `i` with its left and right children:

1. Find the largest among `i`, `left(i)`, and `right(i)`.
2. If one of the children is larger, **swap** it with `i`.
3. **Recursively heapify** the affected subtree.

---

###  **Example:**

Array = `[3, 9, 2, 1, 4, 5]` (not a heap)

Start heapifying from the last non-leaf node:

* Node `2` at index 2 → children: `5`
* Swap 2 and 5 → `[3, 9, 5, 1, 4, 2]`

Then check other nodes until the heap property is satisfied for the whole tree.

---

##  **2. Heap Sort:**

###  **Definition:**

**Heap Sort** is a **comparison-based** sorting technique that uses a **heap data structure**.

###  **Steps:**

#### Step 1: **Build a Max Heap** from the array.

#### Step 2: **Swap the root (largest)** with the **last element**.

#### Step 3: **Reduce heap size** by 1 and **heapify** the root again.

#### Step 4: Repeat Step 2 & 3 until the array is sorted.

create-delete-heapify
---

###  **Example (Heap Sort on Array `[4, 10, 3, 5, 1]`):**

####  Initial Array:

```
[4, 10, 3, 5, 1]
```

#### ✅ Build Max Heap:

```
[10, 5, 3, 4, 1]
```

#### ✅ Heap Sort Process:

1. Swap 10 and 1 → `[1, 5, 3, 4, 10]`
2. Heapify → `[5, 4, 3, 1, 10]`
3. Swap 5 and 1 → `[1, 4, 3, 5, 10]`
4. Heapify → `[4, 1, 3, 5, 10]`
5. Continue until sorted...

#### ✅ Final Sorted Array:

```
[1, 3, 4, 5, 10]
```

---

## 🕒 **Time Complexity:**

| Operation  | Time       |
| ---------- | ---------- |
| Build Heap | O(n)       |
| Heapify    | O(log n)   |
| Heap Sort  | O(n log n) |

---

