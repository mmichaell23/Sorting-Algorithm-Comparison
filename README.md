# Sorting-Algorithm-Comparison
Implemented in C++

![Image](https://github.com/user-attachments/assets/5a6751c8-72c3-437c-805a-289f9d8cee8e)

 # Bubble Sort
The space complexity of Bubble Sort is O(1). This means that the amount of extra space (memory) required by the algorithm remains constant regardless of the size of the input array being sorted. Bubble Sort only needs a constant amount of additional space to store temporary variables or indices during the sorting process. Therefore, the space complexity of Bubble Sort is considered to be very efficient as it does not depend on the input size and does not require additional space proportional to the input size.

 # Selection Sort
The Selection sort algorithm has a time complexity of O(n^2) and a space complexity of O(1) since it does not require any additional memory space apart from a temporary variable used for swapping.

 # Insertion Sort
The auxiliary space complexity of Insertion Sort is O(1), indicating it uses constant extra space regardless of the input size.

This is because the algorithm typically performs in-place sorting, meaning it rearranges the elements within the input array itself without requiring additional data structures or memory allocation proportional to the input size. Therefore, regardless of the size of the input array, the amount of extra space used by the Insertion Sort algorithm remains constant.

 # Quick Sort
The time complexity of Quick Sort is O(n log n) on average case, but can become O(n^2) in the worst-case. The space complexity of Quick Sort in the best case is O(log n), while in the worst-case scenario, it becomes O(n) due to unbalanced partitioning causing a skewed recursion tree that requires a call stack of size O(n).

 # Counting Sort
The average case time complexity for the counting sort algorithm is same as bucket sort. It runs in Θ(n) time.
 # Radix Sort
Radix sort also has a space complexity of O(n + b), where n is the number of elements and b is the base of the number system. This space complexity comes from the need to create buckets for each digit value and to copy the elements back to the original array after each digit has been sorted.
