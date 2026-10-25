# DSA Submissions - Comprehensive Documentation

A repository of Data Structures and Algorithms implementations in C++, containing sorting algorithms, linked list variations, stacks, queues, binary trees, binary search trees, AVL trees, heaps, and algorithmic problems.

---

## Table of Contents

- [Overview & Tech Stack](#overview--tech-stack)
- [1. Sorting Algorithms](#1-sorting-algorithms)
  - [binSort.cpp](#binsortcpp)
  - [bubbleSort.cpp](#bubblesortcpp)
  - [bubbleSortLL.cpp](#bubblesortllcpp)
  - [bucketSort.cpp](#bucketsortcpp)
  - [heapSort.cpp](#heapsortcpp)
  - [insertionSort.cpp](#insertionsortcpp)
  - [insertionSortLL.cpp](#insertionsortllcpp)
  - [mergeSort.cpp](#mergesortcpp)
  - [quickSort.cpp](#quicksortcpp)
  - [radixSort.cpp](#radixsortcpp)
  - [selectionSort.cpp](#selectionsortcpp)
  - [selectionSortLL.cpp](#selectionsortllcpp)
- [2. Linked Lists](#2-linked-lists)
  - [convertArr2LL.cpp](#convertarr2llcpp)
  - [traversalLL.cpp](#traversalllcpp)
  - [singlyLL.cpp](#singlyllcpp)
  - [doublyLL.cpp](#doublyllcpp)
  - [reverseSingly.cpp](#reversesingly)
  - [reverseDoubly.cpp](#reversedoublycpp)
  - [listsBasicFunctions.cpp](#listsbasicfunctionscpp)
  - [kthSmallestLL.cpp](#kthsmallestllcpp)
- [3. Stacks & Queues](#3-stacks--queues)
  - [stackArr.cpp](#stackarrcpp)
  - [stackLL..cpp](#stackllcpp)
  - [queue.cpp](#queuecpp)
  - [queueLL.cpp](#queuellcpp)
  - [circularQueue.cpp](#circularqueuecpp)
  - [circularQueueLL..cpp](#circularqueuellcpp)
- [4. Trees & Balanced Trees](#4-trees--balanced-trees)
  - [BT.cpp](#btcpp)
  - [BST.cpp](#bstcpp)
  - [AVL_Rotations.cpp](#avl_rotationscpp)
  - [AVL_or_not.cpp](#avl_or_notcpp)
- [5. Heaps](#5-heaps)
  - [maxHeapify.cpp](#maxheapifycpp)
  - [maxHeapBT.cpp](#maxheapbtcpp)
- [6. Algorithmic Problems](#6-algorithmic-problems)
  - [findDuplicate.cpp](#findduplicatecpp)
  - [kSmallestElements.cpp](#ksmallestelementscpp)
  - [moveZeroesToEnd.cpp](#movezeroestoendcpp)
  - [summList.cpp](#summlistcpp)
  - [towerOfHanoi.cpp](#towerofhanoicpp)

---

## Overview & Tech Stack

- **Language:** C++ (C++11 / C++14 standard compliant)
- **Standard Library:** Uses standard I/O streams (`<iostream>`, `<cstdio>`), STL containers (`<vector>`, `<queue>`, `<algorithm>`), and `<bits/stdc++.h>`.
- **Focus Areas:** Elementary and Advanced Sorting, Linear Data Structures (Contiguous and Pointer-Based), Non-linear Data Structures (Hierarchical Trees, Self-balancing Trees, Priority Queues), and classic two-pointer / divide-and-conquer problem solving.

---

## 1. Sorting Algorithms

### [binSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/binSort.cpp)

#### Description
Implements the Bin Sort (or basic Counting Sort for non-negative integers). It determines the maximum value present in the input array, dynamically sizes a frequency array (bin) to count occurrences of each element, and reconstructs the array in non-decreasing order by writing out elements based on their frequencies.

#### Algorithm
1. Scan the array to find the maximum element M = max(arr).
2. Allocate a frequency array `bin` of size M + 1 initialized to zero.
3. Traverse the input array and increment `bin[arr[i]]` for each element.
4. Iterate from index `0` to M in `bin`. For each non-zero frequency, write the index back into the original array and decrement the frequency count until it reaches zero.

#### Complexity
- **Time Complexity:**
  - Best Case: O(N + M)
  - Average Case: O(N + M)
  - Worst Case: O(N + M) where N is the number of elements and M is the maximum value.
- **Space Complexity:** O(M) auxiliary space for the frequency bucket array.

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {3, 2, 10, 5, 4, 7, 8, 9, 1, 6}` (N = 10, M = 10)
  - **Output:** `Sorted array: 1 2 3 4 5 6 7 8 9 10 `
- **Test Case 2 (Duplicates):**
  - **Input:** `arr = {4, 1, 4, 2, 0, 2}` (N = 6, M = 4)
  - **Output:** `Sorted array: 0 1 2 2 4 4 `

---

### [bubbleSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/bubbleSort.cpp)

#### Description
Implements an optimized Bubble Sort on an array with an early-exit optimization. In each pass, adjacent elements are compared and swapped if they are out of order, bubbling the largest unsorted element to its correct position at the end. An early termination flag `didSwap` stops execution if a pass makes zero swaps.

#### Algorithm
1. Loop i from N - 1 down to 0 representing the boundary of unsorted elements.
2. Initialize `didSwap = 0`.
3. Loop j from 0 to i - 1:
   - If `arr[j] > arr[j + 1]`, swap `arr[j]` and `arr[j + 1]` and set `didSwap = 1`.
4. If `didSwap == 0`, break early (array is already sorted).

#### Complexity
- **Time Complexity:**
  - Best Case: O(N) (when array is already sorted, breaks after 1st pass)
  - Average Case: O(N^2)
  - Worst Case: O(N^2) (reverse sorted array)
- **Space Complexity:** O(1) in-place sorting.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    6
    13 46 24 52 20 9
    ```
  - **Output:**
    ```text
    runs
    runs
    runs
    runs
    runs
    9 13 20 24 46 52 
    ```
- **Test Case 2 (Already Sorted):**
  - **Input:**
    ```text
    4
    1 2 3 4
    ```
  - **Output:**
    ```text
    1 2 3 4 
    ```

---

### [bubbleSortLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/bubbleSortLL.cpp)

#### Description
Implements Bubble Sort directly on a Singly Linked List by swapping node data values. Traverses the linked list nodes, comparing `p->data` with `p->next->data`, and applies the early termination flag if no swaps occur across a pass.

#### Algorithm
1. Construct a singly linked list from N user inputs.
2. Outer loop runs i from N - 1 down to 1.
3. Set pointer `p = head` and `didSwap = 0`.
4. Inner loop runs j from 0 to i - 1:
   - If `p->data > p->next->data`, swap their `data` members and set `didSwap = 1`.
   - Move `p = p->next`.
5. If `didSwap == 0`, terminate early.

#### Complexity
- **Time Complexity:**
  - Best Case: O(N)
  - Average Case: O(N^2)
  - Worst Case: O(N^2)
- **Space Complexity:** O(1) auxiliary space (ignoring linked list allocation O(N)).

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    5
    5 1 4 2 8
    ```
  - **Output:**
    ```text
    runs
    runs
    runs
    1 2 4 5 8 
    ```
- **Test Case 2 (Single element):**
  - **Input:**
    ```text
    1
    42
    ```
  - **Output:**
    ```text
    42 
    ```

---

### [bucketSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/bucketSort.cpp)

#### Description
Implements Bucket Sort for integer values by distributing array elements into k buckets based on normalized value ranges, sorting each bucket independently using `std::sort`, and concatenating all buckets back into the original array.

#### Algorithm
1. Find `maxElement` in the array and increment it by 1 (`maxElement++`) to prevent index out of bounds.
2. Initialize an array of vectors `buckets[k]`.
3. For each element `arr[i]`, compute bucket index `(k * arr[i]) / maxElement` and push `arr[i]` into `buckets[bucketIndex]`.
4. Sort each individual bucket using standard quicksort/introsort (`std::sort`).
5. Iterate through buckets `0` to k-1 and copy elements back into `arr`.

#### Complexity
- **Time Complexity:**
  - Best Case: O(N + k) (uniformly distributed)
  - Average Case: O(N + N^2/k + k) (or O(N) when uniformly distributed with k ~ N)
  - Worst Case: O(N^2) (all elements cluster in a single bucket)
- **Space Complexity:** O(N + k) auxiliary storage for the buckets.

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {30, 40, 10, 80, 5, 12, 70}`, k = 4
  - **Output:** `5 10 12 30 40 70 80 `
- **Test Case 2:**
  - **Input:** `arr = {100, 20, 50, 10, 90}`, k = 3
  - **Output:** `10 20 50 90 100 `

---

### [heapSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20%281%29/DSA-submissions-main/heapSort.cpp)

#### Description
Implements the 1-based indexing in-place Heap Sort algorithm using a binary max-heap. It first converts the array into a max heap (`BuildHeap`), then repeatedly swaps the root (maximum element) with the last unsorted element and restores the heap property using `algo` (max-heapify).

#### Algorithm
1. **Max-Heapify (`algo(a, i, n)`):**
   - Compute `left = 2*i` and `right = 2*i + 1`.
   - Identify the index `large` holding the maximum among `a[i]`, `a[left]`, and `a[right]`.
   - If `large != i`, swap `a[i]` with `a[large]` and recursively call `algo(a, large, n)`.
2. **BuildHeap:** Run `algo` bottom-up from i = floor(n/2) down to 1.
3. **HeapSort:** Loop i from n down to 2:
   - Swap `a[1]` with `a[i]`.
   - Call `algo(a, 1, i - 1)` on the reduced heap.

#### Complexity
- **Time Complexity:**
  - Best / Average / Worst Case: O(N log N)
  - Heap Construction: O(N)
- **Space Complexity:** O(log N) recursion stack space (O(1) auxiliary memory).

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    6
    12 11 13 5 6 7
    ```
  - **Output:**
    ```text
    Sorted array: 5 6 7 11 12 13 
    ```
- **Test Case 2:**
  - **Input:**
    ```text
    5
    50 30 20 15 10
    ```
  - **Output:**
    ```text
    Sorted array: 10 15 20 30 50 
    ```

---

### [insertionSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/insertionSort.cpp)

#### Description
Implements the classic array-based Insertion Sort. Divides the array virtually into sorted and unsorted subarrays; elements from the unsorted part are picked and placed at the correct position in the sorted part by continually shifting/swapping adjacent elements backwards.

#### Algorithm
1. Iterate i from index 1 to N - 1.
2. Set j = i.
3. While j > 0 and `arr[j - 1] > arr[j]`:
   - Swap `arr[j - 1]` with `arr[j]`.
   - Decrement j.

#### Complexity
- **Time Complexity:**
  - Best Case: O(N) (when already sorted, condition fails immediately)
  - Average Case: O(N^2)
  - Worst Case: O(N^2) (strictly reverse sorted)
- **Space Complexity:** O(1) in-place.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    5
    14 9 15 12 6
    ```
  - **Output:**
    ```text
    6 9 12 14 15 
    ```
- **Test Case 2:**
  - **Input:**
    ```text
    4
    1 2 3 4
    ```
  - **Output:**
    ```text
    1 2 3 4 
    ```

---

### [insertionSortLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/insertionSortLL.cpp)

#### Description
Performs an in-place Insertion Sort on a Singly Linked List. Uses a nested pointer traversal to compare the current node `i` against preceding nodes `j` starting from `head` up to `i`, swapping their data values when an inversion is detected.

#### Algorithm
1. If `head == nullptr`, return.
2. Outer loop: `i` starts at `head->next`, advancing `i = i->next` until end.
3. Inner loop: `j` starts at `head`, advancing `j = j->next` while `j != i`.
4. If `j->data > i->data`, `swap(j->data, i->data)`.

#### Complexity
- **Time Complexity:**
  - Best Case: O(N)
  - Average / Worst Case: O(N^2)
- **Space Complexity:** O(1) auxiliary space.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    4
    30 20 40 10
    ```
  - **Output:**
    ```text
    10 20 30 40 
    ```
- **Test Case 2:**
  - **Input:**
    ```text
    3
    5 3 1
    ```
  - **Output:**
    ```text
    1 3 5 
    ```

---

### [mergeSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/mergeSort.cpp)

#### Description
Implements the Divide and Conquer Merge Sort algorithm on an `std::vector<int>`. Recursively divides the array into two halves, sorts both halves, and then merges them back into sorted order using a temporary vector.

#### Algorithm
1. **Divide:** Find the midpoint `mid = (low + high) / 2`.
2. **Conquer:** Recursively sort left subarray `ms(arr, low, mid)` and right subarray `ms(arr, mid + 1, high)`.
3. **Combine (`merge`):**
   - Initialize two pointers `left = low` and `right = mid + 1`.
   - Compare `arr[left]` and `arr[right]`, appending the smaller element to a temporary buffer `temp`.
   - Append remaining elements from both halves.
   - Copy back from `temp` into `arr[low..high]`.

#### Complexity
- **Time Complexity:**
  - Best / Average / Worst Case: O(N log N)
- **Space Complexity:** O(N) auxiliary space for merge buffer + O(log N) recursion stack.

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {5, 2, 3, 1, 4}`
  - **Output:** `1 2 3 4 5 `
- **Test Case 2:**
  - **Input:** `arr = {38, 27, 43, 3, 9, 82, 10}`
  - **Output:** `3 9 10 27 38 43 82 `

---

### [quickSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/quickSort.cpp)

#### Description
Implements Quick Sort using Hoare-like bidirectional partitioning. Selects the first element as the pivot, rearranges elements such that smaller or equal elements move to the left and larger elements move to the right, and then recurses on both partitions.

#### Algorithm
1. **Partition (`Partition(arr, low, high)`):**
   - Choose `pivot = arr[low]`, `start = low`, `end = high`.
   - Increment `start` while `arr[start] <= pivot`.
   - Decrement `end` while `arr[end] > pivot`.
   - If `start < end`, swap `arr[start]` and `arr[end]`.
   - When pointers cross, swap `arr[low]` with `arr[end]`, returning `end` as pivot index.
2. **Recursion (`qs`):**
   - If `low < high`, partition the array at `pIndex`, then sort `[low, pIndex - 1]` and `[pIndex + 1, high]`.

#### Complexity
- **Time Complexity:**
  - Best Case: O(N log N) (balanced splits)
  - Average Case: O(N log N)
  - Worst Case: O(N^2) (already sorted or reverse sorted with fixed first pivot)
- **Space Complexity:** O(log N) average call stack, O(N) worst case.

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {10, 7, 8, 9, 1, 5}`
  - **Output:** `1 5 7 8 9 10 `
- **Test Case 2:**
  - **Input:** `arr = {4, 1, 3, 9, 7}`
  - **Output:** `1 3 4 7 9 `

---

### [radixSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/radixSort.cpp)

#### Description
Implements Least Significant Digit (LSD) Radix Sort for integers. It finds the maximum element to determine the number of digits, and applies stable Counting Sort on each decimal digit place (`exp = 1, 10, 100, ...`).

#### Algorithm
1. Find `maxNum = *max_element(arr.begin(), arr.end())`.
2. For exponent `exp = 1, 10, 100, ...` while `maxNum / exp > 0`:
   - Initialize `count[10] = {0}` and `output` vector of size N.
   - Extract digit `(arr[i] / exp) % 10` and increment `count[digit]`.
   - Compute prefix sums: `count[i] += count[i - 1]` for cumulative positions.
   - Build `output` in reverse (to ensure stability): `output[count[digit] - 1] = arr[i]`, `count[digit]--`.
   - Copy `output` back to `arr`.

#### Complexity
- **Time Complexity:**
  - All Cases: O(d * (N + b)), where d = log10(M) is the maximum number of digits and b = 10 is base.
- **Space Complexity:** O(N + b) for output and count buffers.

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {170, 45, 75, 90, 802, 24, 2, 66}`
  - **Output:** `2 24 45 66 75 90 170 802 `
- **Test Case 2:**
  - **Input:** `arr = {329, 457, 657, 839, 436, 720, 355}`
  - **Output:** `329 355 436 457 657 720 839 `

---

### [selectionSort.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/selectionSort.cpp)

#### Description
Implements Selection Sort on an array. Repeatedly finds the minimum element from the unsorted suffix of the array and swaps it with the first unsorted position.

#### Algorithm
1. Loop i from 0 to N - 2:
   - Assume minimum index `mini = i`.
   - Loop j from i to N - 1:
     - If `arr[j] < arr[mini]`, update `mini = j`.
   - Swap `arr[i]` and `arr[mini]`.

#### Complexity
- **Time Complexity:**
  - Best / Average / Worst Case: O(N^2) (always executes N(N - 1) / 2 comparisons).
- **Space Complexity:** O(1) in-place.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    5
    64 25 12 22 11
    ```
  - **Output:**
    ```text
    11 12 22 25 64 
    ```
- **Test Case 2:**
  - **Input:**
    ```text
    3
    3 2 1
    ```
  - **Output:**
    ```text
    1 2 3 
    ```

---

### [selectionSortLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/selectionSortLL.cpp)

#### Description
Applies Selection Sort on a Singly Linked List by repeatedly scanning the remainder of the linked list for the node containing the minimum data value and swapping node values with the current head of the unsorted segment.

#### Algorithm
1. Outer loop pointer `i` traverses from `head` while `i != nullptr && i->next != nullptr`.
2. Pointer `mini = i`.
3. Inner loop pointer `j` iterates from `i` to `nullptr`:
   - If `j->data < mini->data`, update `mini = j`.
4. Swap `i->data` and `mini->data`.
5. Advance `i = i->next`.

#### Complexity
- **Time Complexity:**
  - Best / Average / Worst Case: O(N^2).
- **Space Complexity:** O(1) auxiliary space.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    5
    29 10 14 37 13
    ```
  - **Output:**
    ```text
    10 13 14 29 37 
    ```
- **Test Case 2:**
  - **Input:**
    ```text
    2
    9 2
    ```
  - **Output:**
    ```text
    2 9 
    ```

---

## 2. Linked Lists

### [convertArr2LL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/convertArr2LL.cpp)

#### Description
Demonstrates how to construct a Singly Linked List dynamically from an `std::vector<int>` and access its root element.

#### Algorithm
1. Initialize `head = new Node(arr[0])`.
2. Set a traversal pointer `mover = head`.
3. Loop i from 1 to `arr.size() - 1`:
   - Create `temp = new Node(arr[i])`.
   - Link `mover->next = temp`.
   - Move `mover = temp`.
4. Return `head`.

#### Complexity
- **Time Complexity:** O(N) where N is vector size.
- **Space Complexity:** O(N) for allocating N linked list nodes.

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {12, 5, 8, 7}`
  - **Output:** `12` (prints `head->data`)
- **Test Case 2:**
  - **Input:** `arr = {99, 10, 20}`
  - **Output:** `99`

---

### [traversalLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/traversalLL.cpp)

#### Description
Converts an array into a Singly Linked List, prints all node values sequentially, and computes the total count (length) of the list.

#### Algorithm
1. `convertArrToLL(arr)` creates linked list nodes sequentially.
2. `printLL(head)`: Traverses using `temp = head`, printing `temp->data` until `temp == NULL`.
3. `lengthofLL(head)`: Traverses while incrementing counter `cnt++` until `NULL`.

#### Complexity
- **Time Complexity:**
  - Creation: O(N)
  - Traversal (`printLL`): O(N)
  - Length Calculation (`lengthofLL`): O(N)
- **Space Complexity:** O(N) for nodes; O(1) auxiliary space for traversal.

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {12, 5, 8, 7}`
  - **Output:**
    ```text
    12 5 8 7 
    Length of linked list: 4
    ```

---

### [singlyLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/singlyLL.cpp)

#### Description
A comprehensive, interactive, menu-driven Singly Linked List implementation providing complete CRUD (Create, Read, Update, Delete) functionality covering boundary and positional operations:
- Insertions: Head, Tail, K-th position (1-based), Index (0-based), Before value, After value.
- Deletions: Head, Tail, K-th position (1-based), Index (0-based), Value, Before value, After value.
- Traversal & Display.

#### Algorithm
- **Insert Operations:**
  - `insertHead`: New node points to existing head; returns new node.
  - `insertTail`: Traverse to the last node (`temp->next == nullptr`), attach `temp->next = newNode`.
  - `insertk` / `insertatIndex`: Step pointer to target - 1 position, rewire `newNode->next = temp->next`, `temp->next = newNode`.
  - `insertBeforeValue`: Search for node whose `next->data == target`, insert in between.
  - `insertAfterValue`: Search for node with `data == target`, insert immediately after.
- **Delete Operations:**
  - `deleteHead`: Shift `head = head->next`, delete old head.
  - `deleteTail`: Traverse to second-to-last node, delete `tail`, set `temp->next = nullptr`.
  - `deletek` / `deleteatIndex` / `deletevalue`: Unlink target node by routing preceding node's `next` pointer past it, then invoke `delete`.

#### Complexity
- **Time Complexity:**
  - Insert / Delete at Head: O(1)
  - Insert / Delete at Tail: O(N)
  - Insert / Delete at K / Index / Value: O(N)
  - Display / Clear: O(N)
- **Space Complexity:** O(1) auxiliary space per operation, O(N) overall node allocation.

#### Test Cases
- **Test Case 1 (Create and Traverse):**
  - **Input:** Choice `1`, N = 3, values `10 20 30`, Choice `15`, Choice `0`.
  - **Output:**
    ```text
    10 20 30 
    Exiting...
    ```
- **Test Case 2 (Insertions & Deletions):**
  - **Input:**
    - Insert Head `5` (Choice 2) -> `5`
    - Insert Tail `15` (Choice 3) -> `5 15`
    - Insert at K=2 value `10` (Choice 4) -> `5 10 15`
    - Delete Tail (Choice 9) -> `5 10`
    - Display (Choice 15)
  - **Output:** `5 10 `

---

### [doublyLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/doublyLL.cpp)

#### Description
A full-featured, menu-driven Doubly Linked List (DLL) program. Each node maintains both `next` and `back` (previous) pointers. Supports comprehensive insertion and deletion routines at head, tail, specific indices, 1-based positions, and relative to node values.

#### Algorithm
- **Two-way pointer adjustment:**
  - `inserthead`: Create new node with `next = head`, set `head->back = newNode` if list non-empty.
  - `inserttail`: Traverse to end node, link `tail->next = newNode` and `newNode->back = tail`.
  - `insertbeforevalue` / `insertaftervalue`: Re-link 4 pointers (`newNode->next`, `newNode->back`, preceding `next`, following `back`).
  - `deletek` / `deletevalue`: Re-link `prev->next = front` and `front->back = prev`, then isolate and delete the targeted node.

#### Complexity
- **Time Complexity:**
  - Insert / Delete Head: O(1)
  - Insert / Delete Tail (without tail pointer): O(N)
  - Positional Insert / Delete: O(N)
  - Display: O(N)
- **Space Complexity:** O(1) auxiliary space.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    - Choice `1` (Create), N = 3, Values: `1 2 3`
    - Choice `15` (Display)
    - Choice `0` (Exit)
  - **Output:** `1 2 3 `
- **Test Case 2 (Delete Value):**
  - **Input:**
    - List has `10 20 30`
    - Choice `12` (Delete Value), `20`
    - Choice `15` (Display)
  - **Output:** `10 30 `

---

### [reverseSingly.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/reverseSingly.cpp)

#### Description
Reverses a Singly Linked List iteratively using the classic three-pointer technique (`prev`, `current`, `nextnode`) in a single pass without extra memory.

#### Algorithm
1. Initialize `prev = nullptr`, `current = head`.
2. While `current != nullptr`:
   - Store next node: `nextnode = current->next`.
   - Reverse link: `current->next = prev`.
   - Shift pointers: `prev = current`, `current = nextnode`.
3. Return `prev` as the new head.

#### Complexity
- **Time Complexity:** O(N) linear time.
- **Space Complexity:** O(1) auxiliary space.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    4
    1 2 3 4
    ```
  - **Output:**
    ```text
    4 3 2 1 
    ```
- **Test Case 2:**
  - **Input:**
    ```text
    1
    100
    ```
  - **Output:**
    ```text
    100 
    ```

---

### [reverseDoubly.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/reverseDoubly.cpp)

#### Description
In-place reversal of a Doubly Linked List by swapping the `next` and `back` pointers of every node during a single forward pass.

#### Algorithm
1. If `head == nullptr` or `head->next == nullptr`, return `head`.
2. Initialize `current = head`, `newhead = nullptr`.
3. While `current != nullptr`:
   - Swap pointers: `swap(current->back, current->next)`.
   - Update `newhead = current`.
   - Advance: `current = current->back` (since `back` now holds the original `next` pointer).
4. Return `newhead`.

#### Complexity
- **Time Complexity:** O(N) single pass.
- **Space Complexity:** O(1) auxiliary space.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    4
    10 20 30 40
    ```
  - **Output:**
    ```text
    40 30 20 10 
    ```
- **Test Case 2:**
  - **Input:**
    ```text
    2
    5 9
    ```
  - **Output:**
    ```text
    9 5 
    ```

---

### [listsBasicFunctions.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/listsBasicFunctions.cpp)

#### Description
Demonstrates fundamental list operations implemented on a fixed-size contiguous array: linear search, inserting an element immediately after a specified key, and deleting an occurrence of a key by shifting elements leftward.

#### Algorithm
1. **Linear Search:** Iterate 0 <= i < n. If `arr[i] == key`, return i; else return -1.
2. **Insert after key:** Locate `key` at index i. Shift elements from index n down to i + 2 one position right. Set `arr[i + 1] = x`, increment n.
3. **Delete key:** Locate `key` at index i. Shift elements from index i to n - 2 left by setting `arr[j] = arr[j + 1]`. Decrement n.

#### Complexity
- **Time Complexity:**
  - `linearSearch`: O(N)
  - `insert`: O(N) due to shifting
  - `Delete`: O(N) due to shifting
  - `display`: O(N)
- **Space Complexity:** O(1) auxiliary memory.

#### Test Cases
- **Test Case 1:**
  - **Input (Interactive):**
    - Search key: `4`
    - Insert key & element: `4 5`
    - Delete key: `7`
  - **Output:**
    ```text
    Element found at index 1
    Elements being displayed: 1 4 5 6 7 8 
    Elements being displayed: 1 4 5 6 8 
    ```

---

### [kthSmallestLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/kthSmallestLL.cpp)

#### Description
Finds the k-th smallest element in a Singly Linked List using the Quickselect algorithm applied via node pointers. Selects a pivot node, partitions the linked list around it, and narrows the search range based on the pivot's 0-indexed position.

#### Algorithm
1. Build linked list from N inputs.
2. **Partition:**
   - Choose `high->data` as pivot.
   - Pointer `i = low`. For `j = low` to `high`:
     - If `j->data <= pivot`, swap `i->data` and `j->data`, advance `i = i->next`.
   - Swap `i->data` and `high->data`, return `i`.
3. **Selectk (`selectk(head, k)`):**
   - Calculate position of `pivotNode` using `getpos(head, pivotNode)`.
   - If `pivotpos == k`, element is in position.
   - If `pivotpos < k`, recurse on right range `low = pivotNode->next`.
   - If `pivotpos > k`, move `high` to the node immediately before `pivotNode`.
4. Traverse from `head` to index k-1 and print value.

#### Complexity
- **Time Complexity:**
  - Best / Average Case: O(N) (Quickselect expected runtime)
  - Worst Case: O(N^2) (unfavorable partitions in a singly linked list)
- **Space Complexity:** O(1) auxiliary space.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    6
    7 10 4 3 20 15
    3
    ```
  - **Output:**
    ```text
    3th/rd smallest element: 7
    ```
- **Test Case 2 (Invalid k):**
  - **Input:**
    ```text
    3
    1 2 3
    5
    ```
  - **Output:** `Invalid k`

---

## 3. Stacks & Queues

### [stackArr.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/stackArr.cpp)

#### Description
Array-based implementation of a LIFO (Last-In-First-Out) Stack inside the `ArrayStack` class with overflow and underflow protection and a complete interactive CLI.

#### Algorithm
1. `push(val)`: Check if `top == capacity - 1`. If full, print "Overflow". Otherwise, `top++` and `arr[top] = value`.
2. `pop()`: Check if `top == -1`. If empty, print "Stack underflow". Otherwise, print `arr[top]` and decrement `top--`.
3. `peek()`: Return/display `arr[top]` if `top != -1`.
4. `display()`: Traverse from `top` down to `0`.

#### Complexity
- **Time Complexity:**
  - `push`, `pop`, `peek`: O(1)
  - `display`: O(N)
- **Space Complexity:** O(K) where K is user-specified stack capacity.

#### Test Cases
- **Test Case 1:**
  - **Input:** Capacity `3`, Push `10`, Push `20`, Peek, Pop, Display, Exit.
  - **Output:**
    ```text
    Top element: 20
    Removed: 20
    Stack elements: 10 
    Exiting...
    ```
- **Test Case 2 (Overflow check):**
  - **Input:** Capacity `1`, Push `5`, Push `10`.
  - **Output:**
    ```text
    Overflow
    ```

---

### [stackLL..cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/stackLL..cpp)

#### Description
Linked-list-based Stack (`LinkedStack`) that dynamically grows and shrinks without fixed capacity constraints. Insertions and removals occur at the head node (`top`).

#### Algorithm
1. `push(value)`: Allocate `newNode(value)`, link `newNode->next = top`, update `top = newNode`.
2. `pop()`: If `top == nullptr`, underflow. Otherwise store `temp = top`, update `top = top->next`, delete `temp`.
3. `peek()`: Print `top->data` if stack is non-empty.
4. `display()`: Traverse linked list from `top` to `nullptr`.
5. Destructor deallocates remaining nodes to prevent memory leaks.

#### Complexity
- **Time Complexity:**
  - `push`, `pop`, `peek`: O(1) strict time guarantee.
  - `display`: O(N)
- **Space Complexity:** O(N) proportional to the number of pushed elements.

#### Test Cases
- **Test Case 1:**
  - **Input:** Push `100`, Push `200`, Push `300`, Display, Pop, Peek, Exit.
  - **Output:**
    ```text
    Stack elements: 300 200 100 
    Removed: 300
    Top element: 200
    Exiting...
    ```

---

### [queue.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/queue.cpp)

#### Description
Linear array-based Queue (FIFO). Operates with `front` fixed at index `0` and elements shifted leftward on every dequeue operation.

#### Algorithm
1. `queueEnqueue(val)`: If `rear == capacity`, queue is full. Else, `queue[rear++] = val`.
2. `queueDequeue()`: If `front == rear`, queue is empty. Else, shift all elements left: `queue[i] = queue[i + 1]` for i in [front, rear - 2], then decrement `rear--`.
3. `queuefront()`: Display `queue[front]`.
4. `queueDisplay()`: Print `queue[i]` from `front` to `rear - 1`.

#### Complexity
- **Time Complexity:**
  - `queueEnqueue`: O(1)
  - `queueDequeue`: O(N) due to shifting all elements left.
  - `queuefront`: O(1)
  - `queueDisplay`: O(N)
- **Space Complexity:** O(K) where K is array capacity.

#### Test Cases
- **Test Case 1:**
  - **Input:** Capacity `3`, Enqueue `1`, Enqueue `2`, Display, Dequeue, Display.
  - **Output:**
    ```text
    Queue elements: 1 2 
    Queue elements: 2 
    ```

---

### [queueLL.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/queueLL.cpp)

#### Description
Capacity-bounded Queue implemented via a Singly Linked List with `front` and `rear` pointers, ensuring O(1) enqueue and dequeue operations while enforcing maximum capacity.

#### Algorithm
1. `enqueue(data)`: If `size == cap`, queue is full. Create `newNode(data)`. If `front == nullptr`, `front = rear = newNode`. Else `rear->next = newNode; rear = newNode;`. Increment `size++`.
2. `dequeue()`: If `front == nullptr`, queue is empty. Remove node at `front`, advance `front = front->next`. If `front == nullptr`, set `rear = nullptr`. Decrement `size--`.
3. `showFront()`: Print `front->data`.

#### Complexity
- **Time Complexity:**
  - `enqueue`, `dequeue`, `showFront`: O(1)
  - `display`: O(N)
- **Space Complexity:** O(N) dynamic node memory (<= capacity).

#### Test Cases
- **Test Case 1:**
  - **Input:** Capacity `2`, Enqueue `10`, Enqueue `20`, Enqueue `30` (overflow), Front, Dequeue, Display.
  - **Output:**
    ```text
    Queue is full
    Front element is: 10
    Queue elements: 20 
    ```

---

### [circularQueue.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/circularQueue.cpp)

#### Description
Implements an Array-based Circular Queue using modular arithmetic. Solves the wasted space / shift overhead problem of linear queues by wrapping indices using `(index + 1) % cap`.

#### Algorithm
1. `queueEnqueue(data)`:
   - Check full condition: `(rear + 1) % cap == front`.
   - If empty (`front == -1`), set `front = rear = 0`.
   - Else set `rear = (rear + 1) % cap`.
   - Store `arr[rear] = data`.
2. `queueDequeue()`:
   - Check empty condition: `front == -1`.
   - If `front == rear`, last element removed -> reset `front = rear = -1`.
   - Else `front = (front + 1) % cap`.
3. `queueDisplay()`:
   - Loop `i` starting at `front`, printing `arr[i]`, and break after `i == rear`, stepping via `i = (i + 1) % cap`.

#### Complexity
- **Time Complexity:**
  - `queueEnqueue`, `queueDequeue`, `queuefront`: O(1)
  - `queueDisplay`: O(N)
- **Space Complexity:** O(K) array capacity.

#### Test Cases
- **Test Case 1:**
  - **Input:** Capacity `3`, Enqueue `10`, Enqueue `20`, Dequeue, Enqueue `30`, Enqueue `40`, Display.
  - **Output:**
    ```text
    Removed: 10
    Queue elements: 20 30 40 
    ```

---

### [circularQueueLL..cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/circularQueueLL..cpp)

#### Description
Linked-list queue implementation maintaining `front` and `rear` pointers with explicit dynamic memory deallocation upon dequeue and destruction.

#### Algorithm
1. `queueEnqueue(data)`: Allocate `newNode`. If `front == nullptr`, `front = rear = newNode`. Else `rear->next = newNode`, `rear = newNode`.
2. `queueDequeue()`: If `front == nullptr`, return empty. Extract node at `front`, update `front = front->next`, `delete temp`. If `front == nullptr`, set `rear = nullptr`.
3. `queueDisplay()`: Sequentially traverse from `front` to `nullptr`.

#### Complexity
- **Time Complexity:**
  - `queueEnqueue`, `queueDequeue`, `queuefront`: O(1)
  - `queueDisplay`: O(N)
- **Space Complexity:** O(N) dynamic node allocations.

#### Test Cases
- **Test Case 1:**
  - **Input:** Enqueue `5`, Enqueue `15`, Dequeue, Display, Exit.
  - **Output:**
    ```text
    Removed: 5
    Queue elements: 15 
    Exiting...
    ```

---

## 4. Trees & Balanced Trees

### [BT.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/BT.cpp)

#### Description
Standard Binary Tree implementation supporting interactive recursive creation, level-order insertion using `std::queue`, deletion by replacing the target node's value with the deepest rightmost node, and Inorder, Preorder, and Postorder tree traversals.

#### Algorithm
1. **Interactive Creation (`createBinaryTree`):** Prompt for node value, then recursively ask if left and right children exist (1 for Yes, 0 for No).
2. **Level-Order Insertion (`insertNode`):** Use BFS queue. Insert at the first available `left` or `right` null pointer.
3. **Deletion (`deleteNode`):**
   - Traverse via BFS to find target node `target` and the deepest rightmost node `last` (and its parent).
   - Copy `target->data = last->data`.
   - Disconnect and `delete last`.
4. **Traversals:**
   - Inorder: Left -> Root -> Right
   - Preorder: Root -> Left -> Right
   - Postorder: Left -> Right -> Root

#### Complexity
- **Time Complexity:**
  - Insert / Delete: O(N) (BFS traversal over tree nodes)
  - Traversals: O(N)
- **Space Complexity:** O(N) queue storage in BFS / recursion stack.

#### Test Cases
- **Test Case 1 (Creation and Display):**
  - **Input:**
    - Choice `1` (Create), Data: `1`, Left? `1`, Data: `2`, Left? `0`, Right? `0`, Right of 1? `1`, Data: `3`, Left? `0`, Right? `0`
    - Choice `4` (Display)
  - **Output:**
    ```text
    Inorder: 2 1 3 
    Preorder: 1 2 3 
    Postorder: 2 3 1 
    ```

---

### [BST.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/BST.cpp)

#### Description
Full implementation of a Binary Search Tree (BST) where each node contains `left`, `right`, and `parent` pointers. Supports unique-key insertion, search, in-order traversal, and complete three-case node deletion (leaf, single child, two children using in-order predecessor).

#### Algorithm
1. **Insertion (`insert`):**
   - If `value < root->val`, go left. If `root->left == nullptr`, attach new node and assign `parent`.
   - If `value > root->val`, go right. If `root->right == nullptr`, attach new node and assign `parent`.
   - Reject duplicates.
2. **Search (`search`):** Binary search property traversal in O(H).
3. **Deletion (`Delete`):**
   - **Case 1 (Leaf):** Disconnect parent's pointer and `delete target`.
   - **Case 2 (One Child):** Link target's parent directly to target's single child.
   - **Case 3 (Two Children):** Find maximum in left subtree (`maxNode(target->left)` - the in-order predecessor). Copy its value to `target`, then splice out and delete the predecessor node.

#### Complexity
- **Time Complexity:**
  - Search / Insert / Delete:
    - Average Case: O(log N)
    - Worst Case: O(N) (skewed tree)
  - Inorder Display: O(N)
- **Space Complexity:** O(H) recursion stack, where H is tree height (O(log N) balanced, O(N) skewed).

#### Test Cases
- **Test Case 1:**
  - **Input:** Number of nodes: `5`, values: `50 30 70 20 40`.
  - **Output:** `BST: 20 30 40 50 70 `
- **Test Case 2 (Search and Delete):**
  - **Input:** Search `30` -> `Value found`
  - **Input:** Delete `30` -> Display -> `BST: 20 40 50 70 `

---

### [AVL_Rotations.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/AVL_Rotations.cpp)

#### Description
Implements an AVL (Adelson-Velsky and Landis) Self-Balancing Binary Search Tree. Enforces the height balance invariant (|BF| <= 1) upon insertion using the 4 canonical rotations: Left-Left (LL / Right Rotate), Right-Right (RR / Left Rotate), Left-Right (LR), and Right-Left (RL).

#### Algorithm
1. Standard BST insertion.
2. Update `node->height = 1 + max(height(left), height(right))`.
3. Compute Balance Factor: BF = height(left) - height(right).
4. Balance Cases:
   - **LL (BF > 1 and key < left->key):** `rightRotate(node)`
   - **RR (BF < -1 and key > right->key):** `leftRotate(node)`
   - **LR (BF > 1 and key > left->key):** `leftRotate(node->left)`, then `rightRotate(node)`
   - **RL (BF < -1 and key < right->key):** `rightRotate(node->right)`, then `leftRotate(node)`

#### Complexity
- **Time Complexity:**
  - Insertion: O(log N) guaranteed in all cases.
  - Rotations: O(1) pointer manipulation.
  - Pre-order traversal: O(N).
- **Space Complexity:** O(log N) recursion stack.

#### Test Cases
- **Test Case 1:**
  - **Input:** Insert sequence `45, 4, 5, 8, 9`
  - **Output (Preorder):** `5 4 8 45 9 ` (or balanced preorder representation)

---

### [AVL_or_not.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/AVL_or_not.cpp)

#### Description
Validates whether an interactively created binary tree satisfies both AVL tree conditions:
1. It is a valid Binary Search Tree (BST) within (-infinity, +infinity) without duplicates.
2. Every node is height-balanced, meaning the height difference between left and right subtrees is at most 1.

#### Algorithm
1. `height(root)`: Returns 1 + max(height(left), height(right)) (0 for `nullptr`).
2. `isBST(root, minVal, maxVal)`: Validates that `root->data > minVal` and `root->data < maxVal`, recursively checking subtrees.
3. `isAVL(root)`: Checks |height(left) - height(right)| <= 1 and recurses on both children.
4. If both `isBST` and `isAVL` return `true`, tree is an AVL tree.

#### Complexity
- **Time Complexity:**
  - `isBST`: O(N)
  - `isAVL`: O(N^2) (re-calculates height at every node)
  - Overall: O(N^2)
- **Space Complexity:** O(H) call stack space where H is tree height.

#### Test Cases
- **Test Case 1 (Valid AVL):**
  - **Input:** Root `2`, Left `1` (no children), Right `3` (no children)
  - **Output:** `The tree is an AVL tree.`
- **Test Case 2 (Violates BST):**
  - **Input:** Root `2`, Left `3`, Right `1`
  - **Output:** `The tree is NOT an AVL tree.`

---

## 5. Heaps

### [maxHeapify.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/maxHeapify.cpp)

#### Description
Implements the core Max-Heapify routine (`algo`) on a 1-based array representation of a binary tree. Given an index i whose left and right subtrees are valid max-heaps, it floats a[i] down until the heap property is satisfied.

#### Algorithm
1. Set `left = 2 * i`, `right = 2 * i + 1`, `large = i`.
2. If `left <= n` and `a[left] > a[large]`, `large = left`.
3. If `right <= n` and `a[right] > a[large]`, `large = right`.
4. If `large != i`:
   - Swap `a[i]` and `a[large]`.
   - Recurse: `algo(a, large, n)`.

#### Complexity
- **Time Complexity:**
  - Worst Case: O(log N) along the height of the heap.
- **Space Complexity:** O(log N) call stack space.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    5
    4 10 3 5 1
    ```
  - **Output:**
    ```text
    Array after maxHeapify: 10 5 3 4 1 
    ```

---

### [maxHeapBT.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/maxHeapBT.cpp)

#### Description
Constructs a node-based Binary Tree level-by-level using an `std::queue`, then transforms it into a Max Heap directly on the pointer-linked tree structure using a post-order `Build_Heap` and recursive `heapify`.

#### Algorithm
1. `createTree(n)`: Builds a complete binary tree of n nodes using level-order input queue.
2. `heapify(root)`:
   - Compares `root->data` with `root->left->data` and `root->right->data`.
   - If a child has larger data, swaps data with `largest` child and recurses on `largest`.
3. `Build_Heap(root)`:
   - Recursively calls `Build_Heap(root->left)` and `Build_Heap(root->right)`.
   - Calls `heapify(root)`.
4. `display(root)`: Level-order traversal using BFS queue.

#### Complexity
- **Time Complexity:**
  - Construction & Display: O(N)
  - Building Heap: O(N)
- **Space Complexity:** O(N) for BFS queue and recursion call stack.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    - Number of nodes: `4`
    - Root: `10`
    - Left of 10: `20`, Right of 10: `30`
    - Left of 20: `40`
  - **Output:**
    ```text
    Before building max heap: 10 20 30 40 
    After building max heap: 40 20 30 10 
    ```

---

## 6. Algorithmic Problems

### [findDuplicate.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/findDuplicate.cpp)

#### Description
Finds the duplicate integer in an array of n + 1 integers where each integer is between 1 and n inclusive (LeetCode #287). Solves it in O(1) space without modifying the input array using Floyd's Tortoise and Hare (Cycle Detection) algorithm.

#### Algorithm
1. Interpret values as pointers where index i points to `nums[i]`.
2. **Phase 1 (Detect intersection in cycle):**
   - Initialize `slow = nums[0]`, `fast = nums[0]`.
   - Loop `slow = nums[slow]`, `fast = nums[nums[fast]]` until `slow == fast`.
3. **Phase 2 (Find cycle entrance):**
   - Reset `fast = nums[0]`.
   - Advance both pointers one step at a time: `slow = nums[slow]`, `fast = nums[fast]` until `slow == fast`.
4. Return `slow` (the duplicate value).

#### Complexity
- **Time Complexity:** O(N) linear time.
- **Space Complexity:** O(1) constant auxiliary memory.

#### Test Cases
- **Test Case 1:**
  - **Input:** `nums = {2, 5, 9, 6, 9, 3, 8, 9, 7, 1}`
  - **Output:** `9 `
- **Test Case 2:**
  - **Input:** `nums = {1, 3, 4, 2, 2}`
  - **Output:** `2`

---

### [kSmallestElements.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/kSmallestElements.cpp)

#### Description
Finds and extracts the k smallest elements in an unsorted array using the iterative Quickselect algorithm based on Lomuto/Hoare partition. Once the pivot index matches k-1, all elements to its left are guaranteed to be the k smallest.

#### Algorithm
1. **Partition (`Partition(arr, i, j)`):**
   - Choose `pivot = arr[i]`.
   - Advance `start` while `arr[start] <= pivot`, decrement `end` while `arr[end] > pivot`.
   - Swap `arr[start]` and `arr[end]` while `start < end`.
   - Swap `arr[i]` with `arr[end]`, returning `end`.
2. **Selectk (`Selectk(arr, low, high, k)`):**
   - While `low <= high`:
     - `pivotIndx = Partition(arr, low, high)`.
     - If `pivotIndx == k`, return.
     - If `k < pivotIndx`, search left: `high = pivotIndx - 1`.
     - If `k > pivotIndx`, search right: `low = pivotIndx + 1`.
3. Print `arr[0..k-1]`.

#### Complexity
- **Time Complexity:**
  - Best / Average Case: O(N)
  - Worst Case: O(N^2)
- **Space Complexity:** O(1) auxiliary space (iterative).

#### Test Cases
- **Test Case 1:**
  - **Input:** `arr = {3, 2, 10, 5, 4, 7, 8, 9, 1, 6, 15, 11}`, k = 8
  - **Output:**
    ```text
    8 smallest elements: 1 2 3 4 5 6 7 8 
    ```

---

### [moveZeroesToEnd.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/moveZeroesToEnd.cpp)

#### Description
Moves all zeroes in an integer vector to the end while maintaining the relative order of non-zero elements using an optimal two-pointer approach (LeetCode #283).

#### Algorithm
1. Find the first zero element and store its index in `j`. If no zeroes exist, return.
2. Iterate `i` from j + 1 to `nums.size() - 1`:
   - If `nums[i] != 0`:
     - Swap `nums[i]` and `nums[j]`.
     - Increment `j++`.

#### Complexity
- **Time Complexity:** O(N) single pass.
- **Space Complexity:** O(1) in-place.

#### Test Cases
- **Test Case 1:**
  - **Input:** `nums = {0, 1, 0, 3, 5}`
  - **Output:**
    ```text
    1/n3/n5/n0/n0/n
    ```
    *(Elements moved to `1, 3, 5, 0, 0`)*
- **Test Case 2:**
  - **Input:** `nums = {0, 0, 1}`
  - **Output:** `1, 0, 0`

---

### [summList.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/summList.cpp)

#### Description
Identifies and prints all array elements that can be represented as the sum of any two other distinct elements in the array (arr[i] = arr[j] + arr[k] where j != k != i). Uses sorting followed by the two-pointer technique.

#### Algorithm
1. Sort `arr` in ascending order: `sort(arr, arr + n)`.
2. For each element `arr[i]` from i = 0 to n - 1:
   - Skip duplicates: `if (i > 0 && arr[i] == arr[i - 1]) continue;`.
   - Set two pointers `left = 0`, `right = n - 1`.
   - While `left < right`:
     - If `left == i`, `left++`; if `right == i`, `right--`.
     - Compute `sum = arr[left] + arr[right]`.
     - If `sum == arr[i]`, print `arr[i]` and break.
     - Else if `sum < arr[i]`, increment `left++`.
     - Else decrement `right--`.

#### Complexity
- **Time Complexity:**
  - Sorting: O(N log N)
  - Two-pointer loop for each element: O(N * N) = O(N^2)
  - Total Time: O(N^2)
- **Space Complexity:** O(1) auxiliary space (ignoring sorting stack).

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    5
    1 2 3 4 5
    ```
  - **Output:**
    ```text
    345
    ```
    *(Since 1 + 2 = 3, 1 + 3 = 4, 1 + 4 = 5)*
- **Test Case 2:**
  - **Input:**
    ```text
    4
    10 20 30 40
    ```
  - **Output:**
    ```text
    3040
    ```

---

### [towerOfHanoi.cpp](file:///c:/Users/DELL/Downloads/DSA-submissions-main%20(1)/DSA-submissions-main/towerOfHanoi.cpp)

#### Description
Solves the classic Tower of Hanoi mathematical puzzle using recursion. Determines the minimal sequence of disk moves required to transfer n disks from source rod `F` to destination rod `T` using auxiliary rod `U` without placing a larger disk on top of a smaller one.

#### Algorithm
1. **Base Case:** If n == 1, move disk 1 directly from `F` to `T` and return.
2. **Step 1:** Recursively move n - 1 disks from `F` to `U` using `T` as auxiliary: `TOH(n - 1, F, T, U)`.
3. **Step 2:** Move disk n from `F` to `T`.
4. **Step 3:** Recursively move n - 1 disks from `U` to `T` using `F` as auxiliary: `TOH(n - 1, U, F, T)`.

#### Complexity
- **Time Complexity:** O(2^N) exponential time.
- **Space Complexity:** O(N) recursion call stack depth.

#### Test Cases
- **Test Case 1:**
  - **Input:**
    ```text
    Enter number of disks: 3
    ```
  - **Output:**
    ```text
    Move disk 1 from A to C
    Move disk 2 from A to B
    Move disk 1 from C to B
    Move disk 3 from A to C
    Move disk 1 from B to A
    Move disk 2 from B to C
    Move disk 1 from A to C
    ```
- **Test Case 2:**
  - **Input:** `1`
  - **Output:** `Move disk 1 from A to C`
